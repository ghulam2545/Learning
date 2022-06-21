%{
#include <stdio.h>
int space = 0;
int tab  = 0;
int new_line = 0;
int alphabets = 0;
int number = 0;
int other = 0;
%}

%%

[ ]     { ++space; }
[\t]    { ++tab; }
[\n]    { ++new_line; }
[a-zA-Z]    { ++alphabets; }
[0-9]   { ++number; }
.       { ++other; }

%%

int yywrap() {
    return 1;
}

int main(int argc, char** argv) {
    printf("Getting input file from terminal.\n");
    yyin = fopen(argv[1], "r");
    yylex();
    printf("number of space      : %d\n", space);
    printf("number of tab        : %d\n", tab);
    printf("number of new_line   : %d\n", new_line);
    printf("number of alphabets  : %d\n", alphabets);
    printf("number of numbers    : %d\n", number);
    printf("number of others     : %d\n", other);

    return 0;
}