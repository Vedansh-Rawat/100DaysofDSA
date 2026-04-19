#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v w):\n");
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int selected[MAX];
    int min, x, y;
    int total = 0;

    for(int i = 1; i <= n; i++) {
        selected[i] = 0;
    }

    selected[1] = 1;

    for(int edge = 0; edge < n - 1; edge++) {
        min = INT_MAX;

        for(int i = 1; i <= n; i++) {
            if(selected[i]) {
                for(int j = 1; j <= n; j++) {
                    if(!selected[j] && graph[i][j]) {
                        if(graph[i][j] < min) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        selected[y] = 1;
        total += graph[x][y];
    }

    printf("Total weight of MST: %d\n", total);

    return 0;
}