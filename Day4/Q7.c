#include <stdio.h>

int main(){
    int n;
    printf("Enter length of array: \n");
    scanf("%d", &n);

    int arr[n];
    
    printf("Enter array elements: \n");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int left = 0, right = n - 1;
    while (left < right){
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }

    
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

}