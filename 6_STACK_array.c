#include <stdio.h>
#define MAX 10

int stack[MAX];
int top = -1;

void push(int item) {
    if (top == MAX - 1) {
        printf("\nStack Overflow!");
        return;
    }
    stack[++top] = item;
    printf("\n%d pushed to stack.", item);
}

void pop() {
    if (top == -1) {
        printf("\nStack Underflow!");
        return;
    }
    printf("\n%d popped from stack.", stack[top--]);
}

void peek() {
    if (top == -1) {
        printf("\nStack is Empty!");
        return;
    }
    printf("\nTop element is %d.", stack[top]);
}

void display() {
    if (top == -1) {
        printf("\nStack is Empty!");
        return;
    }

    printf("\nStack elements are:");
    for (int i = top; i >= 0; i--)
        printf(" %d", stack[i]);
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push:");
                scanf("%d", &value);
                push(value);
                break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: return 0;
            default: printf("\nInvalid Choice!");
        }
    }
}
