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
    for(int i = 0 ; i < size ; ++i)
    {
        int * current = &arr[i];
        int * min_to_the_right = &arr[i];

        for(int j = i + 1 ; j < size ; ++j)
        {
            if(arr[j] < *min_to_the_right)
            {
                min_to_the_right = &arr[j];
            }
        }

        swap(current, min_to_the_right);
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