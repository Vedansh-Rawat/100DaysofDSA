#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int findIndex(int inorder[], int start, int end, int val) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == val) return i;
    }
    return -1;
}

Node* build(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if(inStart > inEnd) return NULL;

    int val = postorder[*postIndex];
    (*postIndex)--;

    Node* root = createNode(val);

    int idx = findIndex(inorder, inStart, inEnd, val);

    root->right = build(inorder, postorder, idx + 1, inEnd, postIndex);
    root->left = build(inorder, postorder, inStart, idx - 1, postIndex);

    return root;
}

void preorder(Node* root) {
    if(root == NULL) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int inorder[n], postorder[n];

    printf("Enter inorder traversal: ");
    for(int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    printf("Enter postorder traversal: ");
    for(int i = 0; i < n; i++) scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    Node* root = build(inorder, postorder, 0, n - 1, &postIndex);

    printf("Preorder traversal: ");
    preorder(root);

    return 0;
}