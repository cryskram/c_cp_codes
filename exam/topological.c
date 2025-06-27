#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int nodes;

void dfs(int v)
{
    visited[v] = 1;
    for (int i = 0; i < nodes; i++)
    {
        if (graph[v][i] && !visited[i])
            dfs(i);
    }
    stack[++top] = v;
}

void topologicalSort()
{
    for (int i = 0; i < nodes; i++)
        visited[i] = 0;

    for (int i = 0; i < nodes; i++)
        if (!visited[i])
            dfs(i);

    printf("Topological Order: ");
    while (top != -1)
        printf("%d ", stack[top--]);
    printf("\n");
}

int main()
{
    int edges, u, v;

    printf("Enter number of nodes: ");
    scanf("%d", &nodes);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++)
    {
        printf("Enter edge (from to): ");
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    topologicalSort();

    return 0;
}