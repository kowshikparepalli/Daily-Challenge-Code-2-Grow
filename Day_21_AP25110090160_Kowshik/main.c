#include <stdio.h>
#define MAX 30
void inputData(int id[], int speed[], int lane[], int *count);
int countSpeedViolations(int speed[], int count);
int countLaneViolations(int id[], int lane[], int count);
int busiestLane(int lane[], int count);
int leastBusyLane(int lane[], int count);
void displayReport(int id[], int speed[], int lane[], int count);
int main()
{
    int vehicleID[MAX];
    int speed[MAX];
    int lane[MAX];
    int count = 0;
    int choice;
    do
    {
        printf(" SMART CITY TRAFFIC MONITORING SYSTEM\n");
        printf("1. Input Vehicle Data\n");
        printf("2. Count Speed Violations\n");
        printf("3. Count Lane Violations\n");
        printf("4. Traffic Density Analysis\n");
        printf("5. Display Full Report\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) 
        {
            inputData(vehicleID, speed, lane, &count);
        }
        else if (choice == 2)
        {
            int v = countSpeedViolations(speed, count);
            printf("Total Speed Violations: %d\n", v);
        }
        else if (choice == 3)
        {
            int v = countLaneViolations(vehicleID, lane, count);
            printf("Total Lane Violations: %d\n", v);
        }
        else if (choice == 4)
        {
            int b = busiestLane(lane, count);
            int l = leastBusyLane(lane, count);
            printf("Busiest Lane      : %d\n", b);
            printf("Least Busy Lane   : %d\n", l);
            printf("Total Traffic     : %d vehicles\n", count);
        }
        else if (choice == 5)
        {
            displayReport(vehicleID, speed, lane, count);
        }
        else if (choice == 0)
        {
            printf("Exiting...\n");
        }
        else
        {
            printf("Invalid Option!\n");
        }
    } while (choice != 0);
    return 0;
}
void inputData(int id[], int speed[], int lane[], int *count) {
    int n, i;
    printf("How many vehicles to enter (max 30)? ");
    scanf("%d", &n);
    if (*count + n > MAX)
    {
        printf("Error: Exceeds maximum storage limit.\n");
        return;
    }
    for (i = 0; i < n; i++) 
    {
        printf("\nVehicle %d:\n", *count + 1);
        printf("Enter Vehicle ID (4 digits): ");
        scanf("%d", &id[*count]);
        do {
            printf("Enter Speed: ");
            scanf("%d", &speed[*count]);
            if (speed[*count] <= 0)
                printf("Invalid speed. Try again.\n");
        } while (speed[*count] <= 0);
        do
        {
            printf("Enter Lane (1-4): ");
            scanf("%d", &lane[*count]);
            if (lane[*count] < 1 || lane[*count] > 4)
                printf("Invalid lane. Try again.\n");
        } while (lane[*count] < 1 || lane[*count] > 4);
        (*count)++; 
    }
    printf("\nVehicle data stored successfully!\n");
}
int countSpeedViolations(int speed[], int count)
{
    int i, c = 0;
    int highest = speed[0], lowest = speed[0];
    for (i = 0; i < count; i++)
    {
        if (speed[i] > 80) c++;
        if (speed[i] > highest) highest = speed[i];
        if (speed[i] < lowest)  lowest  = speed[i];
    }
    printf("Highest Speed Recorded : %d\n", highest);
    printf("Lowest Speed Recorded  : %d\n", lowest);
    return c;
}
int countLaneViolations(int id[], int lane[], int count)
{
    int i, c = 0;
    int severity, maxSeverity = -1, badVehicle = 0;
    for (i = 0; i < count; i++)
    {
        int expected = id[i] % 4;
        if (expected == 0) expected = 4;
        if (expected != lane[i])
        {
            c++;
            severity = expected - lane[i];
            if (severity < 0) severity = -severity;

            if (severity > maxSeverity)
            {
                maxSeverity = severity;
                badVehicle = id[i];
            }
        }
    }
    printf("\nWorst Lane Violation:\n");
    printf("Vehicle ID   : %d\n", badVehicle);
    printf("Severity     : %d\n", maxSeverity);
    return c;
}
int busiestLane(int lane[], int count)
{
    int laneCount[4] = {0};
    int i;
    for (i = 0; i < count; i++)
        laneCount[lane[i] - 1]++;
    int max = laneCount[0], idx = 1;
    for (i = 1; i < 4; i++)
    {
        if (laneCount[i] > max)
        {
            max = laneCount[i];
            idx = i + 1;
        }
    }
    return idx;
}
int leastBusyLane(int lane[], int count)
{
    int laneCount[4] = {0};
    int i;
    for (i = 0; i < count; i++)
    laneCount[lane[i] - 1]++;
    int min = laneCount[0], idx = 1;
    for (i = 1; i < 4; i++)
    {
        if (laneCount[i] < min)
        {
            min = laneCount[i];
            idx = i + 1;
        }
    }
    return idx;
}
void displayReport(int id[], int speed[], int lane[], int count)
{
    int i;
    printf("                     TRAFFIC REPORT\n");
    printf("VehID   Speed   Lane   SpeedViol   LaneViol\n");
    for (i = 0; i < count; i++)
    {
        int speedV = (speed[i] > 80) ? 1 : 0;
        int expected = id[i] % 4;
        if (expected == 0) expected = 4;
        int laneV = (expected != lane[i]) ? 1 : 0;
        printf("%-7d %-7d %-6d %-11d %d\n",id[i], speed[i], lane[i] , speedV, laneV);
    }
}
