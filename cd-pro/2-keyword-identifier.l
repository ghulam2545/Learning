%{
#include <stdio.h>
#include <stdbool.h>
bool is_keyword = false;
bool is_identifier = false;
%}

%%
"int"|"float"|"double"|"long"|"char"  { is_keyword = true; }
"if"|"else"|"switch"|"case"           { is_keyword = true; }
"for"|"while"|"do"|"break"            { is_keyword = true; }
[_]*[[a-zA-Z]*[0-9]*[_]*              { is_identifier = true; }
.+                                    { printf("invalid string."); }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter your string here : ");
    yylex();
    if(is_keyword) printf("string is a keyword.");
    if(is_identifier) printf("string is an identifier.");

    return 0;
}

