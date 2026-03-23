#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return create(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

struct Node* lca(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    if (n1 < root->data && n2 < root->data)
        return lca(root->left, n1, n2);

    if (n1 > root->data && n2 > root->data)
        return lca(root->right, n1, n2);

    return root;
}

int main() {
    int n, i, val, n1, n2;
    struct Node* root = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Enter two node values: ");
    scanf("%d %d", &n1, &n2);

    struct Node* ans = lca(root, n1, n2);

    printf("LCA: %d", ans->data);

    return 0;
}