#include <stdio.h>

int adj[100][100], visited[100];
int n;

void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(start);

    return 0;
}