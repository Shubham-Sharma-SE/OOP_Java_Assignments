#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int stack[SIZE];
int top = -1;

void push(int value)
{
    if (top == SIZE - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        top++;
        stack[top] = value;
        printf("Value pushed\n");
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Deleted value: %d\n", stack[top]);
        top--;
    }
}
/*Made changes- Whenever User Enters a number it should be Pushed 2 times and whenever he tries to dequeue it
    should Poped 2 times */
void print()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack: ");

        for (i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }

        printf("\n");
    }
}

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