#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int countLeaf(struct Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaf(root->left) + countLeaf(root->right);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        int val;
        printf("Enter value of node %d: ", i);
        scanf("%d", &val);
        nodes[i] = createNode(val);
    }

    for (int i = 0; i < n; i++) {
        int l, r;
        printf("Enter left and right index of node %d (-1 if none): ", i);
        scanf("%d %d", &l, &r);

        if (l != -1)
            nodes[i]->left = nodes[l];
        if (r != -1)
            nodes[i]->right = nodes[r];
    }

    int ans = countLeaf(nodes[0]);
    printf("Leaf nodes = %d\n", ans);

    return 0;
}