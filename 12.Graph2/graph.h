#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int dest;
    int weight;
    struct Node * next;
};

struct Graph
{
    int nodes;
    struct Node ** array;
};

typedef struct Node Node;
typedef struct Graph Graph;

Node * createNode(int dest, int weight);
Graph * createGraph(int nodes);

void addDirectedEdge(Graph * graph, int u, int v, int w);
void pushNodeToList(Node * head, Node * node);

void printGraph(Graph * graph);

#endif