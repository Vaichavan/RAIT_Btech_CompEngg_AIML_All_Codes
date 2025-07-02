#include <stdio.h>
#define max 10

int queue[max];
int front = -1;
int rear = -1;

void enqueue(int element)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = element;
    }
    else if ((rear + 1) % max == front)
    {
        printf("Queue is overflow..");
    }
    else
    {
        rear = (rear + 1) % max;
        queue[rear] = element;
    }
}

int dequeue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nUnderflow");
    }
    else if (front == rear)
    {
        printf("\nDequeued element: %d", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("\nDequeued element: %d", queue[front]);
        front = (front + 1) % max;
    }
}

void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\nEmpty");
    }
    else
    {
        printf("\nQueue:");
        while (i <= rear)
        {
            printf("\n%d", queue[i]);
            i = (i + 1) % max;
        }
    }
}

int main()
{
    int choice = 1, x;

    while (choice < 5 && choice != 0)
    {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        }
    }
    return 0;
}
