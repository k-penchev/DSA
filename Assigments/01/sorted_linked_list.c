#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../01.Single-linked-list/01/list.h"

void swap_nodes(LinkedList * list, int x, int y)
{
    //x and y are consecutive

    if(x == 0)
    {
        Node * x_node = list->head;
        Node * y_node = x_node ? x_node->next : NULL;

        if(x_node == NULL || y_node == NULL) return;

        x_node->next = y_node->next;
        y_node->next = x_node;
        list->head = y_node;

        return;
    }

    Node * x_node_prev = getNode(list, x - 1);
    Node * x_node = x_node_prev ? x_node_prev->next : NULL;
    Node * y_node = getNode(list, y);

    if(x_node == NULL || y_node == NULL) return;

    x_node_prev->next = y_node;
    x_node->next = y_node->next;
    y_node->next = x_node;
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

bool is_greater(LinkedList * list, int x, int y)
{
    return *getNodeValue(list, x) > *getNodeValue(list, y);
}

void sort(LinkedList * list, bool type)
{
    int n_elements = list->size;
    for(int i = 0 ; i < n_elements - 1 ; ++i)
    {
        bool swapped = false;
        for(int j = 0 ; j < n_elements - i - 1 ; ++j)
        {
            if(is_greater(list, j, j + 1))
            {
                swap(list, j, j + 1, type);
                swapped = true;
            }
        }

        if(!swapped) break;
    }
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
    sort(&list, 0); //0/1

    print(&list);
    destroy(&list);

    return 0;
}