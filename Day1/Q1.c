#include <stdio.h>

int main(){
    int n;
    printf("Enter the length of the array: \n");
    scanf("%d", &n);
    
    int array[n+1];

    printf("Enter array elements: \n");
    for (int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }

    int pos;
    printf("Enter position you want to enter the new element to: \n");
    scanf("%d", &pos);
    pos = pos - 1;

    int x;
    printf("Enter the element you want to add: \n");
    scanf("%d", &x);

    for (int i = n; i > pos; i--){
        array[i] = array[i - 1];
    }
    array[pos] = x;

    for (int i = 0; i < n + 1; i++){
        printf("%d ", array[i]);
    }

}