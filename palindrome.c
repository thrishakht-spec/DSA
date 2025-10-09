#include <stdio.h>
#include <string.h>
#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char item) {
    if (top >= SIZE - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = item;
}

char pop() {
    if (top < 0) {
        return '\0';
    }
    return stack[top--];
}

void remove_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void palindrome(char str[]) {
    int length = strlen(str);
    int i;

    for (i = 0; i < length / 2; i++) {
        push(str[i]);
    }

    int start_index = (length % 2 != 0) ? (length / 2) + 1 : length / 2;

    for (i = start_index; i < length; i++) {
        char popped_char = pop();

        if (popped_char == '\0') {
            printf("Error: Stack underflow during comparison.\n");
            return;
        }

        if (str[i] != popped_char) {
            printf("\"%s\" is NOT a palindrome.\n", str);
            top = -1;
            return;
        }
    }

    printf("\"%s\" IS a palindrome.\n", str);

    top = -1;
}

int main() {
    char input[SIZE];

    printf("Enter a word or phrase to check if it's a palindrome: ");

    if (fgets(input, SIZE, stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    remove_newline(input);

    palindrome(input);

    return 0;
}