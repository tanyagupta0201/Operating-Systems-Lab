#include <stdio.h>
#include <stdlib.h>
#define n 10

int main()
{
    int r, p, process, count = 0, i, j;
    int Max_Need[n][n], allocation[n][n], Rem_Need[n][n], available[n], completed[n], safe[n];

    printf("Enter the number of processes: ");
    scanf("%d", &p);

    printf("Enter the number of resources: ");
    scanf("%d", &r);

    for (i = 0; i < p; i++)
    {
        completed[i] = 0;
    }

    // Resources allocated
    printf("\nEnter the allocation for each process:\n");
    for (i = 0; i < p; i++)
    {
        printf("For process %d : ", i + 1);
        for (j = 0; j < r; j++)
            scanf("%d", &allocation[i][j]);
    }

    // Maximum Resources that can be allocated
    printf("\nEnter the Max Need Matrix for each process:\n");
    for (i = 0; i < p; i++)
    {
        printf("For process %d : ", i + 1);
        for (j = 0; j < r; j++)
            scanf("%d", &Max_Need[i][j]);
    }

    // Available Instances
    printf("\nEnter the Current Available Resources: ");
    for (i = 0; i < r; i++)
        scanf("%d", &available[i]);

    // Calculating Need Matrix
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            Rem_Need[i][j] = Max_Need[i][j] - allocation[i][j];
        }
    }

    do
    {
        printf("\n MAXIMUM DEMAND\t\tALLOCATION MATRIX\t\tREMAINING NEED MATRIX\n");
        for (i = 0; i < p; i++)
        {
            for (j = 0; j < r; j++)
            {
                printf(" %d ", Max_Need[i][j]);
            }
            printf("\t\t\t");

            for (j = 0; j < r; j++)
            {
                printf(" %d ", allocation[i][j]);
            }
            printf("\t\t\t");

            for (j = 0; j < r; j++)
            {
                printf(" %d ", Rem_Need[i][j]);
            }
            printf("\t\t\t");
            printf("\n");
        }

        process = -1; // No process is not yet completed
        for (i = 0; i < p; i++)
        {
            // If the process is not completed
            if (completed[i] == 0)
            {
                process = i;
                for (j = 0; j < r; j++)
                {
                    if (available[j] < Rem_Need[i][j])
                    {
                        process = -1;
                        break;
                    }
                }
            }
            if (process != -1)
                break;
        }

        if (process != -1)
        {
            printf("\nProcess %d runs to the completion \n\n", (process + 1));
            safe[count] = process + 1;
            count++;
            for (j = 0; j < r; j++)
            {
                available[j] = available[j] + allocation[process][j];
                allocation[process][j] = 0;
                // Since the process has been completed it doesn't require maxNeed and RemainingNeed
                Max_Need[process][j] = 0;
                Rem_Need[process][j] = 0;
                completed[process] = 1;
            }

            printf("New Availability of resource: ");
            for (j = 0; j < r; j++)
            {
                printf(" %d", available[j]);
            }
            printf("\n");
        }
    } while (count != p && process != -1);

    if (count == p)
    {
        printf("\nThe system is in SAFE STATE !!\n");
        printf("\n The Safe Sequence is: ");
        for (i = 0; i < p; i++)
        {
            printf(" P%d -->", safe[i]);
        }
    }
    else
    {
        printf("\nThe system is in UNSAFE STATE !!\n");
    }

    return 0;
}