// Producer Consumer Problem

#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty = 10, x = 0;

int wait(int s)
{
    return (--s);
}

int signal(int s)
{
    return (++s);
}

// Function to produce an item and add it to the buffer
void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("\nProducer produces the item %d\n", x);
    mutex = signal(mutex);
}

// Function to consume an item and remove it from the buffer
void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\nConsumer consumes item %d\n", x);
    x--;
    mutex = signal(mutex);
}

int main()
{
    int ch;
    printf("\n1.Producer\n2.Consumer\n3.Exit\n");

    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if ((mutex == 1) && (empty != 0))
                producer();
            else
                printf("Buffer is full !!\n");
            break;

        case 2:
            if ((mutex == 1) && (full != 0))
                consumer();
            else
                printf("Buffer is empty !!\n");
            break;

        default:
            printf("Wrong choice entered !!");
            exit(0);
            break;
        }
    }

    return 0;
}