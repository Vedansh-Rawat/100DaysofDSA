#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1, size = 0;

void enqueue(int x)
{
    rear = (rear + 1) % MAX;
    queue[rear] = x;
    size++;
}

void dequeue()
{
    if(size == 0)
        return;

    front = (front + 1) % MAX;
}

void display()
{
    int i = front;
    int count = size;

    printf("Queue elements: ");

    while(count--)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }
}

int main()
{
    int n, m, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    printf("Enter number of dequeue operations: ");
    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        int temp = queue[front];
        dequeue();
        enqueue(temp);   
    }

    display();

    return 0;
}