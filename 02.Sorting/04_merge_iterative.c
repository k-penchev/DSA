#include <stdio.h>
#include <stdlib.h>

#define N 5

int min(int a, int b)
{
    return (a <= b ? a : b);
}

void merge(int * arr, int l, int m, int r)
{
    int l_size = m - l + 1;
    int r_size = r - m;

    int left[l_size], right[r_size];

    for(int i = 0 ; i < l_size ; ++i)
    {
        left[i] = arr[i + l];
    }

    for(int i = 0 ; i < r_size ; ++i)
    {
        right[i] = arr[i + m + 1];
    }

    int l_ptr = 0, r_ptr = 0;

    for(int i = 0 ; i < l_size + r_size ; ++i)
    {
        if(l_ptr == l_size)
        {
            arr[l + i] = right[r_ptr++];
            continue;
        }

        if(r_ptr == r_size)
        {
            arr[l + i] = left[l_ptr++];
            continue;
        }

        if(left[l_ptr] < right[r_ptr])
        {
            arr[l + i] = left[l_ptr++];
        }
        else
        {
            arr[l + i] = right[r_ptr++];
        }
    }
}

void sort(int * arr, int arr_size)
{
    for(int size = 1 ; size <= arr_size - 1; size <<= 1) 
    {
        printf("%d\n", size);
        for(int l = 0 ; l < arr_size - 1 ; l += 2 * size)
        {
            int m = min(l + size - 1, arr_size - 1);
            int r = min(l + 2 * size - 1, arr_size - 1);

            printf("%d, %d, %d\n", l, m, r);
            merge(arr, l, m, r);
        }
    }
}

int main()
{
    int arr[N] = {1, 5, 4, 3, 2};
    sort(arr, N);

    for(int i = 0 ; i < N ; ++i)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}