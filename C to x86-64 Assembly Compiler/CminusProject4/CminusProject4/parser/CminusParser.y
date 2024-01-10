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
#include <util/dlink.h>
#include <util/string_utils.h>
#include <codegen/symfields.h>
#include <codegen/codegen.h>
#include <codegen/reg.h>
#include <util/symtab_stack.h>

#define SYMTABLE_SIZE 100

/*********************EXTERNAL DECLARATIONS***********************/

EXTERN(void,yyerror,(const char*));

EXTERN(int,yylex,(void));

char *fileName;

SymTable symtab;
SymTable localSymtab;
SymtabStack stack;

static DList instList;
static DList dataList;

char *fileName;

int globalOffset = 0;

extern union YYSTYPE yylval;

extern int yylineno;
 
extern FILE *yyin;
%}

%defines

%start Program

%token AND
%token ELSE
%token EXIT
%token FLOAT
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
%token NE
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
%left AND
%left NOT
%left LT LE GT GE NE EQ
%left PLUS MINUS
%left TIMES DIVDE

%union {
	char*	name;        
	int     regIndex;
        int     symIndex;
}

%type <regIndex> Expr SimpleExpr AddExpr
%type <regIndex> MulExpr Factor Variable  Constant
%type <symIndex> TestAndThen Test WhileExpr WhileToken
%type <name> IDENTIFIER STRING INTCON StringConstant FunctionDecl

/***********************PRODUCTIONS****************************/
%%
Program		: Headers Programbody 
                | Programbody
                ;

Headers         : Headers Header
		| Header
                ;

Header          : INCLUDE HEADERSTRING 

Programbody	: Procedures
		{
			emitDataPrologue(dataList);
			emitInstructions(instList);
		}
	  	| DeclList Procedures
		{
			emitDataPrologue(dataList);
			emitInstructions(instList);
		}
                ;

Procedures 	: ProcedureDecl Procedures
	   	|
	   	;

ProcedureDecl : ProcedureHead ProcedureBody
               {
			emitExit(instList);
               }
	      ;

ProcedureHead : FunctionDecl DeclList 
		{
		  emitProcedurePrologue(instList, $1);
		}
	      | FunctionDecl
		{
		  emitProcedurePrologue(instList, $1);
		}
              ;

FunctionDecl :  Type IDENTIFIER LPAREN RPAREN LBRACE 
	        {
		
		   if(strcmp($2, "main") != 0){

			localSymtab = beginScope(stack); //Begins new local table on function creation.
			SymInitField(localSymtab,SYMTAB_OFFSET_FIELD,(Generic)-1,NULL);
                   	SymInitField(localSymtab,SYMTAB_TYPE_INDEX_FIELD,(Generic)-1,NULL);


			}

                   $$ = $2;
                }
	      	;

ProcedureBody : StatementList RBRACE
	      ;


DeclList 	: Type IdentifierList  SEMICOLON 
	   	| DeclList Type IdentifierList SEMICOLON
          	;


IdentifierList 	: VarDecl  
                | IdentifierList COMMA VarDecl
                ;

VarDecl 	: IDENTIFIER
		{
		   addIdToSymtab(currentSymtab(stack), $1);
		}
		| IDENTIFIER LBRACKET INTCON RBRACKET
		{
		  addArrayIdToSymtab(currentSymtab(stack), $1, atoi($3), 1);
		}  
		| IDENTIFIER LBRACKET INTCON RBRACKET LBRACKET INTCON RBRACKET
                {
	          addArrayIdToSymtab(currentSymtab(stack), $1, atoi($3), atoi($6));
		}
		| IDENTIFIER LPAREN RPAREN
		{
		  addIdToSymtab(currentSymtab(stack), $1);

		}
		;

Type     	: INTEGER 
                ;

Statement 	: Assignment
                | IfStatement
		| WhileStatement
                | IOStatement 
		| ReturnStatement
		| ExitStatement	
		| CompoundStatement
                ;

