#include <stdio.h>

int main()
{
    int stack[100];
    int top = -1;
    int n, m;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements to push: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &stack[++top]);
    }

    printf("Enter number of pops: ");
    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        if(top >= 0)
            top--;
    }

    printf("Remaining stack elements (top to bottom): ");
    for(int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }

    return 0;
}