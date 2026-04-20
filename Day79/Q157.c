#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

Node* adj[MAX];

void addEdge(int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

typedef struct {
    int node, dist;
} HeapNode;

HeapNode heap[MAX];
int size = 0;

void swap(int i, int j) {
    HeapNode temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void push(int node, int dist) {
    heap[++size] = (HeapNode){node, dist};
    int i = size;
    while (i > 1 && heap[i].dist < heap[i/2].dist) {
        swap(i, i/2);
        i /= 2;
    }
}

HeapNode pop() {
    HeapNode top = heap[1];
    heap[1] = heap[size--];

    int i = 1;
    while (2*i <= size) {
        int smallest = i;
        if (heap[2*i].dist < heap[smallest].dist)
            smallest = 2*i;
        if (2*i+1 <= size && heap[2*i+1].dist < heap[smallest].dist)
            smallest = 2*i+1;

        if (smallest != i) {
            swap(i, smallest);
            i = smallest;
        } else break;
    }

    return top;
}

int main() {
    int n, m;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) adj[i] = NULL;

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);

    int dist[MAX];
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;

    dist[source] = 0;
    push(source, 0);

    while (size > 0) {
        HeapNode cur = pop();
        int u = cur.node;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }

            temp = temp->next;
        }
    }

    printf("Shortest distances:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}