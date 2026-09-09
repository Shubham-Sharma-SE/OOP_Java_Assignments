#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char word[30];
    char meaning[100];

    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insert()
{
    struct Node *newNode;
    struct Node *last;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("\nEnter word: ");
    scanf("%s", newNode->word);

    printf("Enter meaning: ");
    scanf(" %[^\n]", newNode->meaning);

    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;

        newNode->next = head;
        newNode->prev = head;
    }
    else
    {
        last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;
    }

    printf("\nWord inserted successfully.\n");
}

void deleteWord()
{
    char word[30];
    struct Node *temp;
    struct Node *last;

    if (head == NULL)
    {
        printf("\nDictionary is empty.\n");
        return;
    }

    printf("\nEnter word to delete: ");
    scanf("%s", word);

    temp = head;

    do
    {
        if (strcmp(temp->word, word) == 0)
        {
            if (temp->next == head && temp->prev == head)
            {
                head = NULL;
            }
            else
            {
                last = head->prev;

                if (temp == head)
                {
                    head = head->next;
                }

                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                if (temp == head)
                {
                    head->prev = last;
                }
            }

            free(temp);

            printf("\nWord deleted successfully.\n");
            return;
        }

        temp = temp->next;

    } while (temp != head);

    printf("\nWord not found.\n");
}

void update()
{
    char word[30];
    struct Node *temp;

    if (head == NULL)
    {
        printf("\nDictionary is empty.\n");
        return;
    }

    printf("\nEnter word to update: ");
    scanf("%s", word);

    temp = head;

    do
    {
        if (strcmp(temp->word, word) == 0)
        {
            printf("Enter new meaning: ");
            scanf(" %[^\n]", temp->meaning);

            printf("\nWord updated successfully.\n");
            return;
        }

        temp = temp->next;

    } while (temp != head);

    printf("\nWord not found.\n");
}

void display()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("\nDictionary is empty.\n");
        return;
    }

    printf("\n--- DICTIONARY ---\n");

    temp = head;

    do
    {
        printf("\nWord: %s", temp->word);
        printf("\nMeaning: %s\n", temp->meaning);

        temp = temp->next;

    } while (temp != head);
}

int main()
{
    int choice;

    do
    {
        printf("\n\nDOUBLY CIRCULAR LINKED LIST DICTIONARY");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Update");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                deleteWord();
                break;

            case 3:
                update();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("\nProgram ended.\n");
                break;

            default:
                printf("\nInvalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}