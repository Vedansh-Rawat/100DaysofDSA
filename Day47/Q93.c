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

int height(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (leftHeight > rightHeight)
        return 1 + leftHeight;
    else
        return 1 + rightHeight;
}

struct Node* buildTree() {
    int val;
    printf("Enter node value (-1 for NULL): ");
    scanf("%d", &val);

    if (val == -1)
        return NULL;

    struct Node* root = createNode(val);

    printf("Entering left child of %d\n", val);
    root->left = buildTree();

    printf("Entering right child of %d\n", val);
    root->right = buildTree();

    return root;
}

int main() {
    struct Node* root;

    printf("Build Binary Tree\n");
    root = buildTree();

    int h = height(root);

    printf("Height of Binary Tree = %d\n", h);

    return 0;
}