#include "binary_search_tree.h"
#include <stdlib.h>
#include <stdio.h>

BinaryNode * createNode(BinaryNodeType value)
{
    BinaryNode * newNode = malloc(sizeof(BinaryNode));

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

    if(root->value < target)
    {
        findNode(root->right, target);
    }
    
    findNode(root->left, target);
    
}   

BinaryNode * insertNode(BinaryNode * root, BinaryNodeType value)
{
    if(root == NULL)
    {
        return newNode(value);
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
            
        }
    }

    return root;
}

void printBinarySearchTree(BinaryNode * root);
void destory(BinaryNode * root);