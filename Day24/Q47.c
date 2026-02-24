#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    int n, key, i;
    struct Node *head = NULL, *temp = NULL, *newNode, *prev = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Enter key to delete: ");
    scanf("%d", &key);

    temp = head;

    if(temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
    } else {
        while(temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if(temp != NULL) {
            prev->next = temp->next;
            free(temp);
        }
    }

    printf("Linked list after deletion:\n");
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}