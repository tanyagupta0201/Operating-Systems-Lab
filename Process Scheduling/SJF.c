#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, pid[100], at[100], bt[100], ct[100], tat[100], wt[100], f[100], rt[100], st = 0, tot = 0;
    float Avg_WT = 0, Avg_TAT = 0, s1 = 0, s2 = 0;

    printf("Enter the number of process: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the AT of P%d: ", i + 1);
        scanf("%d", &at[i]);

        printf("Enter the BT of P%d: ", i + 1);
        scanf("%d", &bt[i]);

        pid[i] = i + 1;
        f[i] = 0;
    }

    while (true)
    {
        int c = n, min = 999;

        if (tot == n)
            break;

        for (int i = 0; i < n; i++)
        {
            if ((at[i] <= st) && (f[i] == 0) && (bt[i] < min))
            {
                min = bt[i];
                c = i;
            }
        }

        if (c == n)
        {
            st++;
        }
        else
        {
            ct[c] = st + bt[c];
            st = st + bt[c];
            tat[c] = ct[c] - at[c];
            wt[c] = tat[c] - bt[c];
            rt[c] = wt[c]; // Response Time and waiting time are same in non-premetive SJF
            f[c] = 1;
            tot++;
        }
    }

    printf("PID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
    }

    for (int i = 0; i < n; i++)
    {
        s1 = s1 + tat[i];
        s2 = s2 + wt[i];
    }

    Avg_TAT = s1 / n;
    Avg_WT = s2 / n;

    printf("\nAvg Turn Around Time: %f \nAvg Waiting Time: %f ", Avg_TAT, Avg_WT);

    return 0;
}