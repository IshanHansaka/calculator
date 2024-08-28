#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define Max_size 100

char postfix[Max_size];
int stack[Max_size];
int top = -1;

bool isEmpty();
bool isFull();
void push(int data);
int pop();
int peak();
int precedence(char symbol);
void infixToPostfix(char equation[100]);
int postfixToAnswer(char equation[100]);

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == Max_size - 1;
}

void push(int data) {
    if (isFull()) {
        return;
    }
    stack[++top] = data;
}

int pop() {
    if (isEmpty()) {
        return -1;
    }
    return stack[top--];
}

int peak() {
    if (isEmpty()) {
        return -1;
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
                    postfix[arr_index++] = next;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (!isEmpty() && precedence(equation[i]) <= precedence(peak())) {
                    postfix[arr_index++] = pop();
                }
                push(equation[i]);
                break;
            default:
                postfix[arr_index++] = equation[i];
                break;
        }
        i++;
    }

    while (!isEmpty()) {
        postfix[arr_index++] = pop();
    }
    postfix[arr_index] = '\0';
}

int postfixToAnswer(char equation[100]) {
    int i = 0;
    int num1, num2;
    while (equation[i] != '\0') {
        if (equation[i] >= '0' && equation[i] <= '9') {
            push(equation[i] - '0'); // Convert char to int
        } 
        else {
            num2 = pop();
            num1 = pop();
            switch (equation[i]) {
                case '+':
                    push(num1 + num2);break;
                case '-':
                    push(num1 - num2);break;
                case '*':
                    push(num1 * num2);break;
                case '/':
                    push(num1 / num2);break;
                case '^':
                    push((int)pow(num1, num2)); // Convert double to int
                    break;
            }
        }
        i++;
    }
    return pop();
}

int main() {
    char expression[100];
    printf("Enter the infix expression: ");
    scanf("%s", expression);

    infixToPostfix(expression);

    printf("Postfix expression: %s\n", postfix);

    int answer = postfixToAnswer(postfix);
    printf("Answer: %d\n", answer);
    return 0;
}