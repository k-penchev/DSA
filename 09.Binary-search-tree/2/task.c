#include "bst.h"
#include <stdlib.h>
#include <limits.h>

static int maxInt(int a, int b)
{
    return (a > b) ? a : b;
}

static BinaryNode * buildPreOrderUtil(const BinaryNodeType * arr, int n, int * index, BinaryNodeType min, BinaryNodeType max)
{
    if(*index >= n)
    {
        return NULL;
    }

    BinaryNodeType value = arr[*index];
    if(value <= min || value >= max)
    {
        return NULL;
    }

    BinaryNode * root = createNode(value);
    (*index)++;

    root->left = buildPreOrderUtil(arr, n, index, min, value);
    root->right = buildPreOrderUtil(arr, n, index, value, max);

    int lh = root->left ? root->left->height : 0;
    int rh = root->right ? root->right->height : 0;
    root->height = maxInt(lh, rh) + 1;

    return root;
}

BinaryNode * buildFromPreOrder(const BinaryNodeType * arr, int n)
{
    if(n <= 0)
    {
        return NULL;
    }

    int index = 0;
    return buildPreOrderUtil(arr, n, &index, INT_MIN, INT_MAX);
}

static BinaryNode * buildInOrderUtil(const BinaryNodeType * arr, int low, int high)
{
    if(low > high)
    {
        return NULL;
    }

    int mid = (low + high) / 2;
    BinaryNode * root = createNode(arr[mid]);

    root->left = buildInOrderUtil(arr, low, mid - 1);
    root->right = buildInOrderUtil(arr, mid + 1, high);

    int lh = root->left ? root->left->height : 0;
    int rh = root->right ? root->right->height : 0;
    root->height = maxInt(lh, rh) + 1;

    return root;
}

BinaryNode * buildFromInOrder(const BinaryNodeType * arr, int n)
{
    if(n <= 0)
    {
        return NULL;
    }

    return buildInOrderUtil(arr, 0, n - 1);
}


BinaryNode * buildFromPostOrder(const BinaryNodeType * arr, int n)
{
    
}
