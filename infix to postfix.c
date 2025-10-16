#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1)
        return '\0'; // empty stack
    return stack[top--];
}

char peek() {
    if (top == -1)
        return '\0';
    return stack[top];
}

int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else
        return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char c;

    while ((c = infix[i++]) != '\0') {
        if (isspace(c)) continue;  // skip spaces

        if (isalnum(c)) {
            // If operand, add to postfix expression
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            // Pop until '('
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '(' from stack
        } else {
            // Operator encountered
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }

    // Pop all remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    // Remove trailing newline from fgets
    infix[strcspn(infix, "\n")] = 0;

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
