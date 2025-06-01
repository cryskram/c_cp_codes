#include <stdio.h>
#include <limits.h>

#define N 4

int tsp(int graph[N][N], int visited[N], int pos, int count, int cost, int start, int *minCost)
{
    if (count == N && graph[pos][start])
    {
        int totalCost = cost + graph[pos][start];
        if (totalCost < *minCost)
            *minCost = totalCost;
        return *minCost;
    }

    for (int i = 0; i < N; i++)
    {
        if (!visited[i] && graph[pos][i])
        {
            visited[i] = 1;
            tsp(graph, visited, i, count + 1, cost + graph[pos][i], start, minCost);
            visited[i] = 0;
        }
    }

    return *minCost;
}

int main()
{
    int graph[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};

    int visited[N] = {0};
    int minCost = INT_MAX;

    visited[0] = 1;
    tsp(graph, visited, 0, 1, 0, 0, &minCost);

    return 0;
}
