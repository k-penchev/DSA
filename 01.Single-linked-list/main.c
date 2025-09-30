#include "list.h"
#include <stdio.h>

void print(LinkedList * list)
{
    Node * current = list->head;

    for(int i = 0 ; i < list->size ; ++i)
    {
        printf("%d\n", current->value);
        current = current->next;
    }

    printf("\n");
}

int main()
{
    LinkedList list = init();

    pushBack(&list, 5);
    pushBack(&list, 6);
    pushBack(&list, 7);
    print(&list);

    popBack(&list);
    print(&list);

    destroy(&list);

    return 0;
}