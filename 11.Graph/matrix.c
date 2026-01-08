#include <stdio.h>

#define N 4

void displayAdjacency(int adj[N][N])
{
    for(int i = 0 ; i < N ; ++i)
    {
        for(int j = 0 ; j < N ; ++j)
        {
            printf("%d ", adj[i][j]);
        }

        printf("\n");
    }
}

void addEdge(int adj[N][N], int u, int v)
{
    adj[u][v] = 1;
    adj[v][u] = 1;
}

int main()
{
    int matrix[N][N] = {0};

    addEdge(matrix, 0, 1);
    addEdge(matrix, 1, 2);
    addEdge(matrix, 2, 3);

    displayAdjacency(matrix);

    return 0;
}