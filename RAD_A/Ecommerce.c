#include <stdio.h>

struct Product
{
    int id;
    char name[30];
    char category[20];
    float price;
    float rating;
    int stock;
};

void addProducts(struct Product p[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("\nEnter Product ID: ");
        scanf("%d", &p[i].id);

        printf("Enter Product Name: ");
        scanf("%s", p[i].name);

        printf("Enter Category: ");
        scanf("%s", p[i].category);

        printf("Enter Price: ");
        scanf("%f", &p[i].price);

        printf("Enter Rating: ");
        scanf("%f", &p[i].rating);

        printf("Enter Stock Quantity: ");
        scanf("%d", &p[i].stock);
    }
}

void displayProducts(struct Product p[], int n)
{
    int i;

    printf("\nProduct Details\n");

    for (i = 0; i < n; i++)
    {
        printf("\nID: %d", p[i].id);
        printf("\nName: %s", p[i].name);
        printf("\nCategory: %s", p[i].category);
        printf("\nPrice: %.2f", p[i].price);
        printf("\nRating: %.1f", p[i].rating);
        printf("\nStock: %d\n", p[i].stock);
    }
}

void linearSearch(struct Product p[], int n, int id)
{
    int i;
    int found = 0;

    for (i = 0; i < n; i++)
    {
        if (p[i].id == id)
        {
            printf("\nProduct Found\n");
            printf("ID: %d\n", p[i].id);
            printf("Name: %s\n", p[i].name);
            printf("Category: %s\n", p[i].category);
            printf("Price: %.2f\n", p[i].price);
            printf("Rating: %.1f\n", p[i].rating);
            printf("Stock: %d\n", p[i].stock);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nProduct not found\n");
    }
}

void bubbleSort(struct Product p[], int n)
{
    int i;
    int j;
    struct Product temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j].price > p[j + 1].price)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    printf("\nProducts sorted according to price\n");
}

void binarySearch(struct Product p[], int n, int id)
{
    int low = 0;
    int high = n - 1;
    int mid;
    int found = 0;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (p[mid].id == id)
        {
            printf("\nProduct Found\n");
            printf("ID: %d\n", p[mid].id);
            printf("Name: %s\n", p[mid].name);
            printf("Category: %s\n", p[mid].category);
            printf("Price: %.2f\n", p[mid].price);
            printf("Rating: %.1f\n", p[mid].rating);
            printf("Stock: %d\n", p[mid].stock);

            found = 1;
            break;
        }
        else if (p[mid].id < id)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (found == 0)
    {
        printf("\nProduct not found\n");
    }
}

void cheapestProduct(struct Product p[], int n)
{
    int i;
    int min = 0;

    for (i = 1; i < n; i++)
    {
        if (p[i].price < p[min].price)
        {
            min = i;
        }
    }

    printf("\nCheapest Product\n");
    printf("ID: %d\n", p[min].id);
    printf("Name: %s\n", p[min].name);
    printf("Price: %.2f\n", p[min].price);
}

void expensiveProduct(struct Product p[], int n)
{
    int i;
    int max = 0;

    for (i = 1; i < n; i++)
    {
        if (p[i].price > p[max].price)
        {
            max = i;
        }
    }

    printf("\nMost Expensive Product\n");
    printf("ID: %d\n", p[max].id);
    printf("Name: %s\n", p[max].name);
    printf("Price: %.2f\n", p[max].price);
}

void highestRated(struct Product p[], int n)
{
    int i;
    int max = 0;

    for (i = 1; i < n; i++)
    {
        if (p[i].rating > p[max].rating)
        {
            max = i;
        }
    }

    printf("\nHighest Rated Product\n");
    printf("ID: %d\n", p[max].id);
    printf("Name: %s\n", p[max].name);
    printf("Rating: %.1f\n", p[max].rating);
}

void topFive(struct Product p[], int n)
{
    int i;
    int j;
    struct Product temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j].price < p[j + 1].price)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    printf("\nTop 5 Highest-Priced Products\n");

    if (n < 5)
    {
        for (i = 0; i < n; i++)
        {
            printf("\nID: %d", p[i].id);
            printf("\nName: %s", p[i].name);
            printf("\nPrice: %.2f\n", p[i].price);
        }
    }
    else
    {
        for (i = 0; i < 5; i++)
        {
            printf("\nID: %d", p[i].id);
            printf("\nName: %s", p[i].name);
            printf("\nPrice: %.2f\n", p[i].price);
        }
    }
}

void priceRange(struct Product p[], int n, float minPrice, float maxPrice)
{
    int i;
    int found = 0;

    printf("\nProducts in Price Range\n");

    for (i = 0; i < n; i++)
    {
        if (p[i].price >= minPrice && p[i].price <= maxPrice)
        {
            printf("\nID: %d", p[i].id);
            printf("\nName: %s", p[i].name);
            printf("\nPrice: %.2f\n", p[i].price);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\nNo product found in this price range\n");
    }
}

int main()
{
    struct Product p[100];
    int n;
    int choice;
    int id;
    float minPrice;
    float maxPrice;

    printf("Enter number of products: ");
    scanf("%d", &n);

    addProducts(p, n);

    do
    {
        printf("\n");
        printf("1. Display Products\n");
        printf("2. Linear Search\n");
        printf("3. Sort According to Price\n");
        printf("4. Binary Search\n");
        printf("5. Cheapest Product\n");
        printf("6. Most Expensive Product\n");
        printf("7. Highest Rated Product\n");
        printf("8. Top 5 Highest-Priced Products\n");
        printf("9. Price Range Search\n");
        printf("10. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                displayProducts(p, n);
                break;

            case 2:
                printf("Enter Product ID: ");
                scanf("%d", &id);

                linearSearch(p, n, id);
                break;

            case 3:
                bubbleSort(p, n);
                break;

            case 4:
                printf("Enter Product ID: ");
                scanf("%d", &id);

                binarySearch(p, n, id);
                break;

            case 5:
                cheapestProduct(p, n);
                break;

            case 6:
                expensiveProduct(p, n);
                break;

            case 7:
                highestRated(p, n);
                break;

            case 8:
                topFive(p, n);
                break;

            case 9:
                printf("Enter minimum price: ");
                scanf("%f", &minPrice);

                printf("Enter maximum price: ");
                scanf("%f", &maxPrice);

                priceRange(p, n, minPrice, maxPrice);
                break;

            case 10:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 10);

    return 0;
}