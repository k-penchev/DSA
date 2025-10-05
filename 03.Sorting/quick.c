#include <stdio.h>

#define N 5

void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//arr[l ... r]
int partition(int * arr, int l, int r)
{
    int pivot = arr[r];

    int ptr1 = l - 1, ptr2 = l;

    for(; ptr2 <= r - 1 ; ++ptr2)
    {
        if(arr[ptr2] <= pivot)
        {
            ptr1++;
            swap(&arr[ptr1], &arr[ptr2]);
        }
    }

    swap(&arr[ptr1 + 1], &arr[r]);
    return ptr1 + 1;
}

void sort(int * arr, int l, int r)
{
    if(l >= r) return;

    int idx = partition(arr, l, r);

    sort(arr, l, idx - 1);
    sort(arr, idx + 1, r);
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