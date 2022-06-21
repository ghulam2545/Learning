%{
#include <stdio.h>
int len = 0;
%}

%%

[a-zA-Z]+    { len = yyleng; }
.+           { printf("invalid item."); }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter your string here : ");
    yylex();
    printf("Length of your string is : %d\n", len);

    return 0;
}
