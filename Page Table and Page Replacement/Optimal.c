#include <stdio.h>

int maximum(int arr[], int n)
{
    int i, m = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] > arr[m])
            m = i;
    }
    return m;
}

void Optimal(int str[], int nframes, int nref)
{
    int i, frames[nframes], page_faults = 0, full = 0, j, flag, freq[nframes], optimal, k;

    for (i = 0; i < nref; i++)
    {
        if (full < nframes)
        {
            frames[full] = str[i];
            full++;
            page_faults++;
        }
        else
        {
            flag = 0;

            for (j = 0; j < nframes; j++)
            {
                if (str[i] == frames[j])
                {
                    flag = 1;
                }
            }

            if (flag == 0)
            {
                for (j = 0; j < nframes; j++)
                {
                    int f = 0;
                    for (k = i; k < nref; k++)
                    {
                        if (str[k] == frames[j])
                        {
                            freq[j] = k;
                            f = 1;
                            break;
                        }
                    }

                    if (f == 0)
                        freq[j] = 100;
                }

                optimal = maximum(freq, nframes);
                frames[optimal] = str[i];
                page_faults++;
            }
        }
    }

    printf("Final Frames: \n");
    for (i = 0; i < nframes; i++)
    {
        printf("%d ", frames[i]);
    }
    printf("\nNumber of page faults: %d", page_faults);
}

int main()
{
    int page[] = {7, 2, 3, 1, 2, 5, 3, 4, 6, 7, 7, 1, 0, 5, 4, 6, 2, 3, 0, 1};
    int nref = 20;
    int nframes = 3;

    Optimal(page, nframes, nref);

    return 0;
}
