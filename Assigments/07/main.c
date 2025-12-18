#include "huffman.h"
#include <stdio.h>

int main()
{
    BinaryNode * root = buildHuffmanTree("martainIkaloyan", 15);
    
    printf("From DFS\n");
    dfs(root, 0);
    
    printf("From Array\n");
    for(int i = 0 ; i < bufferSize ; ++i)
    {
        printf("%c : %d\n", buffer[i].symbol, buffer[i].code);
    }

    destroyTree(root);
    return 0;
}