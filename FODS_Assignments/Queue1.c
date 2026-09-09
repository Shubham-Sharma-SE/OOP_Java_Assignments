//  Implemenetation Of Queue Using Array and Linked list
// <1> Implementation Using Array
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int queue[SIZE];

int front = -1;
int rear = -1;

void enqueue(int value)
{
    if (rear == SIZE - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }

        rear++;

        queue[rear] = value;

        printf("Value inserted\n");
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Deleted value: %d\n", queue[front]);

        front++;

        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}

void print()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue: ");

        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}
/*Made changes- Whenever User Enters a number it should enqueued 2 times and whenever he tries to dequeue it
    should dequeue 2 times */ 
int main()
{
    int choice;
    int value;

    do
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print\n");
        printf("4. Exit\n");

        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n');
            choice = 0;
        }

        switch (choice)
        {
            case 1:
                printf("Enter value: ");

                if (scanf("%d", &value) != 1)
                {
                    while (getchar() != '\n');
                    printf("Invalid value\n");
                    break;
                }

                enqueue(value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                dequeue();
                break;

            case 3:
                print();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 4);

    return 0;
}