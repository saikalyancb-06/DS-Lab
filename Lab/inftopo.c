#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX 256

char st[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("\nStack Overflow!\n");
    } else {
        top++;
        st[top] = c;
    }
}

char pop() {
    if (top == -1) {
        printf("\nStack Underflow!\n");
        return '\0';
    } else {
        char item = st[top];
        top--;
        return item;
    }
}

char peek() {
    if (top != -1) {
        return st[top];
    }
    return '\0';
}

bool isempty() {
    return top == -1;
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    else if (op == '/' || op == '*') return 2;
    return 0;
}

void infix_to_postfix(const char* infix, char* postfix) {
    int i;
    int j = 0;

    for (i = 0; i < strlen(infix); i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix[j++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (!isempty() && peek() != '(') {
                postfix[j++] = pop();
            }
            if (!isempty() && peek() == '(') {
                pop();
            }
        }
        else {
            while (!isempty() && peek() != '(' && precedence(c) <= precedence(peek())) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }

    while (!isempty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("\nPostfix Expression: %s\n", postfix);
}
int main() {
    printf("Enter the Infix expression: ");
    char infix_exp[MAX];
    char postfix_exp[MAX];

    gets(infix_exp);
    infix_to_postfix(infix_exp, postfix_exp);
    return 0;
}
    
