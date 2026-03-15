#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

typedef struct Node
{
    int dest;
    int weight;
    struct Node * next;
} Node;

typedef struct Graph
{
    int nodes;
    Node ** array;
} Graph;

Graph * createGraph(int nodes);
void addEdge(Graph * graph, int src, int dest, int weight);

int * dijkstra(Graph * graph, int start, int target, int * pathSize);
int * astar(Graph * graph, int start, int target, int * h, int * pathSize);

#endif