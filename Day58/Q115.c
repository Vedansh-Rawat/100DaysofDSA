#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

Node* build(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start > end)
        return NULL;

    Node* root = createNode(preorder[*preIndex]);
    (*preIndex)++;

    if (start == end)
        return root;

    int inIndex = search(inorder, start, end, root->data);

    root->left = build(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = build(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

void postorder(Node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int preorder[1000], inorder[1000];

    printf("Enter preorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    printf("Enter inorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    int preIndex = 0;

    Node* root = build(preorder, inorder, 0, n - 1, &preIndex);

    printf("Postorder traversal: ");
    postorder(root);

    return 0;
}