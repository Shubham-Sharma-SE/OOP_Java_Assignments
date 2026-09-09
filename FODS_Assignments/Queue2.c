//<2>Implentation of queue using liked list 
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;
struct Node *temp = NULL;
void enqueue(int value)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Value inserted\n");
}

void dequeue()
{
    struct Node *temp;

    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp = front;

        printf("Deleted value: %d\n", front->data);

        front = front->next;

        if (front == NULL)
        {
            rear = NULL;
        }

        free(temp);
    }
}

void print()
{
    struct Node *temp;

    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp = front;

        printf("Queue: ");

        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
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