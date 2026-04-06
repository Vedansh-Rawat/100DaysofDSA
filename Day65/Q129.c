#include <stdio.h>
#include <stdlib.h>

int hasCycle(int v, int parent, int visited[], int **adj, int *colSize) {
    visited[v] = 1;

    for (int i = 0; i < colSize[v]; i++) {
        int neighbor = adj[v][i];

        if (!visited[neighbor]) {
            if (hasCycle(neighbor, v, visited, adj, colSize))
                return 1;
        } else if (neighbor != parent) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int **adj = (int **)malloc(n * sizeof(int *));
    int *colSize = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Enter number of neighbors of %d: ", i);
        scanf("%d", &colSize[i]);

        adj[i] = (int *)malloc(colSize[i] * sizeof(int));

        printf("Enter neighbors: ");
        for (int j = 0; j < colSize[i]; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int *visited = (int *)calloc(n, sizeof(int));
    int cycle = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (hasCycle(i, -1, visited, adj, colSize)) {
                cycle = 1;
                break;
            }
        }
    }

    if (cycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}