Assignment      : Variable ASSIGN Expr SEMICOLON
		{
			emitAssignment(instList,$1,$3);
		}
                ;

				
IfStatement	: IF TestAndThen ELSE CompoundStatement
		{
			emitEndBranchTarget(instList,currentSymtab(stack),$2);
		}
		| IF TestAndThen
		{
			emitEndBranchTarget(instList,currentSymtab(stack),$2);
		}
		;
		
				
TestAndThen	: Test CompoundStatement
		{
		   	$$ = emitThenBranch(instList,currentSymtab(stack),$1);
		}
		;
				
Test		: LPAREN Expr RPAREN
		{
			$$ = emitIfTest(instList,currentSymtab(stack),$2);
		}
		;
	

WhileStatement  : WhileToken WhileExpr Statement
		{
			emitWhileLoopBackBranch(instList,currentSymtab(stack),$1,$2);
		}
                ;
                
WhileExpr	: LPAREN Expr RPAREN
		{
			$$ = emitWhileLoopTest(instList,currentSymtab(stack),$2);
		}
		;
				
WhileToken	: WHILE
		{
			$$ = emitWhileLoopLandingPad(instList,currentSymtab(stack));
		}
		;

IOStatement     : READ LPAREN STRING COMMA ADDR Variable RPAREN SEMICOLON
		{
		  emitReadVariable(instList, dataList, $3, lastSymtab(stack), $6);
		}
                | WRITE LPAREN STRING COMMA Expr RPAREN SEMICOLON
		{
		  emitWriteExpression(instList, dataList, $3, lastSymtab(stack), $5);
		}
                | WRITE LPAREN StringConstant RPAREN SEMICOLON         
		{
		  emitWriteString(instList, dataList, lastSymtab(stack), $3);
		}
                ;


ReturnStatement : RETURN Expr SEMICOLON
		{
			emitReturn(instList, $2);
			SymTable localSymtab = endScope(stack); //Ends the local SymTable after exiting the function
			SymKillField(localSymtab,SYMTAB_OFFSET_FIELD);
    			SymKillField(localSymtab,SYMTAB_TYPE_INDEX_FIELD);
	    		SymKill(localSymtab);


		}
                ;

ExitStatement 	: EXIT SEMICOLON
		;

CompoundStatement : LBRACE StatementList RBRACE
                ;

StatementList   : Statement
		
                | StatementList Statement
		
                ;

Expr            : SimpleExpr
		{
			$$ = $1; 
		}
                | Expr OR SimpleExpr 
		{
			$$ = emitOrExpression(instList,$1,$3);
		}
                | Expr AND SimpleExpr 
		{
			$$ = emitAndExpression(instList,$1,$3);
		}
                | NOT SimpleExpr 
		{
			$$ = emitNotExpression(instList,$2);
		}
                ;

SimpleExpr	: AddExpr
		{
			$$ = $1; 
		}
                | SimpleExpr EQ AddExpr
		{
			$$ = emitEqualExpression(instList,$1,$3);
		}
                | SimpleExpr NE AddExpr
		{
			$$ = emitNotEqualExpression(instList,$1,$3);
		}
                | SimpleExpr LE AddExpr
		{
			$$ = emitLessEqualExpression(instList,$1,$3);
		}
                | SimpleExpr LT AddExpr
		{
			$$ = emitLessThanExpression(instList,$1,$3);
		}
                | SimpleExpr GE AddExpr
		{
			$$ = emitGreaterEqualExpression(instList,$1,$3);
		}
                | SimpleExpr GT AddExpr
		{
			$$ = emitGreaterThanExpression(instList,$1,$3);
		}
                ;

AddExpr		:  MulExpr            
		{
			$$ = $1; 
		}
                |  AddExpr PLUS MulExpr
		{
			$$ = emitAddExpression(instList,$1,$3);
		}
                |  AddExpr MINUS MulExpr
		{
			$$ = emitSubtractExpression(instList,$1,$3);
		}
                ;

