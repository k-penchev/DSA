#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

Node * createNode(int dest)
{
    Node * node = malloc(sizeof(Node));
    node->dest = dest;
    node->next = NULL;
    return node;
}

void pushNodeToList(Node * head, Node * node)
{
    while(head->next != NULL)
    {
        head = head->next;
    }

    head->next = node;
}

Graph * createGraph(int nodes)
{
    Graph * graph = malloc(sizeof(Graph));
    graph->nodes = nodes;
    graph->array = calloc(nodes, sizeof(Node *));
    return graph;
}

void addEdge(Graph * graph, int u, int v)
{
    Node * node = createNode(v);
    
    if(graph->array[u] == NULL)
    {
        graph->array[u] = node;
    }
    else
    {
        pushNodeToList(graph->array[u], node);
    }
}

void printGraph(Graph * graph)
{
    for(int i = 0 ; i < graph->nodes ; ++i)
    {
        printf("%d --> ", i);
        for(Node * cur = graph->array[i] ; cur != NULL ; cur = cur->next)
        {
            printf("%d ", cur->dest);
        }
        printf("\n");
    }
}

