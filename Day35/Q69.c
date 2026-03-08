#include <stdio.h>

#define MAX 100

int main()
{
    int queue[MAX];
    int front = 0, rear = -1;
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &queue[++rear]);
    }

    printf("Queue elements are: ");
    for(int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}