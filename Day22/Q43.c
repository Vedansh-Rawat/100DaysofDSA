#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n, i, count = 0;
    struct node *head = NULL, *temp = NULL, *newnode = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    printf("Linked List: ");
    temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        count++;
        temp = temp->next;
    }

    printf("\nTotal Nodes: %d", count);

    return 0;
}