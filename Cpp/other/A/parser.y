%token INTEGER VARIABLE
%left '+' '-'
%left  '*'  '/'

%{

#include <stdio.h>
void yyerror(char*);
int yylex();
int symbols[26];
extern FILE* yyin;

%}

%%

program : program statement '\n'
        |
        ;

statement : expr        { printf("%d\n", $1); }
          | VARIABLE '=' expr   { symbols[$1] = $3; }
          ;

expr : INTEGER
     | VARIABLE             { $$ = symbols[$1]; }
     | expr '+' expr        { $$ = $1 + $3; }
     | expr '-' expr        { $$ = $1 - $3; }
     | expr '*' expr        { $$ = $1 * $3; }
     | expr '/' expr        { $$ = $1 / $3; }
     | '(' expr ')'         { $$ = $2; }
     ;

%%

void yyerror(char* s) {
    fprintf(stderr, "%s\n", s);
    return;
}

int main() {
    // yyin = fopen("code.txt", "r");
    yyparse();
    return 0;
}
