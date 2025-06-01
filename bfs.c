#include <stdio.h>

#define SIZE 100

int adj[SIZE][SIZE], visited[SIZE], queue[SIZE];
int front = -1, rear = -1;

void bfs(int start, int n)
{
    visited[start] = 1;
    queue[++rear] = start;
    while (front != rear)
    {
        int current = queue[++front];
        for (int i = 0; i < n; i++)
        {
            if (adj[current][i] && !visited[i])
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main()
{
    int vertices = 5;
    int edges = 6;
    int edgeList[6][2] = {
        {0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 4}, {3, 4}};

    for (int i = 0; i < edges; i++)
    {
        int u = edgeList[i][0], v = edgeList[i][1];
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    bfs(0, vertices);
    return 0;
}
