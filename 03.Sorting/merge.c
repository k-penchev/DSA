#include <stdio.h>
#include <stdbool.h>

#define N 5

void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge()
{

}

void sort(int * arr, int size, int l, int r)
{
    if(l == r) return;

    //left
    sort(arr, );
    
    //right
    sort(arr);

    merge();
}

int main()
{
    int arr[N] = {1, 5, 4, 3, 2};
    sort(arr, N, 0, N - 1);

    return 0;
}