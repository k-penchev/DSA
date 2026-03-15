#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"

Node * newNode(int dest, int weight)
{
    Node * node = malloc(sizeof(Node));
    node->dest = dest;
    node->weight = weight;
    node->next = NULL;
    return node;
}

Graph * createGraph(int nodes)
{
    Graph * graph = malloc(sizeof(Graph));
    graph->nodes = nodes;

    graph->array = malloc(nodes * sizeof(Node *));

    for(int i = 0 ; i < nodes ; ++i)
    {
        graph->array[i] = NULL;
    }

    return graph;
}

void addEdge(Graph * graph, int src, int dest, int weight)
{
    Node * node = newNode(dest, weight);
    node->next = graph->array[src];
    graph->array[src] = node;
}

int extractMin(int * dist, bool * used, int n)
{
    int best = -1;

    for(int i = 0 ; i < n ; ++i)
    {
        if(!used[i] && (best == -1 || dist[i] < dist[best]))
        {
            best = i;
        }
    }

    return best;
}

int * buildPath(int * parent, int start, int target, int * pathSize)
{
    int cur = target;
    int len = 0;

    while(cur != -1)
    {
        len++;
        cur = parent[cur];
    }

    int * path = malloc(len * sizeof(int));
    cur = target;

    for(int i = len - 1 ; i >= 0 ; --i)
    {
        path[i] = cur;
        cur = parent[cur];
    }

    *pathSize = len;
    return path;
}

int * dijkstra(Graph * graph, int start, int target, int * pathSize)
{
    int n = graph->nodes;

    int * dist = malloc(n * sizeof(int));
    int * parent = malloc(n * sizeof(int));
    bool * used = calloc(n, sizeof(bool));

    for(int i = 0 ; i < n ; ++i)
    {
        dist[i] = 1000000000;
        parent[i] = -1;
    }

    dist[start] = 0;

    while(true)
    {
        int v = extractMin(dist, used, n);

        if(v == -1) break;
        if(v == target) break;

        used[v] = 1;

        for(Node * cur = graph->array[v] ; cur != NULL ; cur = cur->next)
        {
            int to = cur->dest;
            int w = cur->weight;

            if(dist[v] + w < dist[to])
            {
                dist[to] = dist[v] + w;
                parent[to] = v;
            }
        }
    }

    int * path = buildPath(parent, start, target, pathSize);

    free(dist);
    free(parent);
    free(used);

    return path;
}

int * astar(Graph * graph, int start, int target, int * h, int * pathSize)
{
    int n = graph->nodes;

    int * g = malloc(n * sizeof(int));
    int * f = malloc(n * sizeof(int));
    int * parent = malloc(n * sizeof(int));
    bool * used = calloc(n, sizeof(bool));

    for(int i = 0 ; i < n ; ++i)
    {
        g[i] = 1000000000;
        f[i] = 1000000000;
        parent[i] = -1;
    }

    g[start] = 0;
    f[start] = h[start];

    while(1)
    {
        int v = extractMin(f, used, n);

        if(v == -1) break;
        if(v == target) break;

        used[v] = 1;

        for(Node * cur = graph->array[v] ; cur != NULL ; cur = cur->next)
        {
            int to = cur->dest;
            int w = cur->weight;

            if(g[v] + w < g[to])
            {
                g[to] = g[v] + w;
                f[to] = g[to] + h[to];
                parent[to] = v;
            }
        }
    }

    int * path = buildPath(parent, start, target, pathSize);

    free(g);
    free(f);
    free(parent);
    free(used);

    return path;
}