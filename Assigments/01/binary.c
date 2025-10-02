#include <stdio.h>

#define N 5

int binary(int * arr, int size, int k)
{
    //printf("%d\n", size);
    if(size == 1)
    {
        return arr[size] == k;
    }

    int m = size / 2;
    if(arr[m] == k) return 1;

    if(arr[m] > k) 
    {
        binary(arr, m - 1, k); //left
    }
    else 
    {
        binary(arr + m, m, k); //right
    }
}

int main()
{
    int arr[N] = {1, 10, 20, 30, 100};

    //0 -> not found , 1 -> found
    printf("%d\n", binary(arr, 5, 2)); 
    printf("%d\n", binary(arr, 5, 10));
    printf("%d\n", binary(arr, 5, 30));
    printf("%d\n", binary(arr, 5, 50));

    return 0;
}