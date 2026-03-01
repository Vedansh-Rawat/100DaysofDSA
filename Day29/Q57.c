#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, k, i;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL, *tail = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Enter k: ");
    scanf("%d", &k);

    if(head == NULL || head->next == NULL) {
        temp = head;
    } else {
        int count = 1;
        temp = head;

        while(temp->next != NULL) {
            temp = temp->next;
            count++;
        }

        k = k % count;

        if(k != 0) {
            temp->next = head;

            int steps = count - k;
            temp = head;

            for(i = 1; i < steps; i++) {
                temp = temp->next;
            }

            head = temp->next;
            temp->next = NULL;
        }
    }

    printf("Rotated List:\n");
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}