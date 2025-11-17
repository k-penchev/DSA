#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>

/*

For the implementation I chose to have a struct Node
and a struct called SkipList.

The nodes are dynamiclly allocated, while the pointers
are in static array.

For the level I use 

rand() % MAX_LEVEL , which gives a number between 0 and 14

The complexity is O(log N).

*/

int main()
{
    SkipList list = init();

    insert(&list, 10);
    insert(&list, 1);
    insert(&list, 5);
    insert(&list, 2);

    bool res = search(&list, 5);
    printf("%d\n", res);

    erase(&list, 5);

    bool res2 = search(&list, 5);
    printf("%d\n", res2);


    //clear();

    return 0;
}