// reference : https://en.wikipedia.org/wiki/LL_parser

/**
 * GRAMMER
 * E --> TE'
 * E' --> +TE'/ε
 * T --> FT'
 * T' --> *FT'/ε
 * E --> (E)/id
 */

#include <iostream>
#include <map>
#include <stack>
#include <string>
#define log std::cout << "I'm here\n";

enum symbol {
    /**
     * these are our terminal symbols used in grammer.
     */
    LEFT_BRACE = 0,
    RIGHT_BRACE = 1,
    PLUS_OPS = 2,
    STAR_OPS = 3,
    IDENTIFIER = 4,
    EPSILON = 5,
    END_OF_STRING = 6,
    INVALID_SYMBOL = 7,

    /**
     * these are our non-terminal symbols used in grammer.
     * look at productions for more...
     */
    E = 8,  // this is our start symbol
    T = 9,
    E_DASH = 10,
    F = 11,
    T_DASH = 12
};

/**
 * this is lexer function tell us about each token/lexem
 */
symbol lexer(char ch);

/**
 * this is parser function does parsing of token/lexem
 */
bool parse(std::string input_buff);

using std::cout;
int main(int argc, char** argv) {
    // id*id+id
    // I'm replacing 'id' by 'a' bcz 'id' is a multichars (just for easiness)
    auto our_string = "a*a+a";

    if (parse(our_string)) {
        cout << "\nParsing successfull.\n";
    } else {
        cout << "\nLOL : you haven't provided string that follow our grammer.\n";
    }
    return 0;
}

symbol lexer(char ch) {
    switch (ch) {
        case '(':
            return LEFT_BRACE;
        case ')':
            return RIGHT_BRACE;
        case '+':
            return PLUS_OPS;
        case '*':
            return STAR_OPS;
        case 'a':
            return IDENTIFIER;
        case '\0':
            return END_OF_STRING;
        default:
            return INVALID_SYMBOL;
    }
}

bool parse(std::string input_buff) {
    std::map<symbol, std::map<symbol, int>> parse_table;
    std::stack<symbol> charsStack;

    charsStack.push(END_OF_STRING);
    charsStack.push(E);

    // here we are telling about parsing table, on the basis of that
    // our string will be parsed
    parse_table[E][LEFT_BRACE] = 1;
    parse_table[E][IDENTIFIER] = 1;
    parse_table[E_DASH][PLUS_OPS] = 2;
    parse_table[E_DASH][EPSILON] = 3;
    parse_table[E_DASH][END_OF_STRING] = 3;
    parse_table[T][LEFT_BRACE] = 4;
    parse_table[T][IDENTIFIER] = 4;
    parse_table[T_DASH][STAR_OPS] = 5;
    parse_table[T_DASH][PLUS_OPS] = 6;
    parse_table[T_DASH][RIGHT_BRACE] = 6;
    parse_table[T_DASH][END_OF_STRING] = 6;
    parse_table[F][LEFT_BRACE] = 7;
    parse_table[F][IDENTIFIER] = 8;

    int index = 0;
    while (charsStack.size()) {
        if (lexer(input_buff[index]) == charsStack.top()) {
            if (charsStack.top() == END_OF_STRING) {
                cout << "matched symbol : END_OF_STRING\n";
                break;
            }
            cout << "matched symbol : " << input_buff[index] << "\n";
            ++index;
            charsStack.pop();
        } else {
            // here we are telling about our productions
            auto non_terminal = parse_table[charsStack.top()][lexer(input_buff[index])];
            switch (non_terminal) {
                case 1:
                    charsStack.pop();
                    charsStack.push(E_DASH);
                    charsStack.push(T);
                    break;
                case 2:
                    charsStack.pop();
                    charsStack.push(E_DASH);
                    charsStack.push(T);
                    charsStack.push(PLUS_OPS);
                    break;
                case 3:
                    charsStack.pop();
                    break;
                case 4:
                    charsStack.pop();
                    charsStack.push(T_DASH);
                    charsStack.push(F);
                    break;
                case 5:
                    charsStack.pop();
                    charsStack.push(T_DASH);
                    charsStack.push(F);
                    charsStack.push(STAR_OPS);
                    break;
                case 6:
                    charsStack.pop();
                    break;
                case 7:
                    charsStack.pop();
                    charsStack.push(RIGHT_BRACE);
                    charsStack.push(E);
                    charsStack.push(LEFT_BRACE);
                    break;
                case 8:
                    charsStack.pop();
                    charsStack.push(IDENTIFIER);
                    break;
                default:
                    cout << "ERROR : some funky statement/chars has encountered.\n";
                    return false;
            }
        }
    }
    return true;
}