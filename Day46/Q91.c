#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* queue[100];
int front = -1, rear = -1;

void enqueue(struct Node* node) {
    if (front == -1) front = 0;
    queue[++rear] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

void levelOrder(struct Node* root) {
    if (root == NULL) return;

    enqueue(root);

    while (front <= rear) {
        struct Node* temp = dequeue();
        printf("%d ", temp->data);

        if (temp->left != NULL)
            enqueue(temp->left);

        if (temp->right != NULL)
            enqueue(temp->right);
    }
}

int main() {
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n == 0) return 0;

    struct Node* nodes[100];

    for (int i = 0; i < n; i++) {
        printf("Enter value of node %d: ", i + 1);
        scanf("%d", &val);
        nodes[i] = createNode(val);
    }

    for (int i = 0; i < n; i++) {
        int left, right;
        printf("Enter left and right child index of node %d (-1 for NULL): ", i);
        scanf("%d %d", &left, &right);

        if (left != -1)
            nodes[i]->left = nodes[left];

        if (right != -1)
            nodes[i]->right = nodes[right];
    }

    printf("Level Order Traversal:\n");
    levelOrder(nodes[0]);

    return 0;
}