/*******************************************************/
/*                     Cminus Parser                   */
/*                                                     */
/*******************************************************/

/*********************DEFINITIONS***********************/
%{
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <util/general.h>
#include <util/symtab.h>
#include <util/string_utils.h>

#define SYMTABLE_SIZE 100
#define SYMTAB_VALUE_FIELD     "value"

/*********************EXTERNAL DECLARATIONS***********************/

EXTERN(void,yyerror,(const char*));

EXTERN(int,yylex,(void));

char *fileName;
char *instrString;
char *stringString;
char *memString;
int stringCount = 0;
int memCount = 0;

char registers[14][10] = {"%rax", "%rbx", "%rcx", "%rdx", "%rdi", "%rsi", "%r8", "%r9", "%r10", "%r11", "%r12", "%r13", "%r14", "%r15"};

char inUse[14][6];

SymTable symtab;

extern int yylineno;

extern FILE *yyin;

static int getValue(char *name);
static void setValue(char *name, int value);
char* getRegister(char* c);
void setRegister(char* c);
void freeRegister(char*c); 
%}

%defines
   
%start Program

%token AND
%token ELSE
%token EXIT
%token FOR
%token IF 		
%token INTEGER 
%token NOT 		
%token OR 		
%token READ
%token WHILE
%token WRITE
%token LBRACE
%token RBRACE
%token LE
%token LT
%token GE
%token GT
%token EQ
i%token NE
%token ASSIGN
%token COMMA
%token SEMICOLON
%token LBRACKET
%token RBRACKET
%token LPAREN
%token RPAREN
%token PLUS
%token TIMES
%token IDENTIFIER
%token DIVIDE
%token RETURN
%token STRING	
%token INTCON
%token MINUS
%token INCLUDE
%token HEADERSTRING
%token ADDR
   
%left OR
i%left AND
%left NOT
%left LT LE GT GE NE EQ
%left PLUS MINUS
%left TIMES DIVDE

%union {
	char*	name;
	int     val;
}
%type <val> Expr SimpleExpr AddExpr MulExpr Factor Constant INTCON
%type <name> Variable STRING StringConstant IDENTIFIER

/***********************PRODUCTIONS****************************/
%%
Program		: Headers Programbody
                {
		  //printf("<Program> -> <Headers> <Programbody>\n");
		} 
                | Programbody
		{
		  //printf("<Program> -> <Programbody>\n");
		}
                ;

Headers         : Headers Header
                {
		  //printf("<Headers> -> <Headers> <Header>\n");
		} 

		| Header
		{
		  //printf("<Headers> -> <Header>\n");
		}
                ;

Header          : INCLUDE HEADERSTRING
                {
		  //printf("<Header> -> <INCLUDE> <HEADERSTRING>\n");
		}
                ;

Programbody		: Procedures 
		{
		  //printf("<Program> -> <Procedures>\n");
		}
	  	| DeclList Procedures
		{
		  //printf("<Program> -> <DeclList> <Procedures>\n");
		}
                ;

Procedures 	: ProcedureDecl Procedures
		{
		  //printf("<Procedures> -> <ProcedureDecl> <Procedures>\n");
		}
	   	|
		{
		  //printf("<Procedures> -> epsilon\n");
		}
	   	;

ProcedureDecl : ProcedureHead ProcedureBody
		{
		  //printf("<ProcedureDecl> -> <ProcedureHead> <ProcedureBody>\n");
		}
              ;

ProcedureHead : FunctionDecl DeclList 
		{
		  //printf("<ProcedureHead> -> <FunctionDecl> <DeclList>\n");
		}
	      | FunctionDecl
		{
		  //printf("<ProcedureHead> -> <FunctionDecl>\n");
		}
              ;

FunctionDecl :  Type IDENTIFIER LPAREN RPAREN LBRACE 
		{
			//printf("<FunctionDecl> ->  <Type> <IDENTIFIER> <LP> <RP> <LBR>\n"); 
		}
	      	;

ProcedureBody : StatementList RBRACE
		{
		  //printf("<ProcedureBody> -> <StatementList> <RBR>\n");
		}
	      ;


