#include <stdio.h>

int main()
{
    int AT[20], BT[20], BT1[20], WT[20], TAT[20], CT[20], min, count = 0, n;
    float Avg_WT = 0, Avg_TAT = 0, s1 = 0, s2 = 0, end;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter AT for Process P%d: ", i + 1);
        scanf("%d", &AT[i]);

        printf("Enter BT for Process P%d: ", i + 1);
        scanf("%d", &BT[i]);

        BT1[i] = BT[i];
    }

    for (int time = 0; count != n; time++)
    {
        min = 99;

        for (int i = 0; i < n; i++)
        {
            if (AT[i] <= time && BT[i] < BT[min] && BT[i] > 0)
                min = i;
        }

        BT[min]--;

        if (BT[min] == 0)
        {
            count++;
            end = time + 1;
            CT[min] = end;
            TAT[min] = end - AT[min];
            WT[min] = TAT[min] - BT1[min];
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, AT[i], BT1[i], CT[i], TAT[i], WT[i]);
    }

    for (int i = 0; i < n; i++)
    {
        s1 = s1 + TAT[i];
        s2 = s2 + WT[i];
    }

    Avg_TAT = s1 / n;
    Avg_WT = s2 / n;

    printf("\nAvg Turn Around Time: %f \nAvg Waiting Time: %f ", Avg_TAT, Avg_WT);

    return 0;
}
