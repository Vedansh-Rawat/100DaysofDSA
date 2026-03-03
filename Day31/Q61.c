#include <stdio.h>

#define MAX 100

int main()
{
    int stack[MAX];
    int top = -1;
    int n;

    printf("Enter number of operations: ");
    scanf("%d", &n);

    while(n--)
    {
        int op;

        printf("\nEnter operation (1-Push, 2-Pop, 3-Display): ");
        scanf("%d", &op);

        if(op == 1)
        {
            int val;
            printf("Enter value to push: ");
            scanf("%d", &val);

            if(top == MAX - 1)
            {
                printf("Stack Overflow\n");
            }
            else
            {
                stack[++top] = val;
                printf("%d pushed into stack\n", val);
            }
        }
        else if(op == 2)
        {
            if(top == -1)
            {
                printf("Stack Underflow\n");
            }
            else
            {
                printf("Popped element: %d\n", stack[top--]);
            }
        }
        else if(op == 3)
        {
            if(top == -1)
            {
                printf("Stack is Empty\n");
            }
            else
            {
                printf("Stack elements (Top to Bottom): ");
                for(int i = top; i >= 0; i--)
                {
                    printf("%d ", stack[i]);
                }
                printf("\n");
            }
        }
        else
        {
            printf("Invalid operation\n");
        }
    }

    return 0;
}