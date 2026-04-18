#include <stdio.h>
#include <stdlib.h>

int visited[100005];

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[100005];

void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

int queue[100005];

int main() {
    int n, m;

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    printf("Enter edges:\n");
    int u, v;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int front = 0, rear = 0;
    queue[rear++] = 1;
    visited[1] = 1;

    while(front < rear) {
        int node = queue[front++];
        struct Node* temp = adj[node];

        while(temp) {
            if(!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");
    return 0;
}