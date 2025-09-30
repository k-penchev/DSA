#include <stdio.h>
#include <stdbool.h>

#define N 5

int binary(int * arr, int size, int k)
{
    int l = -1, r = size;

    while(l < r - 1)
    {
        int m = (l + r) / 2;

        if(arr[m] > k) r = m;
        else l = m;
    }

    return r;
}

void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int * arr, int size)
{
    for(int i = 1; i < size; ++i)
    {
        int key = arr[i];
        int idx = binary(arr, i, key);

        // Shift elements to the right to make space for key
        for(int j = i; j > idx; --j)
        {
            arr[j] = arr[j - 1];
        }
        arr[idx] = key;
    }

    for(int i = 0 ; i < size ; ++i)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    int arr[N] = {1, 5, 4, 3, 2};
    sort(arr, N);

    return 0;
}