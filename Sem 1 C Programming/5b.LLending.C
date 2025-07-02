#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(int data) {
    struct Node* temp = head;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;


    if (head == NULL) {
	newNode->prev = NULL;
	head = newNode;
	return;
    }


    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    printf("Element inserted at the end.\n");
}

// Function to delete a node from the end of the doubly linked list
void deleteFromEnd() {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty, deletion not possible.\n");
        return;
    }


    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev == NULL) {
        head = NULL;
    } else {
        temp->prev->next = NULL;
    }

    free(temp);
    printf("Element deleted from the end.\n");
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
        printf("1. Insert at the end\n");
        printf("2. Delete from the end\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 2:
                deleteFromEnd();
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
