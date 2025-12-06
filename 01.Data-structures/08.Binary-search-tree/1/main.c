#include "bst.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

int main()
{
    BinaryNode * tree1 = createNode(5);

    insertNode(tree1, 10);
    insertNode(tree1, 20);
    insertNode(tree1, 30);

    BinaryNode * tree2 = createNode(5);

    insertNode(tree2, 1);
    insertNode(tree2, 10);

    printf("%d\n", isBalanced(tree1));
    printf("%d\n", isBalanced(tree2));

    destroy(tree1);
    destroy(tree2);

    return 0;
}