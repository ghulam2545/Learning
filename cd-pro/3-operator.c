// reference : https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ops {
    char ops[20];
    char name[100];
};

typedef struct Ops Ops;

static const Ops Collection[] = {
    {"++", "Postfix/Prefix increment operator"},
    {"--", "Postfix/Prefix decrement operator"},
    {"()", "Function call opetator"},
    {"[]", "Array subscripting operator"},
    {".", "Element selection by reference operator"},
    {"->", "Element selection through pointer operator"},
    {"+", "Unary plus/Addition operator"},
    {"-", "Unary minus/Subtraction operator"},
    {"!", "Logical NOT operator"},
    {"~", "Bitwise NOT operator"},
    {"*", "Indirection/Multiplication operator"},
    {"&", "Address-of/Bitwise AND operator"},
    {"sizeof", "Sizeof operator"},
    {"/", "Division operator"},
    {"%", "Modulo operator"},
    {"<<", "Bitwise left shift operator"},
    {">>", "Bitwise right shift operator"},
    {"<", "Less than operator"},
    {"<=", "Less than or eqaul to operator"},
    {">", "Greater than operator"},
    {">=", "Greater than or equal to operator"},
    {"==", "Equal to operator"},
    {"!=", "Not equal to operator"},
    {"^", "Bitwise XOR operator"},
    {"&&", "Logical AND operator"},
    {"||", "Logical OR operator"},
    {"?:", "Ternary conditional operator"},
    {"=", "Direct assignment operator"},
    {"+=", "Assignment by sum operator"},
    {"-=", "Assignment by difference operator"},
    {"*=", "Assignment by product operator"},
    {"/=", "Assignment by quotient operator"},
    {"%=", "Assignment by remainder operator"},
    {"<<=", "Assignment by bitwise left shift operator"},
    {">>=", "Assignment by bitwise right shift operator"},
    {"&=", "Assignment by bitwise AND operator"},
    {"^=", "Assignment by bitwise XOR operator"},
    {"|=", "Assignment by bitwise OR operator"},
    {",", "Comma operator"},
};

int main() {
    printf("Kindly enter your operator : ");
    char userInput[20];
    scanf("%s", userInput);

    bool isOk = false;
    size_t len = sizeof(Collection) / sizeof(*Collection);
    for (int i = 0; i < len; ++i) {
        int temp = strcmp(Collection[i].ops, userInput);
        if (!temp) {
            printf("%s", Collection[i].name);
            isOk = true;
            break;
        }
    }

    if (!isOk) {
        printf("ERROR : User input is not an operator.");
    }

    return 0;
}