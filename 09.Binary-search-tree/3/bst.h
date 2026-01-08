#ifndef BST_H
#define BST_H

#include <stdbool.h>

typedef int BinaryNodeType;

struct BinaryNode
{
    BinaryNodeType value;
    struct BinaryNode * left;
    struct BinaryNode * right;
    int height;
};

typedef struct BinaryNode BinaryNode;

BinaryNode * createNode(BinaryNodeType value);
BinaryNode * searchNode(BinaryNode * root, BinaryNodeType target);
BinaryNode * insertNode(BinaryNode * root, BinaryNodeType value);
void inOrder(BinaryNode * root);
void destroy(BinaryNode * root);

#endif
