#include <stdio.h>
int main()
{
    char name[50], regNo[20], section[5];
    int i, j, choice,employees, above = 0, below = 0;
    float salary[10], total = 0, avg = 0, highest, lowest;
    printf("Enter Student Name = ");
    scanf("%s",&name);
    printf("Enter Regestration Number = ");
    scanf("%s",&regNo);
    printf("Enter section = ");
    scanf("%s",&section);
    printf("Enter number of employees(max 1 to 10) = ");
    scanf("%d",&employees);
    if(employees <= 0 || employees > 10)
    {
        printf("Invalid numder of employees! please enter between 1 to 10");
    }
    printf("Enter Salary = ");
    for(i = 0; i < employees; i++)
    {
        printf("%d: ", i + 1);
        scanf("%f",&salary[i]);
    }
    do
    {
        printf("\n---Menu---\n");
        printf("1. Display All Salaries \n");
        printf("2. Display Total and Average Salary \n");
        printf("3. Display Highest and Lowest Salary \n");
        printf("4. Count Employees Above and Below Average \n");
        printf("5. Display Sorted Salaries (Ascending) \n");
        printf("6. Exit \n");
        printf("Enter your choice = ");
        scanf("%d",&choice);
        if(choice == 1)
        {
            printf("All Employees Salary = ");
            for (i = 0; i < employees; i++)
            printf("%.2f ", salary[i]);
            printf("\n");
        }
        else if(choice == 2)
        {
            total = 0;
            for (i = 0; i < employees; i++)
            total = total + salary[i];
            avg = total / employees;
            printf("\nTotal Salary = %.2f \n", total);
            printf("Average Salary = %.2f \n", avg);
        }
        else if(choice == 3)
        {
            highest = salary[0];
            lowest = salary[0];
            for (i = 1; i < employees; i++)
            {
                if (salary[i] > highest)
                highest = salary[i];
                if (salary[i] < lowest)
                lowest = salary[i];
            }
            printf("\nHighest Salary = %.2f\n", highest);
            printf("Lowest Salary = %.2f\n", lowest);
        }
        else if(choice == 4)
        {
            total = 0;
            for (i = 0; i < employees; i++)
            total += salary[i];
            avg = total / employees;
            for (i = 0; i < employees; i++)
            {
                if (salary[i] > avg)
                above++;
                else if (salary[i] < avg)
                below++;
            }
            printf("\nAverage Salary = %.2f\n", avg);
            printf("Employees Above Average = %d\n", above);
            printf("Employees Below Average = %d\n", below);
        }
        else if(choice == 5)
        {
            float temp;
            for (i = 0; i < employees - 1; i++)
            {
                for (j = 0; j < employees - i - 1; j++)
                {
                    if (salary[j] > salary[j + 1])
                    {
                        temp = salary[j];
                        salary[j] = salary[j + 1];
                        salary[j + 1] = temp;
                    }
                }
            }
            printf("\nSalaries in Ascending Order =\n");
            for (i = 0; i < employees; i++)
            printf("%.2f ", salary[i]);
            printf("\n"); 
        }
        else if(choice == 6)
        {
            printf("Exiting Program...\n");
        }
        else
        {
            printf("Invalid choice! Please try again.\n");
        }
        printf("\nSubmitted by: %s | Reg No: %s | Section: %s\n", name, regNo, section);
        printf("Challenge Day 17 - Code2Grow Program\n");
    } while (choice != 6);
    return 0;
}
