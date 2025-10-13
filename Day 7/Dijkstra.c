#include <stdio.h>
#include <limits.h>

#define MAX 10
#define INF 9999

int n;
int cost[MAX][MAX];
int dist[MAX], visited[MAX], parent[MAX];

void dijkstra(int src) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 1; count <= n - 1; count++) {
        int u = -1, min = INF;
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && cost[u][v] && dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
                parent[v] = u;
            }
        }
    }
}

void printPath(int v) {
    if (parent[v] == -1)
        return;
    printPath(parent[v]);
    printf("->%d", v);
}

int main() {
    FILE *fp = fopen("inDiAdjMat1.dat", "r");
    if (!fp) {
        printf("Error: Cannot open input file.\n");
        return 1;
    }

    n = 5; // number of vertices is 5 for this case

    // read adjacency matrix
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            fscanf(fp, "%d", &cost[i][j]);
    fclose(fp);

    int src;
    printf("Enter the Number of Vertices: %d\n", n);
    printf("Enter the Source Vertex: ");
    scanf("%d", &src);

    dijkstra(src);

    printf("\nOutput:\n");
    printf("Source\tDestination\tCost\tPath\n");

    for (int i = 1; i <= n; i++) {
        printf("%d\t%d\t\t", src, i);
        if (dist[i] == INF) {
            printf("INF\tNo Path\n");
            continue;
        }
        printf("%d\t", dist[i]);
        if (i == src)
            printf("-\n");
        else {
            printf("%d", src);
            printPath(i);
            printf("\n");
        }
    }

    return 0;
}
