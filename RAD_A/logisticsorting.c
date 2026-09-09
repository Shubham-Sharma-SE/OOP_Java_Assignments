#include <stdio.h>
#include <string.h>

struct Package
{
    int packageID;
    char destination[30];
    float distance;
    int deadline;
    float shippingCost;
};

void display(struct Package p[], int n)
{
    int i;

    printf("\nID\tDestination\tDistance\tDeadline\tCost\n");
    printf("------------------------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%s\t\t%.1f km\t\t%d hrs\t\t%.2f\n",
               p[i].packageID,
               p[i].destination,
               p[i].distance,
               p[i].deadline,
               p[i].shippingCost);
    }
}

void emergencySort(struct Package p[], int n)
{
    int i, j;
    struct Package temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j].deadline > p[j + 1].deadline)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void fuelSort(struct Package p[], int n)
{
    int i, j;
    struct Package temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j].distance > p[j + 1].distance)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void revenueSort(struct Package p[], int n)
{
    int i, j;
    struct Package temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j].shippingCost < p[j + 1].shippingCost)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int main()
{
    struct Package packages[5] =
    {
        {101, "Downtown", 15.5, 4, 25.00},
        {102, "North Suburb", 42.0, 12, 85.50},
        {103, "Airport District", 8.2, 2, 15.00},
        {104, "West Valley", 23.1, 6, 45.00},
        {105, "East Pier", 19.8, 3, 60.00}
    };

    struct Package temp[5];
    int i;
    int choice;

    printf("PACKAGE SORTING MODULE\n");

    printf("\n1. Emergency Mode");
    printf("\n2. Fuel-Saving Mode");
    printf("\n3. Revenue Mode");

    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);

    for (i = 0; i < 5; i++)
    {
        temp[i] = packages[i];
    }

    if (choice == 1)
    {
        emergencySort(temp, 5);

        printf("\n--- EMERGENCY DELIVERY SCHEDULE ---\n");
        display(temp, 5);
    }
    else if (choice == 2)
    {
        fuelSort(temp, 5);

        printf("\n--- FUEL-SAVING SCHEDULE ---\n");
        display(temp, 5);
    }
    else if (choice == 3)
    {
        revenueSort(temp, 5);

        printf("\n--- REVENUE SCHEDULE ---\n");
        display(temp, 5);
    }
    else
    {
        printf("\nInvalid choice.");
    }

    return 0;
}