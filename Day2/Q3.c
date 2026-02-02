#include <stdio.h>

int main(){
    int n;
    printf("Enter the length of the array:\n");
    scanf("%d", &n);
    
    int array[n];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }

    int pos;
    printf("Enter position to delete:\n");
    scanf("%d", &pos);

    if (pos < 1 || pos > n){
        printf("Invalid Position.");
        return 0;
    }

    for (int i = pos - 1; i < n - 1; i++){
        array[i] = array[i + 1];
    }

    n--;

    printf("Array after deletion:\n");
    for (int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }

    return 0;
}
