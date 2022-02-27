#include <stdio.h>

#include "lex.yy.c"

// extern int yylex();
// extern int yylineno;
// extern char* yytext;

int main() {
    yylex();
    return 0;
}