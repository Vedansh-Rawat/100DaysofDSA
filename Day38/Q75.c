#include <stdio.h>

#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

void insertFront(int x){

    if(front == -1){
        front = rear = 0;
    }

    else if(front == 0){
        printf("Overflow\n");
        return;
    }

    else{
        front--;
    }

    dq[front] = x;
}

void insertRear(int x){

    if(front == -1){
        front = rear = 0;
    }

    else if(rear == MAX-1){
        printf("Overflow\n");
        return;
    }

    else{
        rear++;
    }

    dq[rear] = x;
}

int deleteFront(){

    if(front == -1)
        return -1;

    int val = dq[front];

    if(front == rear)
        front = rear = -1;
    else
        front++;

    return val;
}

int deleteRear(){

    if(front == -1)
        return -1;

    int val = dq[rear];

    if(front == rear)
        front = rear = -1;
    else
        rear--;

    return val;
}

int main(){

    insertRear(10);
    insertRear(20);
    insertFront(5);

    printf("%d\n", deleteFront());
    printf("%d\n", deleteRear());

}