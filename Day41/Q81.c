#include <stdio.h>
#include <stdlib.h>

struct node{

    int data;
    struct node *next;

};

struct node *front=NULL,*rear=NULL;

void enqueue(int x){

    struct node* temp = malloc(sizeof(struct node));

    temp->data = x;

    temp->next = NULL;

    if(rear == NULL){

        front = rear = temp;

        return;
    }

    rear->next = temp;

    rear = temp;
}

int dequeue(){

    if(front == NULL)
        return -1;

    struct node* temp = front;

    int val = temp->data;

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);

    return val;
}

int main(){

    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("%d\n", dequeue());
    printf("%d\n", dequeue());

}