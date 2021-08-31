#include <stdio.h>

void FIFO(int str[], int frames, int ref)
{
    int i, j, flag, last = -1, page_fault = 0, Frames[frames];

    for (i = 0; i < ref; i++)
    {
        flag = 0;
        for (j = 0; j < frames; j++)
        {
            if (str[i] == Frames[j])
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            last = (last + 1) % frames;
            Frames[last] = str[i];
            page_fault++;
        }
    }

    printf("Final Frames: \n");
    for (int i = 0; i < frames; i++)
    {
        printf("%d ", Frames[i]);
    }
    printf("\nNumber of page faults: %d", page_fault);
}

int main()
{
    int page[] = {7, 2, 3, 1, 2, 5, 3, 4, 6, 7, 7, 1, 0, 5, 4, 6, 2, 3, 0, 1};
    int frames = 3;
    int ref = 20;

    FIFO(page, frames, ref);

    return 0;
}
