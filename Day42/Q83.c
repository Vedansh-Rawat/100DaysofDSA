#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0;
int rear = -1;

int stack[MAX];
int top = -1;

void enqueue(int x){
    queue[++rear] = x;
}

int dequeue(){
    return queue[front++];
}

void push(int x){
    stack[++top] = x;
}

int pop(){
    return stack[top--];
}

void reverseQueue(){

    while(front <= rear)
        push(dequeue());

    front = 0;
    rear = -1;

    while(top != -1)
        enqueue(pop());
}

int main(){

    enqueue(10);
    enqueue(20);
    enqueue(30);

    reverseQueue();

    while(front <= rear)
        printf("%d ", dequeue());

}