// C program to check whether parentheses are balanced using stack

#include <stdio.h>
#include <string.h>

#define SIZE 50

typedef struct {
    char data[SIZE];
    int top;
} STACK;

// Function to push element into stack
void push(STACK *s, char ch) {
    s->data[++(s->top)] = ch;
}

// Function to pop element from stack
char pop(STACK *s) {
    return s->data[(s->top)--];
}

// Function to check if parentheses are balanced
int isBalanced(char exp[]) {
    STACK s;
    s.top = -1;

    int i;
    char ch, temp;

    for(i = 0; i < strlen(exp); i++) {
        ch = exp[i];

        // If opening bracket, push to stack
        if(ch == '(' || ch == '{' || ch == '[')
            push(&s, ch);

        // If closing bracket, check matching
        else if(ch == ')' || ch == '}' || ch == ']') {
            // Stack empty → no matching opening
            if(s.top == -1)
                return 0;

            temp = pop(&s);

            if((ch == ')' && temp != '(') ||
               (ch == '}' && temp != '{') ||
               (ch == ']' && temp != '['))
                return 0;
        }
    }

    // If stack is empty → balanced
    if(s.top == -1)
        return 1;
    else
        return 0;
}

int main() {
    char exp[SIZE];
    printf("Enter an expression: ");
    scanf("%s", exp);

    if(isBalanced(exp))
        printf("\nParentheses are Balanced.\n");
    else
        printf("\nParentheses are NOT Balanced.\n");

    return 0;
}