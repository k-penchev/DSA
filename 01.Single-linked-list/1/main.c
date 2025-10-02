#include "list.h"
#include <stdio.h>

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