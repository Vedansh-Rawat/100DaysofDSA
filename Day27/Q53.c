#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* getIntersectionNode(struct Node* headA, struct Node* headB) {
    if (headA == NULL || headB == NULL)
        return NULL;

    struct Node* a = headA;
    struct Node* b = headB;

    while (a != b) {
        if (a == NULL)
            a = headB;
        else
            a = a->next;

        if (b == NULL)
            b = headA;
        else
            b = b->next;
    }

    return a;
}

int main() {

    // Common part
    struct Node* common = createNode(30);
    common->next = createNode(40);
    common->next->next = createNode(50);

    // List A: 10 -> 20 -> 30 -> 40 -> 50
    struct Node* headA = createNode(10);
    headA->next = createNode(20);
    headA->next->next = common;

    // List B: 15 -> 30 -> 40 -> 50
    struct Node* headB = createNode(15);
    headB->next = common;

    struct Node* intersection = getIntersectionNode(headA, headB);

    if (intersection != NULL)
        printf("Intersection at node with value: %d\n", intersection->data);
    else
        printf("No intersection\n");

    return 0;
}