#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef int BinaryNodeType;

struct BinaryNode
{
    BinaryNodeType value;
    struct BinaryNode * left;
    struct BinaryNode * right;
};

typedef struct BinaryNode BinaryNode;

BinaryNode * createNode(BinaryNodeType value);

BinaryNode * findNode(BinaryNode * root, BinaryNodeType target);
BinaryNode * insertNode(BinaryNode * root, BinaryNodeType value);
BinaryNode * deleteNode(BinaryNode * root, BinaryNodeType value);

void printBinarySearchTree(BinaryNode * root);
void destory(BinaryNode * root);

#endif
