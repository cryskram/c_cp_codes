#include <stdio.h>
#include <limits.h>

#define N 4

int cost[N][N] = {
    {0, 12, 10, 19},
    {12, 0, 3, 7},
    {10, 3, 0, 6},
    {19, 7, 6, 0}
};

int visited[N], minCost = INT_MAX;

void tsp(int pos, int count, int costSoFar) {
    if (count == N) {
        if (costSoFar + cost[pos][0] < minCost)
            minCost = costSoFar + cost[pos][0];
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            tsp(i, count + 1, costSoFar + cost[pos][i]);
            visited[i] = 0;
        }
    }
}

int main() {
    visited[0] = 1;
    tsp(0, 1, 0);
    printf("Minimum cost: %d\n", minCost);
    return 0;
}