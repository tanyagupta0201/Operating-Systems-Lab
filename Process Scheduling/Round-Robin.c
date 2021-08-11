#include <stdio.h>

int test(int finish[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (finish[i] == 0)
            return 0;
    }
    return 1;
}

int main()
{
    printf("\n\n----------ROUND ROBIN CPU SCHEDULING----------\n\n");

    int n, i = 0, time_quantum, curr_time = 0;
    float x = 0, y = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int AT[n], BT[n], CT[n], TAT[n], WT[n], RBT[n], finish[n];

    for (i = 0; i < n; i++)
        finish[i] = 0;

    printf("Enter the Arrival Time for the processes: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &AT[i]);
    }

    printf("Enter the Burst Time for the processes: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &BT[i]);
        RBT[i] = BT[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &time_quantum);
    printf("\n");

    i = 0;
    while (test(finish, n) != 1)
    {
        if (RBT[i] >= time_quantum)
        {
            curr_time = curr_time + time_quantum;
            RBT[i] = RBT[i] - time_quantum;

            if (RBT[i] == 0)
            {
                CT[i] = curr_time;
                finish[i] = 1;
            }
        }
        else
        {
            if (finish[i] != 1)
            {
                curr_time = curr_time + RBT[i];
                CT[i] = curr_time;
                finish[i] = 1;
            }
        }
        i = (i + 1) % n;
    }

    for (i = 0; i < n; i++)
    {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
        x = x + TAT[i];
        y = y + WT[i];
    }

    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
    {
        printf(" P%d\t%d\t%d\t%d\t%d\t%d \n", i, AT[i], BT[i], CT[i], TAT[i], WT[i]);
    }

    printf("\nAverage Turn Around Time: %f", x / n);
    printf("\nAverage Waiting Time: %f\n", y / n);

    return 0;
}
