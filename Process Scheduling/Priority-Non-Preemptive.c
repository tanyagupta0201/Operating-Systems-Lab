#include <stdio.h>
#define max 30

int main()
{
    int n, i, j, k = 1, t, b = 0, min, temp[max], at[max], bt[max], wt[max], tat[max], pr[max];
    float awt = 0, atat = 0;

    printf("Enter the number of process: ");
    scanf("%d", &n);

    printf("Enter the Arrival Time, Burst Time and Priority of the process: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (at[i] < at[j])
            {
                t = at[j];
                at[j] = at[i];
                at[i] = t;

                t = bt[j];
                bt[j] = bt[i];
                bt[i] = t;
            }
        }
    }

    for (int j = 0; i < n; j++)
    {
        b = b + bt[i];
        min = bt[k];

        for (int i = k; i < n; i++)
        {
            min = pr[k];

            if (b >= at[i])
            {
                if (pr[i] < min)
                {
                    t = at[k];
                    at[k] = at[i];
                    at[i] = t;

                    t = bt[k];
                    bt[k] = bt[i];
                    bt[i] = t;

                    t = pr[k];
                    pr[k] = pr[i];
                    pr[i] = t;
                }
            }
            k++;
        }
    }

    temp[0] = 0;

    printf("\nPID\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurn Around Time\n");
    for (int i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        temp[i + 1] = temp[i] + bt[i];
        wt[i] = temp[i] - at[i];
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, at[i], bt[i], pr[i], wt[i], tat[i]);
    }

    awt = awt / n;
    atat = atat / n;
    printf("\n");

    printf("Average Waiting Time = %f\n", awt);
    printf("Average Turn Around Time = %f\n", atat);

    return 0;
}
