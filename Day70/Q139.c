#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, m;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    int u[m], v[m], w[m];

    printf("Enter edges (u v w):\n");
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }

    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);

    int dist[n];
    for(int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[source] = 0;

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m; j++) {
            if(dist[u[j]] != INT_MAX && dist[u[j]] + w[j] < dist[v[j]]) {
                dist[v[j]] = dist[u[j]] + w[j];
            }
        }
    }

    for(int j = 0; j < m; j++) {
        if(dist[u[j]] != INT_MAX && dist[u[j]] + w[j] < dist[v[j]]) {
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }

    printf("Shortest distances:\n");
    for(int i = 0; i < n; i++) {
        if(dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }

    return 0;
}