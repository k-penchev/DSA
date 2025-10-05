#include <stdio.h>
#include <stdbool.h>

#define N 5

void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int * arr, int size, int * comparisons_cnt, int * swaps_cnt)
{
    for(int i = 0 ; i < size - 1 ; ++i)
    {
        bool swapped = false;
        for(int j = 0 ; j < size - i - 1 ; ++j)
        {
            *comparisons_cnt += 1;
            if(arr[j] > arr[j + 1])
            {
                *swaps_cnt += 1;
                swapped = true;
                swap(&arr[j], &arr[j + 1]);
            }
        }

        if(!swapped) break;
    }

}

int partition(int * arr, int l, int r, int * comparisons_cnt, int * swaps_cnt)
{
    int pivot = arr[r];

    int ptr1 = l - 1, ptr2 = l;

    for(; ptr2 <= r - 1 ; ++ptr2)
    {
        *comparisons_cnt += 1;
        if(arr[ptr2] <= pivot)
        {
            *swaps_cnt += 1;
            ptr1++;
            swap(&arr[ptr1], &arr[ptr2]);
        }
    }

    *swaps_cnt += 1;
    swap(&arr[ptr1 + 1], &arr[r]);
    return ptr1 + 1;
}

void quick_sort(int * arr, int l, int r, int * comparisons_cnt, int * swaps_cnt)
{
    if(l >= r) return;

    int idx = partition(arr, l, r, comparisons_cnt, swaps_cnt);

    quick_sort(arr, l, idx - 1, comparisons_cnt, swaps_cnt);
    quick_sort(arr, idx + 1, r, comparisons_cnt, swaps_cnt);
}

int main()
{
    int bubble_comps = 0, bubble_swaps = 0;
    int arr1[N] = {1, 5, 4, 3, 2};
    bubble_sort(arr1, N, &bubble_comps, &bubble_swaps);

    printf("Bubble sort : \n");
    printf("-> Comparisons : %d\n", bubble_comps);
    printf("-> Swaps : %d\n", bubble_swaps);
    printf("\n");



    int quick_comps = 0, quick_swaps = 0;
    int arr2[N] = {1, 5, 4, 3, 2};
    quick_sort(arr2, 0, N - 1, &quick_comps, &quick_swaps);

    printf("Quick sort : \n");
    printf("-> Comparisons : %d\n", quick_comps);
    printf("-> Swaps : %d\n", quick_swaps);
    printf("\n");


    /*
    For sorted array {1, 2, 3, 4, 5}:

    Bubble sort :
    -> Comparisons : 4
    -> Swaps : 0

    Quick sort :
    -> Comparisons : 10
    -> Swaps : 14
    */

    /*
    For reversed array {5, 4, 3, 2, 1}:

    Bubble sort :
    -> Comparisons : 10
    -> Swaps : 10

    Quick sort :
    -> Comparisons : 10
    -> Swaps : 8
    */

    return 0;
}