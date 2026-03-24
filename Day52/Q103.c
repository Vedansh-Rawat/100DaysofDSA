#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    struct Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct Node* current = queue[front++];

        if (arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    return root;
}

struct Node* LCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    struct Node* left = LCA(root->left, n1, n2);
    struct Node* right = LCA(root->right, n1, n2);

    if (left && right) return root;

    return (left != NULL) ? left : right;
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[1000];
    printf("Enter level order (-1 for NULL): ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int n1, n2;
    printf("Enter two nodes: ");
    scanf("%d %d", &n1, &n2);

    struct Node* root = buildTree(arr, n);

    struct Node* ans = LCA(root, n1, n2);

    if (ans)
        printf("LCA: %d\n", ans->data);
    else
        printf("LCA not found\n");

    return 0;
}