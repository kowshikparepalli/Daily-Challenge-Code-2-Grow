#include <stdio.h>
#define MAX_PRODUCTS 20
#define RACK_ROWS 3
#define RACK_COLS 3
void printMenu();
int findProductIndex(int ids[], int count, int id);
void addProduct(int ids[], int qty[], double price[], int *count);
void searchProduct(int ids[], int qty[], double price[], int count);
void updateQuantity(int ids[], int qty[], int count);
void generateRackReport();
void calculateStockValue(int ids[], int qty[], double price[], int count);
void displayAllProducts(int ids[], int qty[], double price[], int count);
int main()
{
    int productId[MAX_PRODUCTS];
    int quantity[MAX_PRODUCTS];
    double price[MAX_PRODUCTS];
    int productCount = 0;
    int choice;
    do
    {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                addProduct(productId, quantity, price, &productCount);
                break;
            case 2:
                searchProduct(productId, quantity, price, productCount);
                break;
            case 3:
                updateQuantity(productId, quantity, productCount);
                break;
            case 4:
                generateRackReport();
                break;
            case 5:
                calculateStockValue(productId, quantity, price, productCount);
                break;
            case 6:
                displayAllProducts(productId, quantity, price, productCount);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    } while (choice != 0);
    return 0;
}
void printMenu()
{
    printf("--- SMART WAREHOUSE MENU ---\n");
    printf("1. Add Product\n");
    printf("2. Search Product (By ID)\n");
    printf("3. Update Quantity\n");
    printf("4. Generate Rack Report (3x3 Matrix)\n");
    printf("5. Calculate Stock Value for Each Product\n");
    printf("6. Display All Products\n");
    printf("0. Exit\n");
}
int findProductIndex(int ids[], int count, int id)
{
    int i;
    for (i = 0; i < count; i++)
    {
        if (ids[i] == id)
        {
            return i;
        }
    }
    return -1;
}
void addProduct(int ids[], int qty[], double price[], int *count)
{
    int id;
    int q;
    double p;
    if (*count >= MAX_PRODUCTS)
    {
        printf("Cannot add more products. Warehouse is full.\n");
        return;
    }
    printf("Enter Product ID: ");
    scanf("%d", &id);
    if (findProductIndex(ids, *count, id) != -1)
    {
        printf("Error: Product ID already exists.\n");
        return;
    }
    printf("Enter Quantity: ");
    scanf("%d", &q);
    printf("Enter Price per unit: ");
    scanf("%lf", &p);
    if (q <= 0 || p <= 0)
    {
        printf("Error: Quantity and price must be positive.\n");
        return;
    }
    ids[*count] = id;
    qty[*count] = q;
    price[*count] = p;
    (*count)++;
    printf("Product added successfully.\n");
}
void searchProduct(int ids[], int qty[], double price[], int count) {
    int id;
    int index;
    if (count == 0)
    {
        printf("No products in warehouse.\n");
        return;
    }
    printf("Enter Product ID to search: ");
    scanf("%d", &id);
    index = findProductIndex(ids, count, id);
    if (index == -1)
    {
        printf("Not Found.\n");
    }
    else
    {
        double stockValue = qty[index] * price[index];
        printf("Product Found:\n");
        printf("ID: %d\n", ids[index]);
        printf("Quantity: %d\n", qty[index]);
        printf("Price: %.2f\n", price[index]);
        printf("Stock Value: %.2f\n", stockValue);
    }
}
void updateQuantity(int ids[], int qty[], int count)
{
    int id;
    int index;
    int option;
    int amount;
    if (count == 0)
    {
        printf("No products in warehouse.\n");
        return;
    }
    printf("Enter Product ID to update quantity: ");
    scanf("%d", &id);
    index = findProductIndex(ids, count, id);
    if (index == -1)
    {
        printf("Product ID not found.\n");
        return;
    }
    printf("Current Quantity: %d\n", qty[index]);
    printf("1. Increase stock\n");
    printf("2. Decrease stock\n");
    printf("Enter option: ");
    scanf("%d", &option);
    if (option == 1)
    {
        printf("Enter amount to increase: ");
        scanf("%d", &amount);
        if (amount <= 0)
        {
            printf("Amount must be positive.\n");
            return;
        }
        qty[index] += amount;
        printf("Quantity updated. New quantity: %d\n", qty[index]);
    } else if (option == 2)
    {
        printf("Enter amount to decrease: ");
        scanf("%d", &amount);
        if (amount <= 0)
        {
            printf("Amount must be positive.\n");
            return;
        }
        if (qty[index] - amount < 0)
        {
            printf("Error: Quantity cannot be negative.\n");
            return;
        }
        qty[index] -= amount;
        printf("Quantity updated. New quantity: %d\n", qty[index]);
    } else
    {
        printf("Invalid option.\n");
    }
}
void generateRackReport()
{
    int rack[RACK_ROWS][RACK_COLS];
    int i, j;
    printf("Enter the 3x3 rack matrix (9 integers):\n");
    for (i = 0; i < RACK_ROWS; i++)
    {
        for (j = 0; j < RACK_COLS; j++)
        {
            scanf("%d", &rack[i][j]);
        }
    }
    int max = rack[0][0];
    int min = rack[0][0];
    int maxRow = 0, maxCol = 0;
    int minRow = 0, minCol = 0;
    int total = 0;
    for (i = 0; i < RACK_ROWS; i++)
    {
        for (j = 0; j < RACK_COLS; j++)
        {
            int value = rack[i][j];
            total += value;
            if (value > max)
            {
                max = value;
                maxRow = i;
                maxCol = j;
            }
            if (value < min)
            {
                min = value;
                minRow = i;
                minCol = j;
            }
        }
    }
    printf("Rack Report:\n");
    printf("Maximum stock: %d at position (row=%d, col=%d)\n", max, maxRow, maxCol);
    printf("Minimum stock: %d at position (row=%d, col=%d)\n", min, minRow, minCol);
    printf("Total items in all racks: %d\n", total);
}
void calculateStockValue(int ids[], int qty[], double price[], int count)
{
    if (count == 0)
    {
        printf("No products in warehouse.\n");
        return;
    }
    double stockValue;
    double maxValue, minValue;
    int maxIndex = 0, minIndex = 0;
    double totalWarehouseValue = 0.0;
    int i;
    maxValue = qty[0] * price[0];
    minValue = maxValue;
    printf("ID\tQuantity\tPrice\t\tStockValue\n");
    for (i = 0; i < count; i++)
    {
        stockValue = qty[i] * price[i];
        printf("%d\t%d\t\t%.2f\t\t%.2f\n", ids[i], qty[i], price[i], stockValue);
        if (stockValue > maxValue)
        {
            maxValue = stockValue;
            maxIndex = i;
        }
        if (stockValue < minValue)
        {
            minValue = stockValue;
            minIndex = i;
        }

        totalWarehouseValue += stockValue;
    }
    printf("\nProduct with HIGHEST stock value:\n");
    printf("ID: %d, StockValue: %.2f\n", ids[maxIndex], maxValue);
    printf("Product with LOWEST stock value:\n");
    printf("ID: %d, StockValue: %.2f\n", ids[minIndex], minValue);
    printf("Total warehouse stock value: %.2f\n", totalWarehouseValue);
}
void displayAllProducts(int ids[], int qty[], double price[], int count)
{
    int i;
    double stockValue;
    if (count == 0)
    {
        printf("No products in warehouse.\n");
    }
        printf("ID\tQuantity\tPrice\t\tStockValue\n");
        for (i = 0; i < count; i++) {
        stockValue = qty[i] * price[i];
        printf("%d\t%d\t\t%.2f\t\t%.2f\n", ids[i], qty[i], price[i], stockValue);
    }
}