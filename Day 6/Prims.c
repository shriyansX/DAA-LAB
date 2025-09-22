#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, i, j, start;
    int cost[MAX][MAX], mst[MAX][MAX];
    int selected[MAX], min, u, v, totalCost = 0;

    FILE *fp = fopen("inUnAdjMat.dat", "r");
    if (fp == NULL) {
        printf("Error: Cannot open input file.\n");
        return 1;
    }

    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);
    printf("Enter the Starting Vertex: ");
    scanf("%d", &start);

    // Read cost adjacency matrix from file
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            fscanf(fp, "%d", &cost[i][j]);
            mst[i][j] = 0; // Initialize MST matrix
        }
    }
    fclose(fp);

    // Initialize selected array
    for (i = 0; i < n; i++)
        selected[i] = 0;

    selected[start - 1] = 1; // Include starting vertex in MST

    // Prim's Algorithm
    for (int edges = 0; edges < n - 1; edges++) {
        min = INT_MAX;
        u = -1;
        v = -1;

        for (i = 0; i < n; i++) {
            if (selected[i]) {
                for (j = 0; j < n; j++) {
                    if (!selected[j] && cost[i][j] != 0) {
                        if (cost[i][j] < min) {
                            min = cost[i][j];
                            u = i;
                            v = j;
                        }
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            selected[v] = 1;
            mst[u][v] = mst[v][u] = cost[u][v];
            totalCost += cost[u][v];
        }
    }

    // Display MST adjacency matrix
    printf("Minimum Spanning Tree (Adjacency Matrix):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", mst[i][j]);
        }
        printf("\n");
    }

    printf("Total Weight of the Spanning Tree: %d\n", totalCost);

    return 0;
}
