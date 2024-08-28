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

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == Max_size-1;
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

int main() {
    return 0;
}