#include "bst.h"
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

static int checkHeightBalanced(BinaryNode * node)
{
    if(node == NULL)
    {
        return 0;
    }

    int leftHeight = checkHeightBalanced(node->left);
    if(leftHeight == -1)
    {
        return -1;
    }

    int rightHeight = checkHeightBalanced(node->right);
    if(rightHeight == -1)
    {
        return -1;
    }

    int diff = leftHeight - rightHeight;
    if(diff < -1 || diff > 1)
    {
        return -1;
    }

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int isBalanced(BinaryNode * root)
{
    return (checkHeightBalanced(root) != -1) ? 1 : 0;
}

static int countNodes(BinaryNode * node)
{
    if(node == NULL)
    {
        return 0;
    }

    return 1 + countNodes(node->left) + countNodes(node->right);
}

static void storeInOrder(BinaryNode * node, BinaryNode ** arr, int * index)
{
    if(node == NULL)
    {
        return;
    }

    storeInOrder(node->left, arr, index);
    arr[*index] = node;
    (*index)++;
    storeInOrder(node->right, arr, index);
}

static BinaryNode * buildBalanced(BinaryNode ** arr, int low, int high)
{
    if(low > high)
    {
        return NULL;
    }

    int mid = (low + high) / 2;
    BinaryNode * root = arr[mid];

    root->left  = buildBalanced(arr, low, mid - 1);
    root->right = buildBalanced(arr, mid + 1, high);

    int leftHeight  = root->left  ? root->left->height  : 0;
    int rightHeight = root->right ? root->right->height : 0;
    root->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

    return root;
}

BinaryNode * balanceTree(BinaryNode * root)
{
    int n = countNodes(root);
    if(n == 0)
    {
        return NULL;
    }

    BinaryNode ** arr = malloc(n * sizeof(BinaryNode *));
    if(arr == NULL)
    {
        return root;
    }

    int index = 0;
    storeInOrder(root, arr, &index);

    BinaryNode * newRoot = buildBalanced(arr, 0, n - 1);

    free(arr);
    return newRoot;
}
