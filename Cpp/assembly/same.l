/* this does the same as you expect */
/* #define ECHO (void) fwrite( yytext, yyleng, 1, yyout ) */


%{

#include <stdio.h>
#include <conio.h>

%}

%%

\n      ECHO;
.       ECHO;

%%

int main(int argc, const char** argv) {
    // standered IO
    // yyin = fopen(argv[1], "r");
    
    // file IO
    yyin = fopen("test.txt", "r");
    yylex();
    getch();
    return 0;
}

int yywrap() {
    return 1;
}