MulExpr		:  Factor
		{
			$$ = $1; 
		}
                |  MulExpr TIMES Factor
		{
			$$ = emitMultiplyExpression(instList,$1,$3);
		}
                |  MulExpr DIVIDE Factor
		{
			$$ = emitDivideExpression(instList,$1,$3);
		}		
                ;
				
Factor          : Variable
		{ 
			$$ = emitLoadVariable(instList,$1);
		}
                | Constant
		{ 
			$$ = $1;
		}
                | IDENTIFIER LPAREN RPAREN
		{
			//Starts everything needed for function call
			$$ = emitFuncCall(instList, $1, stack);			
				
		        
		}
         	| LPAREN Expr RPAREN
		{
			$$ = $2;
		}
                ;  

Variable        : IDENTIFIER
		{

			
			SymTable found = findSymtab(stack, $1); //Finds SymTable which contains the variable
			int symIndex = SymQueryIndex(found,$1);
			$$ = emitComputeVariableAddress(instList,found,symIndex);
		}
                | IDENTIFIER LBRACKET Expr RBRACKET    
               	{
			SymTable found = findSymtab(stack, $1);

			int symIndex = SymQueryIndex(found,$1);
               		$$ = emitComputeArrayAddress(instList,found,symIndex,$3);
               	}
                | IDENTIFIER LBRACKET Expr RBRACKET LBRACKET Expr RBRACKET     
               	{
			SymTable found = findSymtab(stack, $1);

			int symIndex = SymQueryIndex(found,$1);
               		$$ = emitCompute2DArrayAddress(instList,found,symIndex,$3, $6);
               	}
                ;
			       

StringConstant 	: STRING
		{ 
		        $$ = $1;
		}
                ;

Constant        :  INTCON
		{ 
			$$ = emitLoadIntegerConstant(instList, $1); 
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

static void initSymTable(SymTable symtab) {

	symtab = SymInit(SYMTABLE_SIZE); 
	//symtab = beginScope(stack);

	SymInitField(symtab,SYMTAB_OFFSET_FIELD,(Generic)-1,NULL);
	SymInitField(symtab,SYMTAB_TYPE_INDEX_FIELD,(Generic)-1,NULL);
}

static void deleteSymTable() {
    SymKillField(symtab,SYMTAB_OFFSET_FIELD);
    SymKillField(symtab,SYMTAB_TYPE_INDEX_FIELD);
    SymKill(symtab);

}

static void initialize(char* inputFileName) {

	yyin = freopen(inputFileName,"r", stdin);
        if (yyin == NULL) {
          fprintf(stderr,"Error: Could not open file %s\n",inputFileName);
          exit(-1);
        }

	char* dotChar = rindex(inputFileName,'.');
	int endIndex = strlen(inputFileName) - strlen(dotChar);
	char *outputFileName = nssave(2,substr(inputFileName,0,endIndex),".s");
	stdout = freopen(outputFileName,"w", stdout);
        if (stdout == NULL) {
          fprintf(stderr,"Error: Could not open file %s\n",outputFileName);
          exit(-1);
       }
		
	stack = symtabStackInit(); 
	symtab = beginScope(stack);

	initSymTable(symtab);
	
	initRegisters();
	
	instList = dlinkListAlloc(NULL);
	dataList = dlinkListAlloc(NULL);

}

static void finalize() {

    fclose(yyin);
    
    deleteSymTable();
 
    cleanupRegisters();
    
    dlinkFreeNodesAndAtoms(instList);
    dlinkFreeNodesAndAtoms(dataList);

}

int main(int argc, char** argv)

{	
	fileName = argv[1];
	initialize(fileName);
	
        yyparse();
  
  	finalize();
  
  	return 0;
}
/******************END OF C ROUTINES**********************/
