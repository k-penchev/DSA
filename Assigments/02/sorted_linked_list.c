#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

void swap_nodes(LinkedList * list, int x, int y)
{
    if(x == y) return;

    if(x > y)
    {
        int t = x;
        x = y;
        y = t;
    }

    Node * prevX = NULL;
    if(x > 0) prevX = getNode(list, x - 1);
    Node * currX = getNode(list, x);

    Node * prevY = NULL;
    if(y > 0) prevY = getNode(list, y - 1);
    Node * currY = getNode(list, y);

    if(prevY == currX)
    {
        if(prevX)
        {
            prevX->next = currY; 
        }
        else 
        {
            list->head = currY;
        }

        Node * nextY = currY->next;
        currY->next = currX;
        currX->next = nextY;

        return;
    }

    if(prevX) 
    {
        prevX->next = currY;
    }
    else 
    {
        list->head = currY;
    }

    if(prevY) 
    {
        prevY->next = currX; 
    }
    else 
    {
        list->head = currX;
    }

    Node * tmp = currY->next;
    currY->next = currX->next;
    currX->next = tmp;
}

void swap_values(int * x, int * y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swap(LinkedList * list, int x, int y, int swap_type)
{
    if(swap_type == 0)
    {
        swap_values(getNodeValue(list, x), getNodeValue(list, y));
    }
    else
    {
        swap_nodes(list, x, y);
    }
}

int partition(LinkedList * list, int l, int r, bool type)
{
    int pivot = *getNodeValue(list, r);

    int ptr1 = l - 1, ptr2 = l;

    for(; ptr2 <= r - 1 ; ++ptr2)
    {
        int current = *getNodeValue(list, ptr2);
        if(current <= pivot)
        {
            ptr1++;
            swap(list, ptr1, ptr2, type);
        }
    }

    swap(list, ptr1 + 1, r, type);
    return ptr1 + 1;
}

void quick_sort(LinkedList * list, int l, int r, bool type)
{
    if(l >= r) return;

    int idx = partition(list, l, r, type);

    quick_sort(list, l, idx - 1, type);
    quick_sort(list, idx + 1, r, type);
}

int main()
{
    LinkedList list = init();

    pushBack(&list, 5);
    pushBack(&list, 1);
    pushBack(&list, 4);
    pushBack(&list, 3);
    pushBack(&list, 2);

    //0 -> swap values, 1 -> swap nodes
    quick_sort(&list, 0, list.size - 1, 1);
    //sort(&list, 0, list.size - 1, 1);

    print(&list);
    destroy(&list);

    return 0;
}
