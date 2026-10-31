
#include <stdio.h>

#define INF 999

int main()
{
    int cost[10][10];
    int parent[10];
    int n, i, j, u, v;
    int min, mincost = 0, edges = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    for (i = 0; i < n; i++)
        parent[i] = -1;

    printf("\nEdges in the Minimum Spanning Tree:\n");

    while (edges < n - 1)
    {
        min = INF;
        u = -1;
        v = -1;

        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if (u == -1 || min == INF)
        {
            printf("Graph is disconnected!\n");
            return 0;
        }

        i = u;

        while (parent[i] != -1)
            i = parent[i];

        j = v;

        while (parent[j] != -1)
            j = parent[j];

        if (i != j)
        {
            printf("%d - %d : %d\n", u + 1, v + 1, min);

            mincost += min;
            edges++;

            parent[i] = j;
        }

        cost[u][v] = INF;
        cost[v][u] = INF;
    }

    printf("\nMinimum Cost of Spanning Tree = %d\n", mincost);

    return 0;
}
