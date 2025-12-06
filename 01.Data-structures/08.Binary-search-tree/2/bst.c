#include "bst.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

static int nodeHeight(BinaryNode * node)
{
    return node ? node->height : 0;
}

BinaryNode * createNode(BinaryNodeType value)
{
    BinaryNode * newNode = malloc(sizeof(BinaryNode));
    assert(newNode != NULL);

    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;

    return newNode;
}

BinaryNode * searchNode(BinaryNode * root, BinaryNodeType target)
{
    if(root == NULL || root->value == target)
    {
        return root;
    }

    if(target < root->value)
    {
        return searchNode(root->left, target);
    }
    else
    {
        return searchNode(root->right, target);
    }
}

BinaryNode * insertNode(BinaryNode * root, BinaryNodeType value)
{
    if(root == NULL)
    {
        return createNode(value);
    }

    if(value < root->value)
    {
        root->left = insertNode(root->left, value);
    }
    else if(value > root->value)
    {
        root->right = insertNode(root->right, value);
    }
    else
    {
        return root;
    }

    int leftHeight = nodeHeight(root->left);
    int rightHeight = nodeHeight(root->right);
    root->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

    return root;
}

void inOrder(BinaryNode * root)
{
    if(root == NULL)
    {
        return;
    }

    inOrder(root->left);
    printf("%d ", root->value);
    inOrder(root->right);
}

void destroy(BinaryNode * root)
{
    if(root == NULL)
    {
        return;
    }

    destroy(root->left);
    destroy(root->right);
    free(root);
}
