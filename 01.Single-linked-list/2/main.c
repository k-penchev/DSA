#include "single_list.h"
#include <stdio.h>

int main()
{
    Node * head = NULL;
    pushBack(&head, 5);
    print(&head);
    pushBack(&head, 6);
    print(&head);
    pushBack(&head, 7);
    print(&head);

    popBack(&head);
    print(&head);
    popBack(&head);
    print(&head);

    //destroy(&head);

    return 0;
}