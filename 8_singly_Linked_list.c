#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *head = NULL;

void insertFirst() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nNo space available\n");
        return;
    }
    printf("Enter the value to insert at Front: ");
    scanf("%d", &newnode->data);
    newnode->link = head;
    head = newnode;
    printf("Element %d inserted successfully at front.\n", newnode->data);
}

void insertLast() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nNo space available\n");
        return;
    }
    printf("Enter the value to insert at Last: ");
    scanf("%d", &newnode->data);
    newnode->link = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = newnode;
    }
    printf("Element %d inserted successfully at last.\n", newnode->data);
}

void insertLocation() {
    int key;
    struct node *temp = head, *newnode;

    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    printf("Enter the key after which to insert: ");
    scanf("%d", &key);

    while (temp != NULL && temp->data != key) {
        temp = temp->link;
    }

    if (temp == NULL) {
        printf("Key not found.\n");
        return;
    }

    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("No space available.\n");
        return;
    }

    printf("Enter value to insert after %d: ", key);
    scanf("%d", &newnode->data);
    newnode->link = temp->link;
    temp->link = newnode;

    printf("Element %d inserted successfully after %d.\n", newnode->data, key);
}

void deleteFirst() {
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    struct node *temp = head;
    head = head->link;
    printf("Value %d deleted from front.\n", temp->data);
    free(temp);
}

void deleteLast() {
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    struct node *temp = head;
    struct node *prev = NULL;

    if (head->link == NULL) {
        printf("Value %d deleted from last.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    while (temp->link != NULL) {
        prev = temp;
        temp = temp->link;
    }

    printf("Value %d deleted from last.\n", temp->data);
    prev->link = NULL;
    free(temp);
}

void deleteLocation() {
    int key;
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    printf("Enter the value to delete: ");
    scanf("%d", &key);

    struct node *temp = head;
    struct node *prev = NULL;

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", key);
        return;
    }

    if (prev == NULL) { // Deleting head
        head = temp->link;
    } else {
        prev->link = temp->link;
    }

    printf("Value %d deleted from list.\n", key);
    free(temp);
}

void search() {
    int val, pos = 1, found = 0;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter the value to search: ");
    scanf("%d", &val);

    struct node *temp = head;
    while (temp != NULL) {
        if (temp->data == val) {
            printf("Value %d found at position %d.\n", val, pos);
            found = 1;
            break;
        }
        temp = temp->link;
        pos++;
    }

    if (!found)
        printf("Value %d not found in the list.\n", val);
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;
    printf("Elements in the list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    
}

int main() {
    int choice;

    printf("Singly Linked List Operations\n");

    do {
        printf("\n1. Insert at Front\n2. Insert at Last\n3. Insert at Location\n4. Delete First\n5. Delete Last\n6. Delete Specific\n7. Search\n8. Display\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertFirst(); break;
            case 2: insertLast(); break;
            case 3: insertLocation(); break;
            case 4: deleteFirst(); break;
            case 5: deleteLast(); break;
            case 6: deleteLocation(); break;
            case 7: search(); break;
            case 8: display(); break;
            case 9: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }

    } while (choice != 9);

    return 0;
}

