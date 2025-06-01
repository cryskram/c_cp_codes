#include <stdlib.h>

#define MAX 30

struct Edge
{
    int src, dest, weight;
};
int parent[MAX];

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union_set(int i, int j)
{
    int a = find(i), b = find(j);
    parent[a] = b;
}

void kruskal(struct Edge edge[], int V, int E)
{
    for (int i = 0; i < V; i++)
        parent[i] = i;

    for (int i = 0; i < E - 1; i++)
        for (int j = 0; j < E - i - 1; j++)
            if (edge[j].weight > edge[j + 1].weight)
            {
                struct Edge temp = edge[j];
                edge[j] = edge[j + 1];
                edge[j + 1] = temp;
            }

    for (int i = 0, j = 0; i < E && j < V - 1; i++)
    {
        int x = find(edge[i].src);
        int y = find(edge[i].dest);
        if (x != y)
        {
            union_set(x, y);
            j++;
        }
    }
}

int main()
{
    struct Edge edges[] = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};
    kruskal(edges, 4, 5);
    return 0;
}
