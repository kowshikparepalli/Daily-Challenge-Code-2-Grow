#include <stdio.h>
int main()
{
    int attendance[5][5], marks[5][5], i, j, choice, totalAttend[5] = {0}, totalAbsent[5] = {0}, totalMarks[5] = {0};
    int highestAttend = -1, lowestAttend = 100, highAttendIndex = 0, lowAttendIndex = 0, highestMarks = -1, lowestMarks = 10000;
    int topperIndex = 0, lowMarksIndex = 0;
    float avgMarks[5];
    char names[5][20], grade[5];
    printf("Enter names of 5 students:\n");
    for(i = 0; i < 5; i++)
    {
        printf("Student %d Name = ", i + 1);
        scanf("%s", names[i]);
    }
    printf("Enter Attendance Matrix (1 = Present, 0 = Absent)\n");
    for(i = 0; i < 5; i++)
    {
        printf("Enter attendance for %s (5 subjects) = ", names[i]);
        for (j = 0; j < 5; j++)
        {
            scanf("%d", &attendance[i][j]);
        }
    }
    printf("Enter Marks Matrix (0-100):\n");
    for(i = 0; i < 5; i++)
    {
        printf("Enter marks for %s (5 subjects) = ", names[i]);
        for (j = 0; j < 5; j++)
        {
            scanf("%d", &marks[i][j]);
        }
    }
    for(i = 0; i < 5; i++)
    {
        totalAttend[i] = 0;
        totalMarks[i] = 0;
        for (j = 0; j < 5; j++)
        {
            if(attendance[i][j] == 1)
            totalAttend[i]++;
            else
            totalAbsent[i]++;
            totalMarks[i] += marks[i][j];
        }
        avgMarks[i] = totalMarks[i] / 5.0;
        if(avgMarks[i] >= 90)
        grade[i] = 'A';
        else if(avgMarks[i] >= 80)
        grade[i] = 'B';
        else if(avgMarks[i] >= 70)
        grade[i] = 'C';
        else if(avgMarks[i] >= 60)
        grade[i] = 'D';
        else if(avgMarks[i] >= 50)
        grade[i] = 'E';
        else
        grade[i] = 'F';
        if (totalAttend[i] > highestAttend)
        {
            highestAttend = totalAttend[i];
            highAttendIndex = i;
        }
        if (totalAttend[i] < lowestAttend)
        {
            lowestAttend = totalAttend[i];
            lowAttendIndex = i;
        }
        if (totalMarks[i] > highestMarks)
        {
            highestMarks = totalMarks[i];
            topperIndex = i;
        }
        if (totalMarks[i] < lowestMarks)
        {
            lowestMarks = totalMarks[i];
            lowMarksIndex = i;
        }
    }
    do
    {
        printf("--- MENU ---\n");
        printf("1. Display Attendance Matrix\n");
        printf("2. Display Marks Matrix\n");
        printf("3. Attendance Report\n");
        printf("4. Performance Report\n");
        printf("5. Grade Report\n");
        printf("6. Exit\n");
        printf("Enter your choice = ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Attendance Matrix:\n");
            for (i = 0; i < 5; i++)
            {
                printf("%s: ", names[i]);
                for (j = 0; j < 5; j++)
                printf("%d ", attendance[i][j]);
                printf("\n");
            }
            break;
        case 2:
            printf("Marks Matrix:\n");
            for (i = 0; i < 5; i++)
            {
                printf("%s: ", names[i]);
                for (j = 0; j < 5; j++)
                printf("%d ", marks[i][j]);
                printf("\n");
            }
            break;
        case 3:
            printf("----- Attendance Report -----\n");
            for (i = 0; i < 5; i++)
            {
                printf("%s: Present = %d, Absent = %d\n",names[i], totalAttend[i], totalAbsent[i]);
            }
            printf("Highest Attendance: %s (%d days)\n",names[highAttendIndex], highestAttend);
            printf("Lowest Attendance: %s (%d days)\n",names[lowAttendIndex], lowestAttend);
            break;
        case 4:
            printf("----- Performance Report -----\n");
            for (i = 0; i < 5; i++)
            {
                printf("%s: Total = %d, Average = %.2f\n",names[i], totalMarks[i], avgMarks[i]);
            }
            printf("Class Topper: %s (%d marks)\n",names[topperIndex], highestMarks);
            printf("Lowest Performer: %s (%d marks)\n",names[lowMarksIndex], lowestMarks);
            break;
        case 5:
            printf("----- Grade Report -----\n");
            for (i = 0; i < 5; i++)
            {
                printf("%s: Average = %.2f, Grade = %c\n",names[i], avgMarks[i], grade[i]);
            }
            break;
        case 6:
            printf("Exiting Program...\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while(choice != 6);
}