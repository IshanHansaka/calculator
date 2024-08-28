#include <stdio.h>
#include <stdbool.h>
#define Max_size 100

char arr[Max_size];
char stack[Max_size];
int top = -1;

bool isEmpty();
bool isFull();
void push(char data);
char pop();
char peak();
int precedence(char symbol);
void infixToPostfix(char equation[100]);

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == Max_size - 1;
}

void push(char data) {
    if (isFull()) {
        return;
    }
    stack[++top] = data;
}

char pop() {
    if (isEmpty()) {
        return '\0';
    }
    return stack[top--];
}

char peak() {
    if (isEmpty()) {
        return '\0';
    }
    return stack[top];
}

int precedence(char symbol) {
    switch (symbol) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

void infixToPostfix(char equation[100]) {
    int i = 0, arr_index = 0;
    char next;
    while (equation[i] != '\0') {
        switch (equation[i]) {
            case '(':
                push(equation[i]);
                break;
            case ')':
                while ((next = pop()) != '(') {
                    arr[arr_index++] = next;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (!isEmpty() && precedence(equation[i]) <= precedence(peak())) {
                    arr[arr_index++] = pop();
                }
                push(equation[i]);
                break;
            default:
                arr[arr_index++] = equation[i];
                break;
        }
        i++;
    }

    while (!isEmpty()) {
        arr[arr_index++] = pop();
    }
    arr[arr_index] = '\0';
}

int postfixtoAnswer(char equation[100]) {
}

int main() {
    char equation[100];
    printf("Enter the equation: ");
    scanf("%s", equation);

    infixToPostfix(equation);

    printf("Postfix expression: %s\n", arr);
    return 0;
}