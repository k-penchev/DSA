#include "set.h"
#include <stdio.h>

int main()
{
    Set set1 = init();

    insert(&set1, 10);
    insert(&set1, 5);

    print(&set1);
    destroy(&set1);

    return 0;
}