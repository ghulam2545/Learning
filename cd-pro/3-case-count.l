%{
#include <stdio.h>
int lower = 0;
int upper = 0;
%}

%%

[a-z]   { ++lower; }
[A-Z]   { ++upper; }
[ ]
.       { printf("invalid string."); }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter your string : ");
    yylex();
    printf("lowercase count : %d\nuppercase count :%d.", lower, upper);

    return 0;
}