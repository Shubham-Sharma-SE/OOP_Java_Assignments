#include <stdio.h>
#include <stdlib.h>

struct StudentInfo
{
    int rollNo;
    struct StudentInfo *left;
    struct StudentInfo *right;
};

struct Queue
{
    struct StudentInfo *data;
    struct Queue *next;
};

struct Stack
{
    struct StudentInfo *data;
    struct Stack *next;
};

struct StudentInfo *root = NULL;

struct Queue *front = NULL;
struct Queue *rear = NULL;

struct Stack *top = NULL;


void enqueue(struct StudentInfo *node)
{
    struct Queue *newNode;

    newNode = (struct Queue*)malloc(sizeof(struct Queue));

    newNode->data = node;
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
}

struct StudentInfo *dequeue()
{
    struct Queue *temp;
    struct StudentInfo *node;

    if (front == NULL)
    {
        return NULL;
    }

    temp = front;
    node = front->data;

    front = front->next;

    if (front == NULL)
    {
        rear = NULL;
    }

    free(temp);
    return node;
}

void clearQueue()
{
    while (front != NULL)
    {
        dequeue();
    }
}


void push(struct StudentInfo *node)
{
    struct Stack *newNode;

    newNode = (struct Stack*)malloc(sizeof(struct Stack));

    newNode->data = node;
    newNode->next = top;

    top = newNode;
}

struct StudentInfo *pop()
{
    struct Stack *temp;
    struct StudentInfo *node;

    if (top == NULL)
    {
        return NULL;
    }

    temp = top;
    node = top->data;

    top = top->next;

    free(temp);
    return node;
}

void clearStack()
{
    while (top != NULL)
    {
        pop();
    }
}

void createBinary(int rollNo)
{
    struct StudentInfo *newNode;
    struct StudentInfo *temp;

    newNode = (struct StudentInfo *)malloc(sizeof(struct StudentInfo));

    newNode->rollNo = rollNo;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL)
    {
        root = newNode;
        return;
    }

    enqueue(root);

    while (front != NULL)
    {
        temp = dequeue();

        if (temp->left == NULL)
        {
            temp->left = newNode;
            break;
        }
        else
        {
            enqueue(temp->left);
        }

        if (temp->right == NULL)
        {
            temp->right = newNode;
            break;
        }
        else
        {
            enqueue(temp->right);
        }
    }

    clearQueue();
}

void inorderRecursive(struct StudentInfo *node)
{
    if (node != NULL)
    {
        inorderRecursive(node->left);
        printf("%d ", node->rollNo);
        inorderRecursive(node->right);
    }
}

void preorderRecursive(struct StudentInfo *node)
{
    if (node != NULL)
    {
        printf("%d ", node->rollNo);
        preorderRecursive(node->left);
        preorderRecursive(node->right);
    }
}

void postorderRecursive(struct StudentInfo *node)
{
    if (node != NULL)
    {
        postorderRecursive(node->left);
        postorderRecursive(node->right);
        printf("%d ", node->rollNo);
    }
}

void inorderIterative()
{
    struct StudentInfo *node;

    node = root;

    while (node != NULL || top != NULL)
    {
        while (node != NULL)
        {
            push(node);
            node = node->left;
        }

        node = pop();

        printf("%d ", node->rollNo);

        node = node->right;
    }

    clearStack();
    printf("\n");
}

void preorderIterative()
{
    struct StudentInfo *node;

    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }

    push(root);

    while (top != NULL)
    {
        node = pop();

        printf("%d ", node->rollNo);

        if (node->right != NULL)
        {
            push(node->right);
        }

        if (node->left != NULL)
        {
            push(node->left);
        }
    }

    printf("\n");
}

void postorderIterative()
{
    struct StudentInfo *node;
    struct StudentInfo *previous = NULL;

    node = root;

    while (node != NULL || top != NULL)
    {
        while (node != NULL)
        {
            push(node);
            node = node->left;
        }

        node = top->data;

        if (node->right != NULL && node->right != previous)
        {
            node = node->right;
        }
        else
        {
            printf("%d ", node->rollNo);
            previous = node;
            pop();
            node = NULL;
        }
    }

    printf("\n");
}

