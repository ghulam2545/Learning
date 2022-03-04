%{

#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"
void yyerror(char*);

%}

%%

[a-z]+          {
                    yylval = *yytext - 'a';
                    return VARIABLE;
                }

[0-9]+		    {
                    yylval = atoi(yytext);
                    return INTEGER;
                }

[-+()=/*\n]	{ return  *yytext; }

[ \t]		;

.		yyerror("Invalid character");

%%

int yywrap() {
	return 0;
}
