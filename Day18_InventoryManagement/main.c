#include <stdio.h>
int main()
{
    int productID[10], quantity[10], n, i, j, choice, searchID, highIndex = 0, lowIndex = 0;
    float price[10], value[10], totalValue = 0, highestValue, lowestValue;
    char name[10][50];
    printf("Enter number of products (max 10): ");
    scanf("%d", &n);
if (n <= 0 || n > 10)
    {
        printf("Invalid number of products! Please enter between 1 to 10 = \n");
        return 0;
    }
    // Input product details
    printf("\nEnter Product Details = \n");
    for (i = 0; i < n; i++)
    {
        printf("\nProduct %d = \n", i + 1);
        printf("Enter Product ID =  ");
        scanf("%d", &productID[i]);
        printf("Enter Product Name = ");
        scanf("%s", name[i]);
        printf("Enter Quantity in Stock = ");
        scanf("%d", &quantity[i]);
        printf("Enter Price per Item = ");
        scanf("%f", &price[i]);
        value[i] = quantity[i] * price[i];
    }
    do
    {
        printf("\n---MENU---\n");
        printf("1. Display All Products\n");
        printf("2. Display Total Inventory Value\n");
        printf("3. Display Highest and Lowest Value Products\n");
        printf("4. Search Product by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
    if (choice == 1)
        {
            printf("\nProduct List:\n");
            printf("ID\tName\tQuantity\tPrice\t\tValue\n");
            for (i = 0; i < n; i++)
            {
                printf("%d\t%s\t%d\t\t%.2f\t\t%.2f\n", productID[i], name[i], quantity[i], price[i], value[i]);
            }
        }
        else if (choice == 2)
        {
            totalValue = 0;
            for (i = 0; i < n; i++)
                totalValue += value[i];
            printf("\nTotal Inventory Value = %.2f\n", totalValue);
        }
        else if (choice == 3)
        {
            highestValue = value[0];
            lowestValue = value[0];
            highIndex = 0;
            lowIndex = 0;

            for (i = 1; i < n; i++)
            {
                if (value[i] > highestValue)
                {
                    highestValue = value[i];
                    highIndex = i;
                }
                if (value[i] < lowestValue)
                {
                    lowestValue = value[i];
                    lowIndex = i;
                }
            }

            printf("\nProduct with Highest Value = \n");
            printf("ID = %d | Name = %s | Value = %.2f\n", productID[highIndex], name[highIndex], highestValue);

            printf("\nProduct with Lowest Value = \n");
            printf("ID = %d | Name = %s | Value = %.2f\n", productID[lowIndex], name[lowIndex], lowestValue);
        }
        else if (choice == 4)
        {
            int found = 0;
            printf("\nEnter Product ID to Search = ");
            scanf("%d", &searchID);

            for (i = 0; i < n; i++)
            {
                if (productID[i] == searchID)
                {
                    printf("\nProduct Found:\n");
                    printf("ID: %d | Name =  %s | Quantity = %d | Price = %.2f | Value  =%.2f\n",
                           productID[i], name[i], quantity[i], price[i], value[i]);
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Product with ID %d not found!\n", searchID);
        }
        else if (choice == 5)
        {
            printf("\nExiting Program...\n");
        }
        else
        {
            printf("Invalid Choice! Please try again.\n");
        }

    } while (choice != 5);
    printf("\nProgram Completed Successfully!\n");
    printf("Submitted by: P. Kowshik\n");
    printf("Reg No: AP123456789\n");
    printf("Challenge Day 18 Code2Grow Program\n");
    return 0;
}