DeclList 	: Type IdentifierList  SEMICOLON 
		{
		  //printf("<DeclList> -> <Type> <IdentifierList> <SC>\n");
		}		
	   	| DeclList Type IdentifierList SEMICOLON
	 	{
		  //printf("<DeclList> -> <DeclList> <Type> <IdentifierList> <SC>\n");
	 	}
          	;


IdentifierList 	: VarDecl  
		{
		  //printf("<IdentifierList> -> <VarDecl>\n");
		}
						
                | IdentifierList COMMA VarDecl
		{
		  //printf("<IdentifierList> -> <IdentifierList> <CM> <VarDecl>\n");
		}
                ;

VarDecl 	: IDENTIFIER
		{ 
		  //printf("<VarDecl> -> <IDENTIFIER\n");
		}
		| IDENTIFIER LBRACKET INTCON RBRACKET
                {
		  //printf("<VarDecl> -> <IDENTIFIER> <LBK> <INTCON> <RBK>\n");
		}
		;

Type     	: INTEGER 
		{ 
		  //printf("<Type> -> <INTEGER>\n");
		}
                ;

Statement 	: Assignment
		{ 
		  //printf("<Statement> -> <Assignment>\n");
		}
                | IfStatement
		{ 
		  //printf("<Statement> -> <IfStatement>\n");
		}
		| WhileStatement
		{ 
		  //printf("<Statement> -> <WhileStatement>\n");
		}
                | IOStatement 
		{ 
		  //printf("<Statement> -> <IOStatement>\n");
		}
		| ReturnStatement
		{ 
		  //printf("<Statement> -> <ReturnStatement>\n");
		}
		| ExitStatement	
		{ 
		  //printf("<Statement> -> <ExitStatement>\n");
		}
		| CompoundStatement
		{ 
		  //printf("<Statement> -> <CompoundStatement>\n");
		}
                ;

Assignment      : Variable ASSIGN Expr SEMICOLON
		{ 
		  setRegister($1);
		  //memCount += 4;
		  
		 // char buf[10] = getRegister($1);
		  //strcat(instrString, 

		  setValue($1, $3);
		  //printf("<Assignment> -> <Variable> <ASSIGN> <Expr> <SC>\n");
		}
                ;
				
IfStatement	: IF TestAndThen ELSE CompoundStatement
		{
			//printf("<IfStatement> -> <IF> <TestAndThen> <ELSE> <CompoundStatement>\n");
		}
		| IF TestAndThen
		{
		  //printf("<IfStatement> -> <IF> <TestAndThen>\n");
		}
		;
		
				
TestAndThen	: Test CompoundStatement
		{
		  //printf("<TestAndThen> -> <Test> <CompoundStatement>\n");
		}
		;
				
Test		: LPAREN Expr RPAREN
		{
		  //printf("<Test> -> <LP> <Expr> <RP>\n");
		}
		;
	

WhileStatement  : WhileToken WhileExpr Statement
		{
		  //printf("<WhileStatement> -> <WhileToken> <WhileExpr> <Statement>\n");
		}
                ;
                
WhileExpr	: LPAREN Expr RPAREN
		{
		  //printf("<WhileExpr> -> <LP> <Expr> <RP>\n");
		}
		;
				
WhileToken	: WHILE
		{
		  //printf("<WhileToken> -> <WHILE>\n");
		}
		;

