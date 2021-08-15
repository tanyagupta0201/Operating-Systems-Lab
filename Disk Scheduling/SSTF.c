#include <stdio.h>
#include <stdlib.h>

int main()
{
    int RQ[100], i, n, TotalHeadMoment = 0, head, count = 0;

    printf("Enter the number of Requests: ");
    scanf("%d", &n);

    printf("Enter the Requests sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    // loop will execute until all the processes are completed
    while (count != n)
    {
        int min = 1000, d, index;

        for (i = 0; i < n; i++)
        {
            d = abs(RQ[i] - head);

            if (min > d)
            {
                min = d;
                index = i;
            }
        }

        TotalHeadMoment = TotalHeadMoment + min;
        head = RQ[index];
        RQ[index] = 1000;
        count++;
    }

    printf("\nTotal head movement is %d", TotalHeadMoment);

    return 0;
}