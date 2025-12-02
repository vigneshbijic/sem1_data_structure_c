#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *top = NULL;

void push() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nNo space available\n");
        return;
    }
    newnode->link = NULL;
    printf("\nEnter the element to insert: ");
    scanf("%d", &newnode->data);
    if (top == NULL) {
        top = newnode;
    } else {
        newnode->link = top;
        top = newnode;
    }
    printf("\n%d inserted successfully\n", newnode->data);
}

void pop() {
    struct node *temp = top;
    if (top == NULL) {
        printf("Stack underflow\n");
        return;
    }
    printf("%d is popped\n", temp->data);
    top = temp->link;
    free(temp);
}

void display() {
    struct node *temp = top;
    if (top == NULL) {
        printf("\nNo elements\n");
        return;
    }
    printf("Elements in stack are: ");
    while (temp != NULL) {
        printf(" %d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void peek() {
    struct node *temp = top;
    if (top == NULL) {
        printf("Stack underflow\n");
        return;
    }
    printf("Top element is %d\n", temp->data);
}

void search() {
    struct node *temp = top;
    int key, found = 0, pos = 0;
    if (top == NULL) {
        printf("\nStack underflow\n");
        return;
    }
    printf("\nEnter the element to search: ");
    scanf("%d", &key);
    while (temp != NULL) {
        if (temp->data == key) {
            printf("\n%d element found at position %d\n", temp->data, pos + 1);
            found = 1;
        }
        temp = temp->link;
        pos++;
    }
    if (!found) {
        printf("\nElement not found\n");
    }
}

void freeStack() {
    struct node *temp;
    while (top != NULL) {
        temp = top;
        top = top->link;
        free(temp);
    }
}

int main() {
    int choice;
    do {
        printf("\nStack Operations\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Search\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                search();
                break;
            case 6:
                freeStack();
                printf("\nExiting...\n");
                break;
            default:
                printf("Enter a valid choice\n");
                break;
        }
    } while (choice != 6);
    return 0;
}