void update(int oldRollNo, int newRollNo)
{
    struct StudentInfo *temp;
    int found = 0;

    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }

    enqueue(root);

    while (front != NULL)
    {
        temp = dequeue();

        if (temp->rollNo == oldRollNo)
        {
            temp->rollNo = newRollNo;
            found = 1;
            break;
        }

        if (temp->left != NULL)
            enqueue(temp->left);

        if (temp->right != NULL)
            enqueue(temp->right);
    }

    clearQueue();

    if (found)
        printf("Student updated successfully\n");
    else
        printf("Student not found\n");
}

void deleteNode(int rollNo)
{
    struct StudentInfo *target = NULL;
    struct StudentInfo *deepest = NULL;
    struct StudentInfo *parent = NULL;
    struct StudentInfo *temp;

    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }

    enqueue(root);

    while (front != NULL)
    {
        temp = dequeue();

        if (temp->rollNo == rollNo)
            target = temp;

            deepest = temp;

        if (temp->left != NULL)
            enqueue(temp->left);

        if (temp->right != NULL)
            enqueue(temp->right);
    }

    clearQueue();

    if (target == NULL)
    {
        printf("Student not found\n");
        return;
    }

    if (deepest == root)
    {
        free(root);
        root = NULL;
        printf("Student deleted successfully\n");
        return;
    }

    enqueue(root);

    while (front != NULL)
    {
        temp = dequeue();

        if (temp->left == deepest || temp->right == deepest)
        {
            parent = temp;
            break;
        }

        if (temp->left != NULL)
            enqueue(temp->left);

        if (temp->right != NULL)
            enqueue(temp->right);
    }

    clearQueue();

    target->rollNo = deepest->rollNo;

    if (parent->left == deepest)
        parent->left = NULL;

    if (parent->right == deepest)
        parent->right = NULL;

    free(deepest);

    printf("Student deleted successfully\n");
    
}
                   /*Inorder- Left Root Right
                    Preorder- Root Left Right
                    Postorder- Left Right Root Read them using Iterative and Recursive */
void readTree()
{
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }

    printf("\nInorder Iterative: ");
    inorderIterative();

    printf("Preorder Iterative: ");
    preorderIterative();

    printf("Postorder Iterative: ");
    postorderIterative();

    printf("Inorder Recursive: ");
    inorderRecursive(root);
    printf("\n");

    printf("Preorder Recursive: ");
    preorderRecursive(root);
    printf("\n");

    printf("Postorder Recursive: ");
    postorderRecursive(root);
    printf("\n");
}

int main()
{
    int choice;
    int rollNo;
    int newRollNo;

    do
    {
        printf("\n1. Create\n");
        printf("2. Read\n");
        printf("3. Update\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n');
            printf("Invalid choice\n");
            continue;
        }

        switch (choice)
        {
            case 1:
                printf("Enter roll number: ");

                if (scanf("%d", &rollNo) != 1)
                {
                    while (getchar() != '\n');
                    printf("Invalid roll number\n");
                    break;
                }

                createBinary(rollNo);
                printf("Student created successfully\n");
                break;

            case 2:
                readTree();
                break;

            case 3:
                printf("Enter roll number to update: ");

                if (scanf("%d", &rollNo) != 1)
                {
                    while (getchar() != '\n');
                    printf("Invalid roll number\n");
                    break;
                }

                printf("Enter new roll number: ");

                if (scanf("%d", &newRollNo) != 1)
                {
                    while (getchar() != '\n');
                    printf("Invalid roll number\n");
                    break;
                }

                update(rollNo, newRollNo);
                break;

            case 4:
                printf("Enter roll number to delete: ");

                if (scanf("%d", &rollNo) != 1)
                {
                    while (getchar() != '\n');
                    printf("Invalid roll number\n");
                    break;
                }

                deleteNode(rollNo);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 5);

    return 0;
}