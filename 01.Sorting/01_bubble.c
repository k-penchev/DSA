#include <stdio.h>
#include <stdbool.h>

#define N 5

void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int * arr, int size)
{
    for(int i = 0 ; i < size - 1 ; ++i)
    {
        bool swapped = false;
        for(int j = 0 ; j < size - i - 1 ; ++j)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if(!swapped) break;
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