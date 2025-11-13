#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 8

void swap(int * x, int * y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

bool isOrdered(int * arr, unsigned int count)
{
    for(int i = 0 ; i < count ; ++i)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if(l < count)
        {
            if(arr[i] < arr[l])
            {
                return false;
            }
        }

        if(r < count)
        {
            if(arr[i] < arr[r])
            {
                return false;
            }
        }
    }

    return true;
}

void heapify(int* arr, unsigned int count)
{
    while(true)
    {
        if(isOrdered(arr, count)) break;

        for(int i = 0 ; i < count ; ++i)
        {
            int l = 2 * i + 1;
            int r = 2 * i + 2;

            if(l < count)
            {
                if(arr[i] < arr[l])
                {
                    swap(&arr[i], &arr[l]);
                }
            }

            if(r < count)
            {
                if(arr[i] < arr[r])
                {
                    swap(&arr[i], &arr[r]);
                }
            }
        }
    }
}


void siftUp(int* arr, unsigned int pos)
{
    swap(&arr[0], &arr[pos]);

    int i = 0;
    while(true)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        int largest = i;

        if(l < pos && arr[l] > arr[largest])
        {
            largest = l;
        }

        if(r < pos && arr[r] > arr[largest])
        {
            largest = r;
        }

        if(largest == i) break;

        swap(&arr[i], &arr[largest]);
        i = largest;
    }
}

void heapsort(int* arr, unsigned int count)
{
    heapify(arr, count);

    for(int i = count - 1 ; i >= 0 ; --i)
    {
        siftUp(arr, i);
    }
}

int main()
{
    int arr[N] = {5, 24, 7, 2, 30, 17, 22, 25};
    
    heapsort(arr, N);

    for(int i = 0 ; i < N ; ++i)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}

/*
    The total complexity of my algorithm should be O(N log N) :).

    We do O(N) loop of the whole array and on each iteration we do O(log N)
    operations for siftUp.
*/