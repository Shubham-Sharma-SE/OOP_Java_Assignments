#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = top;

    top = newNode;

    printf("Value pushed\n");
}

void pop()
{
    struct Node *temp;

    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        temp = top;

        printf("Deleted value: %d\n", top->data);

        top = top->next;

        free(temp);
    }
}

void print()
{
    struct Node *temp;

    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        temp = top;

        printf("Stack: ");

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
        printf("1. Push\n");
        printf("2. Pop\n");
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

                push(value);
                push(value);
                break;

            case 2:
                pop();
                pop();
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