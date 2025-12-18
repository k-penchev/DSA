#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

typedef unsigned int uint;

struct Node
{
    int value;
    int height;
    struct Node * left;
    struct Node * right;
};

typedef struct Node Node;

int max(int x, int y)
{
    if(x > y)
    {
        return x;
    }

    return y;
}

void updateHeight(Node * root)
{
    int l = root->left == NULL ? 0 : root->left->height;
    int r = root->right == NULL ? 0 : root->right->height;

    root->height = 1 + max(l, r);
}

int getHeight(Node * root)
{
    if(root == NULL)
    {
        return 0;
    }

    return root->height;
}

Node * rotateLeft(Node * oldRoot)
{
    Node * newRoot = oldRoot->right;
    oldRoot->right = newRoot->left;
    newRoot->left = oldRoot;

    updateHeight(oldRoot);
    updateHeight(newRoot);

    return newRoot;
}

Node * rotateRight(Node * oldRoot)
{
    Node * newRoot = oldRoot->left;
    oldRoot->left = newRoot->right;
    newRoot->right = oldRoot;

    updateHeight(oldRoot);
    updateHeight(newRoot);

    return newRoot;
}

Node * create(int v)
{
    Node * res = (Node *)malloc(sizeof(Node));
    assert(res != NULL);

    res->value = v;
    res->height = 1;
    res->left = NULL;
    res->right = NULL;
    return res;
}

Node * insert(Node * root, int v)
{
    if(root == NULL)
    {
        return create(v);
    }

    if(v < root->value)
    {
        root->left = insert(root->left, v);
    }
    else if(v > root->value)
    {
        root->right = insert(root->right, v);
    }

    updateHeight(root);
    int balance = getHeight(root->left) - getHeight(root->right);

    if(balance > 1)
    {
        if(v > root->left->value)
        {
            root->left = rotateLeft(root->left);
        }

        root = rotateRight(root);
    }
    else if(balance < -1)
    {
        if(v < root->right->value)
        {
            root->right = rotateRight(root->right);
        }

        root = rotateLeft(root);
    }
    
    return root;
}

Node * search(Node * root, int v)
{
    if(root == NULL || root->value == v)
    {
        return root;
    }

    if(v < root->value)
    {
        return search(root->left, v);
    }
    else
    {
        return search(root->right, v);
    }
}

void destroyTree(Node * root)
{
    if(root == NULL)
    {
        return;
    }

    destroyTree(root->left);
    destroyTree(root->right);

    free(root);
}

int main()
{
    
    return 0;
}