IOStatement     : READ LPAREN STRING COMMA ADDR Variable RPAREN SEMICOLON
		{

		  
		   //Creates the data for the string and names it
                  char *s = (char*)malloc(50*sizeof(char));
                  strcat(s, "\n.string_const");
                  char buf[10];
                  sprintf(buf, "%d", stringCount);
                  stringCount++;
                  strcat(s, buf);
                  strcat(s, ": .string ");
                  strcat(s, $3);

                  strcat(stringString, s);

                  //Assembly instruction for scanf

                  char *instr = (char*)malloc(50*sizeof(char));
                  strcat(instr, "\nleaq ");
                  strcat(instr, substr(s, 1, 14)); //Gets the string name from s
                  strcat(instr, "(%rip), %rdi\nmovq ");
		  
		  
		  int n;
		  scanf($3, &n);
		  setValue($6, n);
		  setRegister($6);

		  strcpy(buf, getRegister($6));
		  strcat(instr, buf);
		  strcat(instr,", %rsi\nmovl $0, %eax\ncall scanf@PLT"); 
		  strcat(instrString, instr);

		 // printf("The variable is %c\n", $6[0]);
		 // printf("The register associated with %s is %s\n", $6, getRegister($6));


		  
		 
		  /*	
		  int t;
		      
		  scanf($3, &t);
		  setValue($6, t); */
		  //printf("<IOStatement> -> <READ> <LP> <STRING> <COMMA> <ADDR> <Variable> <RP> <SC>\n");
		}
                | WRITE LPAREN STRING COMMA Expr RPAREN SEMICOLON
		{
		
		
		   //Creates the data for the string and names it
                  char *s = (char*)malloc(50*sizeof(char));
                  strcat(s, "\n.string_const");
                  char buf[10];
                  sprintf(buf, "%d", stringCount);
                  stringCount++;
                  strcat(s, buf);
                  strcat(s, ": .string ");
                  strcat(s, $3);

                  strcat(stringString, s);

                  //Assembly instruction for printf
		  char *instr = (char*)malloc(50*sizeof(char));
                  strcat(instr, "\nleaq ");
                  strcat(instr, substr(s, 1, 14));
		  strcat(instr, "(%rip), %rdi\nmovl $");
		  sprintf(buf, "%d", $5);
		  strcat(instr, buf);
		  strcat(instr, ", %esi\nmovl $0, %eax\ncall printf@PLT");
		  strcat(instrString, instr);
 

		
			
		
		  /* char *fmt = replaceNewline($3);
		  printf(fmt, $5);
		  free(fmt);
		  free($3);*/
		  //printf("<IOStatement> -> <WRITE> <LP> <STRING> <COMMA> <Expr> <RP> <SC>\n");
		
		}
                | WRITE LPAREN StringConstant RPAREN SEMICOLON         
		{

		  //Creates data for string
		  char *s = (char*)malloc(50*sizeof(char));
		  strcat(s, "\n.string_const");
		  char buf[10];
		  sprintf(buf, "%d", stringCount);
		  stringCount++;
		  strcat(s, buf);
		  strcat(s, ": .string ");
		  strcat(s, $3);

		  strcat(stringString, s);


		  //Instruciton part of printf

		  char *instr = (char*)malloc(50*sizeof(char));
		  strcat(instr, "\nleaq ");
		  strcat(instr, substr(s, 1, 14));
		  strcat(instr, "(%rip), %rdi\nmovl $0, %eax\ncall printf@PLT");
		  strcat(instrString, instr);

		  /*
		  char * s = $3;
		  char *fmt = replaceNewline(s);
		  printf(fmt);
		  free(fmt);
		  free($3);*/
		  //printf("<IOStatement> -> <WRITE> <LP> <StringConstant> <RP> <SC>\n");

		}
                ;

ReturnStatement : RETURN Expr SEMICOLON
		{
		  //printf("<ReturnStatement> -> <RETURN> <Expr> <SC>\n");
		}
                ;

ExitStatement 	: EXIT SEMICOLON
		{
		  //printf("<ExitStatement> -> <EXIT> <SC>\n");
		}
		;

CompoundStatement : LBRACE StatementList RBRACE
		{
		  //printf("<CompoundStatement> -> <LBR> <StatementList> <RBR>\n");
		}
                ;

StatementList   : Statement
		{		
		  //printf("<StatementList> -> <Statement>\n");
		}
                | StatementList Statement
		{		
		  //printf("<StatementList> -> <StatementList> <Statement>\n");
		}
                ;

