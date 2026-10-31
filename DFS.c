#include <stdio.h>
#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX * MAX];

void dfs(int startNode, int n)
{
    int top = -1;
    stack[++top] = startNode;

    while (top >= 0)
    {
        int u = stack[top--];
        if (visited[u] == 0)
        {
            visited[u] = 1;
            printf("%d ", u);

            for (int v = n - 1; v >= 0; v--)
            {
                if (graph[u][v] == 1 && visited[v] == 0)
                {
                    stack[++top] = v;
                }
            }
        }
    }
}

void dfsTraversal(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i, n);
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

    printf("\nDFS Result:\n");
    dfsTraversal(n);
    printf("\n");

    return 0;
}