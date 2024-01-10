WS	[ \t]

%{
#include <stdio.h>
#include "CminusParser.h"
#include <util/string_utils.h>
%}

%%

int				{ return INTEGER;}
while				{ return WHILE; }
else				{ return ELSE; }
exit				{ return EXIT; }
if				{ return IF; }
scanf				{ return READ; }
printf				{ return WRITE; }
return				{ return RETURN; }
\#include			{ return INCLUDE; }

\!				{ return NOT;}
"||"		    		{ return OR;}
\&&				{ return AND;}
\<=				{ return LE; }
\<				{ return LT; }
\>=				{ return GE; }
\>				{ return GT; }
\==				{ return EQ; }
\!=				{ return NE; }
\=				{ return ASSIGN; }
\;				{ return SEMICOLON; }
\{			    	{ return LBRACE; }
"}"			    	{ return RBRACE; }
\[				{ return LBRACKET; }
\]				{ return RBRACKET; }
\(				{ return LPAREN; }
\)				{ return RPAREN; }
\+				{ return PLUS; }
\-          			{ return MINUS; }
\*				{ return TIMES; }
\/				{ return DIVIDE;}
\&				{ return ADDR;}
","				{ return COMMA;}
\"[^\"]*\"			{ yylval.name = ssave(yytext);
                                  return STRING; }
\<[a-zA-Z]+\.h\>		{ return HEADERSTRING; }
[a-zA-Z]([a-zA-Z]|[0-9])*	{ yylval.name = ssave(yytext); 
                                  return IDENTIFIER; }
[0-9]+				{ yylval.name = ssave(yytext); return INTCON; }
{WS}				{ ; }
"\n"				{ yylineno++;}
.				{
				  fprintf(stderr, "Scanner: lexical error '%s'.\n", yytext); 
				}
%%
