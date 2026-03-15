#include "graph.h"
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int cycleDFS(Graph * graph, int node, int * color)
{
    color[node] = 1;

    for(Node * cur = graph->array[node] ; cur != NULL ; cur = cur->next)
    {
        if(color[cur->dest] == 0)
        {
            int res = cycleDFS(graph, cur->dest, color);
            if(res == 1)
            {
                return 1;
            }
        }
        else if(color[cur->dest] == 1)
        {
            return 1;
        }
    }

    color[node] = 2;
    return 0;
}

void topoDFS(Graph * graph, int node, bool * vis, int * topo, int * ptr)
{
    vis[node] = 1;

    for(Node * cur = graph->array[node] ; cur != NULL ; cur = cur->next)
    {
        if(!vis[cur->dest])
        {
            topoDFS(graph, cur->dest, vis, topo, ptr);
        }
    }

    topo[(*ptr)++] = node;
}


int reachDFS(Graph * graph, int node, bool * vis, int target)
{
    if(node == target)
    {
        return 1;
    }

    vis[node] = 1;

    for(Node * cur = graph->array[node] ; cur != NULL ; cur = cur->next)
    {
        if(!vis[cur->dest])
        {
            int res = reachDFS(graph, cur->dest, vis, target);
            if(res == 1)
            {
                return 1;
            }
        }
    }

    return 0;
}

int isCyclical(Graph * graph)
{
    int hasCycle = 0;
    int * color = calloc(graph->nodes, sizeof(int));

    for(int i = 0; i < graph->nodes; ++i)
    {
        if(color[i] == 0 && cycleDFS(graph, i, color))
        {
            hasCycle = 1;
            break;
        }
    }

    free(color);
    return hasCycle;
}

int * topoSort(Graph * graph)
{
    int ptr = 0;
    bool * vis = calloc(graph->nodes, sizeof(bool));
    int * topo = calloc(graph->nodes, sizeof(int));
    int * res = calloc(graph->nodes, sizeof(int));

    for(int i = 0; i < graph->nodes; ++i)
    {
        if(!vis[i])
        {
            topoDFS(graph, i, vis, topo, &ptr);
        }
    }

    for(int i = 0; i < graph->nodes; ++i)
    {
        res[i] = topo[(graph->nodes - 1) - i];
    }

    free(vis);
    free(topo);
    return res;
}

int isReachable(Graph * graph, int start, int end)
{
    bool * vis = calloc(graph->nodes, sizeof(bool));
    int reachable = reachDFS(graph, start, vis, end);
    free(vis);
    return reachable;
}

int main()
{
    int n, m;

    FILE * file = fopen("./graph.txt", "r");
    fscanf(file, "%d %d", &n, &m);

    Graph * graph = createGraph(n);
    for(int i = 0; i < m; ++i)
    {
        int u, v, w;
        fscanf(file, "%d %d %d", &u, &v, &w);
        addDirectedEdge(graph, u, v, w);
    }

    int * topo = topoSort(graph);
    for(int i = 0 ; i < graph->nodes ; ++i)
    {
        printf("%d ", topo[i]);
        if(i == graph->nodes - 1) printf("\n");
    }

    printf("Cyclical: %d\n", isCyclical(graph));
    printf("3 --> 4: %d\n", isReachable(graph, 3, 4));
    printf("4 --> 3: %d\n", isReachable(graph, 4, 3));

    fclose(file);
    return 0;
}