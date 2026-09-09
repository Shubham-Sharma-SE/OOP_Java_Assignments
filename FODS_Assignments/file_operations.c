#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int rollNo;
    char name[30];
};
 struct Student s;
void create(int rollNo, char name[])
{
    FILE *fp;

    fp = fopen("student.txt", "a");

    if (fp == NULL)
    {
        printf("File cannot be opened\n");
        return;
    }

    fprintf(fp, "%d %s\n", rollNo, name);

    fclose(fp);

    printf("Student added\n");
}

void read()
{
    FILE *fp;
    struct Student s;

    fp = fopen("student.txt", "r");

    if (fp == NULL)
    {
        printf("No students found\n");
        return;
    }

    while (fscanf(fp, "%d %s", &s.rollNo, s.name) != EOF)
    {
        printf("Roll No: %d  Name: %s\n", s.rollNo, s.name);
    }

    fclose(fp);
}

void update(int rollNo, char name[])
{
    FILE *fp;
    FILE *temp;
    struct Student s;
    int found = 0;

    fp = fopen("student.txt", "r");
    temp = fopen("temp.txt", "w");

    if (fp == NULL)
    {
        printf("No students found\n");
        return;
    }

    while (fscanf(fp, "%d %s", &s.rollNo, s.name) != EOF)
    {
        if (s.rollNo == rollNo)
        {
            fprintf(temp, "%d %s\n", rollNo, name);
            found = 1;
        }
        else
        {
            fprintf(temp, "%d %s\n", s.rollNo, s.name);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found == 1)
        printf("Student updated\n");
    else
        printf("Student not found\n");
}
/*Made Changes Such that whenever a student with roll number between 101 and 109 is to be deleted, a message is displayed */
void deleteStudent(int rollNo)
{
    FILE *fp;
    FILE *temp;
    struct Student s;
    int found = 0;

    fp = fopen("student.txt", "r");
    temp = fopen("temp.txt", "w");   

    if (fp == NULL)
    {
        printf("No students found\n");
        return;
    }

   


    while (fscanf(fp, "%d %s", &s.rollNo, s.name) != EOF)
    {
        if (s.rollNo == rollNo)
        {
            if(s.rollNo > 100 && s.rollNo < 110)
            {
                printf("rollNo Cannot be deleted");
                return;
            }
           else{ found = 1;}
        }
        else if(s.rollNo == rollNo)
        {

            found = 0;
        }
        else if (s.rollNo != rollNo)
        {
            fprintf(temp, "%d %s\n", s.rollNo, s.name);


        }
        else
        {
            fprintf(temp, "%d %s\n", s.rollNo, s.name);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found == 1)
        printf("Student deleted\n");
    else
        printf("Student not found\n");
}

int main()
{
    int choice;
    int rollNo;
    int newRollNo;
    char name[30];

    do
    {
        printf("\n--- STUDENT RECORD ---\n");
        printf("1. Create\n");
        printf("2. Read\n");
        printf("3. Update\n");
        printf("4. Delete\n");
        printf("5. Exit\n");

        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n');
            printf("Invalid choice\n");
            choice = 0;
            continue;
        }

        switch (choice)
        {
            case 1:
                printf("Enter roll no: ");
                if (scanf("%d", &rollNo) != 1)
                {
                    while (getchar() != '\n');
                    printf("Invalid roll no\n");
                    break;
                }

                printf("Enter name: ");
                scanf("%s", name);

                create(rollNo, name);
                break;

            case 2:
                read();
                break;

            case 3:
                printf("Enter roll no to update: ");

                if (scanf("%d", &rollNo) != 1)
                {
                    while (getchar() != '\n');
                    printf("Invalid roll no\n");
                    break;
                }

                printf("Enter new name: ");
                scanf("%s", name);

                update(rollNo, name);
                break;

            case 4:
                printf("Enter roll no to delete: ");

                if (scanf("%d", &rollNo) != 1)
                {
                    while (getchar() != '\n');
                    printf("Invalid roll no\n");
                    break;
                }

                deleteStudent(rollNo);
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