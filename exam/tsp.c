#include <stdio.h>
#include <limits.h>

#define N 4

int minCost = INT_MAX;
int path[N];
int visited[N];

int cost[N][N] = {
    {0, 12, 10, 19},
    {12, 0, 3, 7},
    {10, 3, 0, 6},
    {19, 7, 6, 0}};

void tsp(int currentCity, int count, int currentCost)
{
    if (count == N && cost[currentCity][0])
    {
        int totalCost = currentCost + cost[currentCity][0];
        if (totalCost < minCost)
            minCost = totalCost;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (!visited[i] && cost[currentCity][i])
        {
            visited[i] = 1;
            tsp(i, count + 1, currentCost + cost[currentCity][i]);
            visited[i] = 0;
        }
    }
}

int main()
{
    for (int i = 0; i < N; i++)
        visited[i] = 0;

    visited[0] = 1;
    tsp(0, 1, 0);

    printf("Minimum cost for TSP (using Branch and Bound): %d\n", minCost);
    return 0;
}