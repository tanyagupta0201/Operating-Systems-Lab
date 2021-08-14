#include <stdio.h>
#include <stdlib.h>

void FCFS(int a[], int req, int head)
{
    int sum = 0;

    printf("%d", head);

    for (int i = 0; i < req; i++)
    {
        printf(" --> %d ", a[i]);
        sum += abs(a[i] - head);
        head = a[i];
    }

    printf("\nTotal Head Movements: %d\n", sum);
}

int main()
{
    int req, head;

    printf("Enter number of requests: ");
    scanf("%d", &req);

    int a[req];
    printf("Enter the requests: ");
    for (int i = 0; i < req; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the head position: ");
    scanf("%d", &head);

    FCFS(a, req, head);

    return 0;
}