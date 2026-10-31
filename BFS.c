#include <stdio.h>
#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];

void bfs(int startNode, int n)
{
    int front = 0, rear = 0;
    visited[startNode] = 1;
    queue[rear++] = startNode;

    while (front < rear)
    {
        int u = queue[front++];
        printf("%d ", u);

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] == 1 && visited[v] == 0)
            {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
}

void bfsTraversal(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            bfs(i, n);
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix elements (%d x %d):\n", n, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("\nBFS Result:\n");
    bfsTraversal(n);
    printf("\n");

    return 0;
}