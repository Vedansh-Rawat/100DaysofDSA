#include <stdio.h>
#include <stdlib.h>

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    int adj[V][V];
    int indegree[V];
    int queue[V];
    int front = 0, rear = 0;

    for(int i = 0; i < V; i++) {
        indegree[i] = 0;
        for(int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v) where u -> v:\n");
    for(int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    for(int i = 0; i < V; i++) {
        if(indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;
    int topo[V];

    while(front < rear) {
        int node = queue[front++];
        topo[count++] = node;

        for(int i = 0; i < V; i++) {
            if(adj[node][i] == 1) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    if(count != V) {
        printf("Cycle detected. Topological sort not possible.\n");
    } else {
        printf("Topological Order:\n");
        for(int i = 0; i < V; i++) {
            printf("%d ", topo[i]);
        }
    }

    return 0;
}