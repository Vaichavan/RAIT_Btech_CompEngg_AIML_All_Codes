#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

// Function to insert a node at the beginning of the doubly linked list
void insertAtBegin(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
    printf("Element inserted at the beginning.\n");
}

// Function to delete a node from the beginning of the doubly linked list
void deleteFromBegin() {
    struct Node* temp = head;
    head = head->next;
    if (head == NULL) {
        printf("List is empty, deletion not possible.\n");
	return;
    }



    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
    printf("Element deleted from the beginning.\n");
}

// Function to display the doubly linked list
void display() {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly linked list elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data;

    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Delete from the beginning\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtBegin(data);
                break;
            case 2:
                deleteFromBegin();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
