#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* createList(int n)
{
    struct node *head = NULL, *temp = NULL, *newnode = NULL;
    int i;

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

    return head;
}

struct node* mergeLists(struct node* l1, struct node* l2)
{
    struct node dummy;
    struct node *tail = &dummy;
    dummy.next = NULL;

    while(l1 != NULL && l2 != NULL)
    {
        if(l1->data <= l2->data)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if(l1 != NULL)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy.next;
}

void display(struct node* head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    int n, m;

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n);
    struct node* list1 = createList(n);

    printf("Enter number of nodes in second list: ");
    scanf("%d", &m);
    struct node* list2 = createList(m);

    struct node* merged = mergeLists(list1, list2);

    printf("Merged List: ");
    display(merged);

    return 0;
}