Expr            : SimpleExpr
		{
		  $$ = $1;
		  //printf("<Expr> -> <SimpleExpr>\n");
		}
                | Expr OR SimpleExpr 
		{ 

		   //Checks that both values have an address assigned to them
                  char buf1[4];
                  if (sizeof($1) == sizeof(int)){
                        sprintf(buf1, "%d", $1);
                        setRegister(buf1);
                  }else {
                        strcpy(buf1, $1);
                  }

                  char buf2[4];
                  if (sizeof($3) == sizeof(int)){
                        sprintf(buf2, "%d", $3);
                        setRegister(buf2);
                  }else {
                        strcpy(buf2, $3);
                  }

                  //Creates the instructions for OR
                  strcat(instrString, "\norq ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));

		  $$ = ($1 || $3);
		  //printf("<Expr> -> <Expr> <OR> <SimpleExpr> \n");
		}
                | Expr AND SimpleExpr 
		{

		  //Checks that both values have an address assigned to them
                  char buf1[4];
                  if (sizeof($1) == sizeof(int)){
                        sprintf(buf1, "%d", $1);
                        setRegister(buf1);
                  }else {
                        strcpy(buf1, $1);
                  }

                  char buf2[4];
                  if (sizeof($3) == sizeof(int)){
                        sprintf(buf2, "%d", $3);
                        setRegister(buf2);
                  }else {
                        strcpy(buf2, $3);
                  }

                  //Creates the instructions for AND
                  strcat(instrString, "\nandq ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));

		  $$ = ($1 && $3);
		  //printf("<Expr> -> <Expr> <AND> <SimpleExpr> \n");
		}
                | NOT SimpleExpr 
		{

		   //Checks that both values have an address assigned to them
                  char buf1[4];
                  if (sizeof($2) == sizeof(int)){
                        sprintf(buf1, "%d", $2);
                        setRegister(buf1);
                  }else {
                        strcpy(buf1, $2);
                  }

                  //Creates the instructions for NOT
                  strcat(instrString, "\nnotq ");
                  strcat(instrString, getRegister(buf1));

		  $$ = (!$2);
		  //printf("<Expr> -> <NOT> <SimpleExpr> \n");
		}
                ;

SimpleExpr	: AddExpr
		{
		  $$ = $1;
		  //printf("<SimpleExpr> -> <AddExpr>\n");
		}
                | SimpleExpr EQ AddExpr
		{
		
		  //Checks that both values have an address assigned to them
                  char buf1[4];
                  if (sizeof($1) == sizeof(int)){
                        sprintf(buf1, "%d", $1);
                        setRegister(buf1);
                  }else {
                        strcpy(buf1, $1);
                  }

                  char buf2[4];
                  if (sizeof($3) == sizeof(int)){
                        sprintf(buf2, "%d", $3);
                        setRegister(buf2);
                  }else {
                        strcpy(buf2, $3);
                  }

                  //Creates the instructions for comparing
                  strcat(instrString, "\ncmpq ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));
		
		  strcat(instrString, "\ncmove ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));

  
		  $$ = ($1 == $3);
		  //printf("<SimpleExpr> -> <SimpleExpr> <EQ> <AddExpr> \n");
		}
                | SimpleExpr NE AddExpr
		{


		  //Checks that both values have an address assigned to them
                  char buf1[4];
                  if (sizeof($1) == sizeof(int)){
                        sprintf(buf1, "%d", $1);
                        setRegister(buf1);
                  }else {
                        strcpy(buf1, $1);
                  }

                  char buf2[4];
                  if (sizeof($3) == sizeof(int)){
                        sprintf(buf2, "%d", $3);
                        setRegister(buf2);
                  }else {
                        strcpy(buf2, $3);
                  }

                  //Creates the instructions for comparing
                  strcat(instrString, "\ncmpq ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));

                  strcat(instrString, "\ncmovne ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));

		  $$ = ($1 != $3);
		  //printf("<SimpleExpr> -> <SimpleExpr> <NE> <AddExpr> \n");
		}
                | SimpleExpr LE AddExpr
		{

		  //Checks that both values have an address assigned to them
                  char buf1[4];
                  if (sizeof($1) == sizeof(int)){
                        sprintf(buf1, "%d", $1);
                        setRegister(buf1);
                  }else {
                        strcpy(buf1, $1);
                  }

                  char buf2[4];
                  if (sizeof($3) == sizeof(int)){
                        sprintf(buf2, "%d", $3);
                        setRegister(buf2);
                  }else {
                        strcpy(buf2, $3);
                  }

                  //Creates the instructions for comparing
                  strcat(instrString, "\ncmpq ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));

                  strcat(instrString, "\ncmovne ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));

		  $$ = ($1 <= $3);
		  //printf("<SimpleExpr> -> <SimpleExpr> <LE> <AddExpr> \n");
		}
                | SimpleExpr LT AddExpr
		{

		   //Checks that both values have an address assigned to them
                  char buf1[4];
                  if (sizeof($1) == sizeof(int)){
                        sprintf(buf1, "%d", $1);
                        setRegister(buf1);
                  }else {
                        strcpy(buf1, $1);
                  }

                  char buf2[4];
                  if (sizeof($3) == sizeof(int)){
                        sprintf(buf2, "%d", $3);
                        setRegister(buf2);
                  }else {
                        strcpy(buf2, $3);
                  }

                  //Creates the instructions for comparing
                  strcat(instrString, "\ncmpq ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));

          	  strcat(instrString, "\ncmove ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));


                  strcat(instrString, "\ncmovne ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));

		  $$ = ($1 < $3);
		  //printf("<SimpleExpr> -> <SimpleExpr> <LT> <AddExpr> \n");
		}
                | SimpleExpr GE AddExpr
		{

		  //Checks that both values have an address assigned to them
                  char buf1[4];
                  if (sizeof($1) == sizeof(int)){
                        sprintf(buf1, "%d", $1);
                        setRegister(buf1);
                  }else {
                        strcpy(buf1, $1);
                  }

                  char buf2[4];
                  if (sizeof($3) == sizeof(int)){
                        sprintf(buf2, "%d", $3);
                        setRegister(buf2);
                  }else {
                        strcpy(buf2, $3);
                  }

                  //Creates the instructions for comparing
                  strcat(instrString, "\ncmpq ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));

                  strcat(instrString, "\ncmove ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));

		  strcat(instrString, "\ncmovg ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));


		  $$ = ($1 >= $3);
		  //printf("<SimpleExpr> -> <SimpleExpr> <GE> <AddExpr> \n");
		}
                | SimpleExpr GT AddExpr
		{

		  
		  //Checks that both values have an address assigned to them
                  char buf1[4];
                  if (sizeof($1) == sizeof(int)){
                        sprintf(buf1, "%d", $1);
                        setRegister(buf1);
                  }else {
                        strcpy(buf1, $1);
                  }

                  char buf2[4];
                  if (sizeof($3) == sizeof(int)){
                        sprintf(buf2, "%d", $3);
                        setRegister(buf2);
                  }else {
                        strcpy(buf2, $3);
                  }

                  //Creates the instructions for comparing
                  strcat(instrString, "\ncmpq ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));

                  strcat(instrString, "\ncmovg ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));

		  //printf("<SimpleExpr> -> <SimpleExpr> <GT> <AddExpr> \n");
		  $$ = ($1 > $3);
		}
                ;

AddExpr		:  MulExpr            
		{
		  $$ = $1;
		  //printf("<AddExpr> -> <MulExpr>\n");
		}
                |  AddExpr PLUS MulExpr
		{

		  //Checks that both values have an address assigned to them
		  char buf1[4];
		  if (sizeof($1) == sizeof(int)){
			sprintf(buf1, "%d", $1); 
			setRegister(buf1);
		  }else {
			strcpy(buf1, $1);
		  }

		  char buf2[4];
                  if (sizeof($3) == sizeof(int)){
                        sprintf(buf2, "%d", $3);
			setRegister(buf2);
                  }else {
                        strcpy(buf2, $3);
                  }

		  //Creates the instructions for adding
		  strcat(instrString, "\naddq ");
		  strcat(instrString, getRegister(buf1));
		  strcat(instrString, ", ");
		  strcat(instrString, getRegister(buf2));
		  $$ = $1 + $3;
		  //printf("<AddExpr> -> <AddExpr> <PLUS> <MulExpr> \n");
		}
                |  AddExpr MINUS MulExpr
		{

		  //Checks that both values have an address assigned to them
                  char buf1[4];
                  if (sizeof($1) == sizeof(int)){
                        sprintf(buf1, "%d", $1);
                        setRegister(buf1);
                  }else {
                        strcpy(buf1, $1);
                  }

                  char buf2[4];
                  if (sizeof($3) == sizeof(int)){
                        sprintf(buf2, "%d", $3);
                        setRegister(buf2);
                  }else {
                        strcpy(buf2, $3);
                  }

                  //Creates the instructions for subtracting
                  strcat(instrString, "\nsubq ");
                  strcat(instrString, getRegister(buf2));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf1));

		  $$ = $1 - $3;
		  //printf("<AddExpr> -> <AddExpr> <MINUS> <MulExpr> \n");
		}
                ;

MulExpr		:  Factor
		{
		  $$ = $1;
		  //printf("<MulExpr> -> <Factor>\n");
		}
                |  MulExpr TIMES Factor
		{

		   //Checks that both values have an address assigned to them
                  char buf1[4];
                  if (sizeof($1) == sizeof(int)){
                        sprintf(buf1, "%d", $1);
                        setRegister(buf1);
                  }else {
                        strcpy(buf1, $1);
                  }

                  char buf2[4];
                  if (sizeof($3) == sizeof(int)){
                        sprintf(buf2, "%d", $3);
                        setRegister(buf2);
                  }else {
                        strcpy(buf2, $3);
                  }

                  //Creates the instructions for mul
                  strcat(instrString, "\nimulq ");
                  strcat(instrString, getRegister(buf1));
                  strcat(instrString, ", ");
                  strcat(instrString, getRegister(buf2));
 
		  $$ = $1 * $3;
		  //printf("<MulExpr> -> <MulExpr> <TIMES> <Factor> \n");
		}
                |  MulExpr DIVIDE Factor
		{
		
		   //Checks that both values have an address assigned to them
                  char buf1[4];
                  if (sizeof($1) == sizeof(int)){
                        sprintf(buf1, "%d", $1);
                        setRegister(buf1);
                  }else {
                        strcpy(buf1, $1);
                  }

                  char buf2[4];
                  if (sizeof($3) == sizeof(int)){
                        sprintf(buf2, "%d", $3);
                        setRegister(buf2);
                  }else {
                        strcpy(buf2, $3);
                  }

                  //Creates the instructions for div
		  
		  /*
		  strcat(instrString, "\nmovl (");
		  strcat(instrString, getRegister(buf2));
		  strcat(instrString, "), %eax\nmovl (");
		  strcat(instrString, getRegister(buf1));
		  strcat(instrString, "), %edx");
                  strcat(instrString, "\nidivl ");
                  strcat(instrString, "%edx");*/

		  $$ = $1 / $3;
		  //printf("<MulExpr> -> <MulExpr> <DIVIDE> <Factor> \n");
		}		
                ;
				
Factor          : Variable
		{ 
		  $$ = getValue($1);
		  //printf("<Factor> -> <Variable>\n");
		}
                | Constant
		{ 
		  $$ = $1;
		  //printf("<Factor> -> <Constant>\n");
		}
                | IDENTIFIER LPAREN RPAREN
       		{	
		  //printf("<Factor> -> <IDENTIFIER> <LP> <RP>\n");
		}
         	| LPAREN Expr RPAREN
		{
		  $$ = $2;
		  //printf("<Factor> -> <LP> <Expr> <RP>\n");
		}
                ;  

Variable        : IDENTIFIER
		{
		  $$ = $1;
		  //printf("<Variable> -> <IDENTIFIER>\n");
		}
                | IDENTIFIER LBRACKET Expr RBRACKET    
               	{
		  //printf("<Variable> -> <IDENTIFIER> <LBK> <Expr> <RBK>\n");
               	}
                ;			       

StringConstant 	: STRING
		{ 
		  $$ = $1;
		  //printf("<StringConstant> -> <STRING>\n");
		}
                ;

Constant        : INTCON
		{ 
		  $$ = $1;
		  //printf("<Constant> -> <INTCON>\n");
		}
                ;

%%


/********************C ROUTINES *********************************/

void yyerror(const char *s)
{
  fprintf(stderr,"%s: line %d: %s\n",fileName,yylineno,s);
}

int yywrap() {
	return 1;
}

void setRegister(char* c){

	for(int i = 0; i < 14; i++){
		
		if(strcmp(inUse[i], c) == 0){
			return;
		}


		if(strcmp(inUse[i], "0") == 0){
	
			strcpy(inUse[i], c);
		//	printf("Assigning %s to address %s\n", c, registers[i] );
			break;	

		}

	}

}


char* getRegister(char* c){

	char buf[5];
	strcpy(buf, c);

	for(int i = 0; i < 14; i++){

		if(strcmp(inUse[i], c) == 0){

		//	printf("Found! %s is assigned to %s\n", c, registers[i]);
			return registers[i];

		}/*else{

			setRegister(buf);
			return getRegister(buf);		

		}*/

	}

}


void freeRegister(char* c){

	for(int i = 0; i < 14; i++){

		if(strcmp(inUse[i], c) == 0){
		
			strcpy(inUse[i], "0");
			break;
		
		}

	}

}


static void initialize(char* inputFileName) {
	yyin = fopen(inputFileName,"r");
        if (yyin == NULL) {
          fprintf(stderr,"Error: Could not open file %s\n",inputFileName);
          exit(-1);
        }
	
        //  uncomment this section for Project 2
	char* dotChar = rindex(inputFileName,'.');
	int endIndex = strlen(inputFileName) - strlen(dotChar);
	
	char *outputFileName = nssave(2,substr(inputFileName,0,endIndex),".s");
	stdout = freopen(outputFileName,"w",stdout);
        if (stdout == NULL) {
          fprintf(stderr,"Error: Could not open file %s\n",outputFileName);
          exit(-1);
	} 
        
	//printf(".section .rodata\n.text\n.global main\n.type main,@function\nmain: nop\npushq %rbp\nmovq %rsp, %rbp\n");	

	symtab = SymInit(SYMTABLE_SIZE);
	SymInitField(symtab,SYMTAB_VALUE_FIELD,(Generic)-1,NULL);
}

static void finalize() {
    SymKillField(symtab,SYMTAB_VALUE_FIELD);
    SymKill(symtab);
    fclose(yyin);
    fclose(stdout);  //uncomment this line for Project 2
}

int main(int argc, char** argv)

{	
	fileName = argv[1];
	initialize(fileName);
	
	instrString = (char*)malloc(1000*sizeof(char));
	stringString = (char*)malloc(1000*sizeof(char));
	memString = (char*)malloc(1000*sizeof(char));

	for(int i = 0; i < 14; i++){

		strcpy(inUse[i], "0");		

	}


	
        yyparse();

	//Prints the data section
	printf(".section .rodata\n%s%s\n.text\n.global main\n.type main,@function\nmain: nop\npushq %rbp\nmovq %rsp, %rbp%s\nleave\nret\n", memString, stringString, instrString);
  
  	finalize();
  
	free(instrString);
	free(stringString);
	free(memString);

  	return 0;
}

/**
 *
 * retrieve the value of a key
 *
 :* @param name a C character string which is a key
 * @return the value of the key
 */
static int getValue(char *name)
{
  return (int)SymGetField(symtab, name, SYMTAB_VALUE_FIELD); 
}

/**
 *
 * retrieve the value of a key
 *
 * @param name a C character string which is a key
 * @param value the value of the key
 */
static void setValue(char *name, int value)
{
  SymPutField(symtab, name, SYMTAB_VALUE_FIELD, (Generic)value); 
}
/******************END OF C ROUTINES**********************/
