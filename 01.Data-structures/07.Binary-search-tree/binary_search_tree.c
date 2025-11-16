#include "binary_search_tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

BinaryNode * createNode(BinaryNodeType value)
{
    BinaryNode * newNode = malloc(sizeof(BinaryNode));
    assert(newNode != NULL);

    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

BinaryNode * findNode(BinaryNode * root, BinaryNodeType target)
{
    if(root == NULL || root->value == target)
    {
        return root;
    }

    if(target < root->value)
    {
        return findNode(root->left, target);
    }
    else
    {
        return findNode(root->right, target);
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
    else
    {
        root->right = insertNode(root->right, value);
    }

    return root;
}

static BinaryNode * findMin(BinaryNode * root)
{
    while(root != NULL && root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

BinaryNode * deleteNode(BinaryNode * root, BinaryNodeType value)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(value < root->value)
    {
        root->left = deleteNode(root->left, value);
    }
    else if(value > root->value)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left == NULL || root->right == NULL)
        {
            BinaryNode * temp;

            if(root->left == NULL)
            {
                temp = root->right;
            }
            else
            {
                temp = root->left;
            }

            free(root);
            return temp;
        }
        else
        {
            BinaryNode * succ = findMin(root->right);
            root->value = succ->value;
            root->right = deleteNode(root->right, succ->value);
        }
    }

    return root;
}

void printBinarySearchTree(BinaryNode * root)
{
    if(root == NULL) return;

    printBinarySearchTree(root->left);
    printf("%d ", root->value);
    printBinarySearchTree(root->right);
}

void destory(BinaryNode * root)
{
    if(root == NULL) return;

    destory(root->left);
    destory(root->right);
    free(root);
}
