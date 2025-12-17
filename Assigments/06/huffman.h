#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdbool.h>

#define MAXN 1024

struct BinaryNode
{
    int frequency;
    char symbol;
    
    struct BinaryNode * left;
    struct BinaryNode * right;
};

struct Code
{
    char symbol;
    char code;
};

typedef struct Code Code;
typedef struct BinaryNode BinaryNode;

extern int bufferSize;
extern Code buffer[MAXN];

BinaryNode * createNode(int f, char s);
BinaryNode * buildHuffmanTree(char string[], int string_size);
void dfs(BinaryNode * root, char baseCode);
void destroyTree(BinaryNode * root);

#endif
