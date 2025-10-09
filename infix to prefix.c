#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 20
#define LEN 100

struct stack {
    int top;
    char data[SIZE];
};

typedef struct stack STACK;

void Push(STACK *S, char item) {
    if (S->top >= SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    S->data[++(S->top)] = item;
}

char Pop(STACK *S) {
    if (S->top == -1) {
        return '\0';
    }
    return S->data[(S->top)--];
}

int Preced(char symbol) {
    switch (symbol) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void str_reverse(char *str) {
    int len = strlen(str);
    int i, j;
    char temp;

    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void generate_prefix_intermediate(STACK *S, char reversed_infix[]) {
    int i;
    char symbol;
    char intermediate_result[LEN];
    int j = 0;
    char temp;

    for (i = 0; reversed_infix[i] != '\0'; i++) {
        symbol = reversed_infix[i];

        if (isalnum(symbol)) {
            intermediate_result[j++] = symbol;
        } else {
            switch (symbol) {
                case ')':
                    Push(S, symbol);
                    break;
                case '(':
                    temp = Pop(S);
                    while (temp != ')') {
                        intermediate_result[j++] = temp;
                        temp = Pop(S);
                    }
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    while (S->top != -1 && S->data[S->top] != ')' &&
                           Preced(S->data[S->top]) >= Preced(symbol)) {
                        intermediate_result[j++] = Pop(S);
                    }
                    Push(S, symbol);
                    break;
            }
        }
    }

    while (S->top != -1) {
        intermediate_result[j++] = Pop(S);
    }

    intermediate_result[j] = '\0';

    str_reverse(intermediate_result);

    strcpy(reversed_infix, intermediate_result);
}

void infix_to_prefix(STACK *S, char infix[]) {
    str_reverse(infix);
    generate_prefix_intermediate(S, infix);
}

int main() {
    char infix[LEN];
    STACK S;

    S.top = -1;

    printf("Enter infix expression: \n");
    if (fgets(infix,LEN, stdin) != NULL) {
        infix[strcspn(infix, "\n")] = 0;
    } else {
        return 1;
    }

    infix_to_prefix(&S, infix);

    printf("Prefix expression is: %s\n", infix);

    return 0;
}