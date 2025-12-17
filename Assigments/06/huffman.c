#include "heap.h"
#include "huffman.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int bufferSize = 0;
Code buffer[MAXN];

BinaryNode *createNode(int f, char s)
{
    BinaryNode *newNode = malloc(sizeof(BinaryNode));
    assert(newNode != NULL);

    newNode->frequency = f;
    newNode->symbol = s;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

BinaryNode * buildHuffmanTree(char string[], int string_size)
{
    if(string_size <= 0)
    {
        return NULL;
    }

    int freq[256] = {0};

    for(int i = 0; i < string_size; ++i)
    {
        unsigned char c = (unsigned char)string[i];
        freq[c] += 1;
    }

    Heap pq = init();

    for(int c = 0; c < 256; ++c)
    {
        if(freq[c] > 0)
        {
            BinaryNode * node = createNode(freq[c], (char)c);

            HeapType item;
            item.key = freq[c];
            item.node = node;

            push(&pq, item);
        }
    }

    if(size(&pq) == 0)
    {
        return NULL;
    }

    while(size(&pq) > 1)
    {
        HeapType left = pop(&pq);
        HeapType right = pop(&pq);

        BinaryNode * parent = createNode(left.key + right.key, '\0');

        parent->left = left.node;
        parent->right = right.node;

        HeapType merged;
        merged.key = parent->frequency;
        merged.node = parent;

        push(&pq, merged);
    }

    HeapType rootItem = pop(&pq);
    BinaryNode * root = rootItem.node;

    destroyHeap(&pq);

    return root;
}

void dfs(BinaryNode * root, char curr)
{
    if(root == NULL)
    {
        return;
    }

    Code c = {root->symbol, curr};
    buffer[bufferSize++] = c;

    dfs(root->left, curr << 1);
    printf("%c : %d\n", root->symbol, curr);
    dfs(root->right, (curr << 1) | 1);
}

void destroyTree(BinaryNode * root)
{
    if(root == NULL) return;

    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
}
