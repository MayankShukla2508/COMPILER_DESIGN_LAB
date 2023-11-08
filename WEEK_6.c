#include <stdio.h>

#define SUCCESS 1
#define FAILED 0

const char *pointer;
char input[50];

// Forward declarations of parsing functions
int E();
int T();
int Ed();
int Td();
int F();

// E -> TE'
int E() {
    if (T()) {
        if (Ed()) {
            return SUCCESS;
        } else {
            return FAILED;
        }
    } else {
        return FAILED;
    }
}

// T -> FT'
int T() {
    if (F()) {
        if (Td()) {
            return SUCCESS;
        } else {
            return FAILED;
        }
    } else {
        return FAILED;
    }
}

// E' -> +TE' | epsilon
int Ed() {
    if (*pointer == '+') {
        pointer++;
        if (T()) {
            if (Ed()) {
                return SUCCESS;
            } else {
                return FAILED;
            }
        } else {
            return FAILED;
        }
    } else {
        return SUCCESS; // epsilon
    }
}

// T' -> *FT | epsilon
int Td() {
    if (*pointer == '*') {
        pointer++;
        if (F()) {
            if (Td()) {
                return SUCCESS;
            } else {
                return FAILED;
            }
        } else {
            return FAILED;
        }
    } else {
        return SUCCESS; // epsilon
    }
}

// F -> (E) | 'd'
int F() {
    if (*pointer == '(') {
        pointer++;
        if (E()) {
            if (*pointer == ')') {
                pointer++;
                return SUCCESS;
            } else {
                return FAILED;
            }
        } else {
            return FAILED;
        }
    } else if (*pointer == 'd') {
        pointer++;
        return SUCCESS;
    } else {
        return FAILED;
    }
}

int main() {
    scanf("%s", input);
    pointer = input;
    if (E() && *pointer == '\0') {
        printf("String is successfully parsed\n");
        return 0;
    } else {
        printf("String is not parsed\n");
        return 1;
    }
}