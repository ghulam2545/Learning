/* is this a comment in lex if I am not wrong */

%%

"hi"        printf("Hi There!\n");
"hello"     printf("Hello World\n");
"bye"       printf("Good Bye\n");
.           ;

%%

int yywrap(void) {
    return 0;
}