#include "bst.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

static int nodeHeight(BinaryNode * node)
{
    return node ? node->height : 0;
}

static int maxInt(int a, int b)
{
    return (a > b) ? a : b;
}

static int getBalance(BinaryNode * node)
{
    if(node == NULL)
    {
        return 0;
    }
    
    return nodeHeight(node->left) - nodeHeight(node->right);
}

static BinaryNode * rightRotate(BinaryNode * y)
{
    BinaryNode * x = y->left;
    BinaryNode * T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = maxInt(nodeHeight(y->left), nodeHeight(y->right)) + 1;
    x->height = maxInt(nodeHeight(x->left), nodeHeight(x->right)) + 1;

    return x;
}

static BinaryNode * leftRotate(BinaryNode * x)
{
    BinaryNode * y = x->right;
    BinaryNode * T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = maxInt(nodeHeight(x->left), nodeHeight(x->right)) + 1;
    y->height = maxInt(nodeHeight(y->left), nodeHeight(y->right)) + 1;

    return y;
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

    root->height = maxInt(nodeHeight(root->left), nodeHeight(root->right)) + 1;

    int balance = getBalance(root);

    if(balance > 1 && value < root->left->value)
    {
        return rightRotate(root);
    }

    if(balance < -1 && value > root->right->value)
    {
        return leftRotate(root);
    }

    if(balance > 1 && value > root->left->value)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if(balance < -1 && value < root->right->value)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

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
