#include <stdio.h>

void main()
{
    int n, i, at[100], bt[100], ct[100], tat[100], wt[100];
    float TATavg = 0, Twt = 0;

    printf("Enter the number of process: ");
    scanf("%d", &n);

    at[0] = 0;
    bt[0] = 0;
    ct[0] = 0;
    tat[0] = 0;
    wt[0] = 0;

    for (i = 0; i < n; i++)
    {
        printf("Enter the AT of P%d: ", i);
        scanf("%d", &at[i]);

        printf("Enter the BT of P%d: ", i);
        scanf("%d", &bt[i]);

        if (i == 0)
        {
            ct[i] = at[i] + bt[i];
        }
        else
        {
            ct[i] = ct[i - 1] + bt[i];
        }

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("\n");
    printf("PNO\t AT\t BT\t CT\t TAT\t WT\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t %d\t %d\t %d\t %d\t %d", i, at[i], bt[i], ct[i], tat[i], wt[i]);
        printf("\n");
    }

    for (i = 0; i < n; i++)
    {
        TATavg = TATavg + tat[i];
        Twt = Twt + wt[i];
    }

    TATavg = TATavg / n;
    Twt = Twt / n;

    printf("\nAverage TAT time: %f  \nAverage waiting time:  %f ", TATavg, Twt);
}
