#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, w;
} Edge;

int parent[MAX];

// Find set of an element i (with path compression)
int findSet(int i) {
    if (parent[i] != i)
        parent[i] = findSet(parent[i]);
    return parent[i];
}

// Union of two sets u and v
void unionSets(int u, int v) {
    int setU = findSet(u);
    int setV = findSet(v);
    parent[setV] = setU;
}

// Comparison function for qsort (sort edges by weight)
int compare(const void *a, const void *b) {
    Edge *e1 = (Edge *)a;
    Edge *e2 = (Edge *)b;
    return e1->w - e2->w;
}

int main() {
    int n, m, i, totalCost = 0;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    Edge edges[MAX], mst[MAX];

    printf("Enter edges (u v w):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    // Initialize disjoint sets
    for (i = 1; i <= n; i++)
        parent[i] = i;

    // Sort edges by weight
    qsort(edges, m, sizeof(Edge), compare);

    int count = 0;
    printf("Edge\tCost\n");
    for (i = 0; i < m && count < n - 1; i++) {
        int uSet = findSet(edges[i].u);
        int vSet = findSet(edges[i].v);

        if (uSet != vSet) {
            mst[count] = edges[i];
            totalCost += edges[i].w;
            printf("%d--%d %d\n", edges[i].u, edges[i].v, edges[i].w);
            unionSets(uSet, vSet);
            count++;
        }
    }

    printf("Total Weight of the Spanning Tree: %d\n", totalCost);
    return 0;
}
