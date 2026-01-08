#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int dest;
    struct Node * next;
};

struct Graph
{
    int nodes;
    struct Node ** array;
};

typedef struct Node Node;
typedef struct Graph Graph;

Node * createNode(int dest);
Graph * createGraph(int nodes);

void addEdge(Graph * graph, int u, int v);
void pushNodeToList(Node * head, Node * node);

void printGraph(Graph * graph);

#endif