#include <stdio.h>

int missingNum(int *arr, int size) {
    long long n = size + 1;
    long long expectedSum = n * (n+1) / 2;
    long long actualSum = 0;
    
    for (int i = 0; i < size; i++){
        actualSum += arr[i];
    }
    
    return expectedSum - actualSum;
    
}

int main(){
    int n;
    printf("Enter total numbers: \n");
    scanf("%d", &n);

    int arr[n - 1];

    printf("Enter array elements: \n");
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
    }

    int missing = missingNum(arr, n - 1);

    printf("Missing Number: %d", missing);
}