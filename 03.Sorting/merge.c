#include <stdio.h>
#include <stdbool.h>

#define N 5

//arr[l ... m] & arr[m + 1 ... r]
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
            arr[i + l] = right[r_ptr++];
            continue;
        }

        if(r_ptr == r_size)
        {
            arr[i + l] = left[l_ptr++];
            continue;
        }

        if(left[l_ptr] < right[r_ptr])
        {
            arr[i + l] = left[l_ptr++];
        }
        else
        {
            arr[i + l] = right[r_ptr++];
        }
    }
}

void sort(int * arr, int l, int r)
{
    if(l == r) return;

    int m = (l + r) / 2;
    sort(arr, l, m);
    sort(arr, m + 1, r);

    merge(arr, l, m, r);
}

int main()
{
    int arr[N] = {1, 5, 4, 3, 2};
    sort(arr, 0, N - 1);

    for(int i = 0 ; i < N ; ++i)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}