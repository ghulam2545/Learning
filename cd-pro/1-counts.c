#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "ERROR : no input file is provided.\n");
        exit(1);
    }

    FILE* fin = fopen(argv[1], "r");
    if (fin == NULL) {
        fprintf(stderr, "ERROR : could not open file.\n");
        exit(1);
    }
    int chars = 0;
    int digits = 0;
    int spaces = 0;
    int lines = 1;
    int special_chars = 0;
    int alphabets = 0;

    while (1) {
        char ch = fgetc(fin);

        if ((ch >= 'a' || ch >= 'A') && (ch >= 'z' || ch >= 'Z'))
            ++alphabets;
        else if (ch >= '0' && ch <= '9')
            ++digits;
        else if (ch == ' ')
            ++spaces;
        else if (ch == '\n')
            ++lines;
        else
            ++special_chars;
        ++chars;

        if (feof(fin)) break;
    }

    printf("no of chars         : %d\n", chars);
    printf("no of digits        : %d\n", digits);
    printf("no of spaces        : %d\n", spaces);
    printf("no of lines         : %d\n", lines);
    printf("no of special chars : %d\n", special_chars);
    printf("no of alphabets     : %d\n", alphabets);

    fclose(fin);
    return 0;
}