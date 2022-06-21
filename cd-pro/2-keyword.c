#include <stdbool.h>
#include <stdio.h>
#include <string.h>

const char* keywords[] = {"auto",   "break",  "case",   "char",   "const",   "continue", "default",  "do",       "double",   "else",  "enum",
                          "extern", "float",  "for",    "goto",   "if",      "int",      "long",     "register", "return",   "short", "signed",
                          "sizeof", "static", "struct", "switch", "typedef", "union",    "unsigned", "void",     "volatile", "while"};

int main() {
    char str[100];
    printf("Enter your string here : ");
    scanf("%s", str);

    bool isKeyword = false;

    int len = sizeof(keywords) / sizeof(*keywords);

    for (int i = 0; i < len; ++i) {
        int ans = strcmp(keywords[i], str);
        if (ans == 0) {
            isKeyword = true;
            break;
        }
    }

    if (isKeyword)
        printf("YES: Your input is a valid C keyword.\n");
    else
        printf("NO: Your input is not a valid C keyword.\n");

    return 0;
}