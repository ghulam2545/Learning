%{
#include <stdio.h>
int vowel = 0;
int consonent = 0;
%}

%%

[aeiouAEIOU] { ++vowel; }
[a-zA-Z]     { ++consonent; }
[ ]          { }
.            { printf("invalid string"); }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter your string : ");
    yylex();
    printf("count of vowels : %d\ncount of consonent : %d.", vowel, consonent);

    return 0;
}