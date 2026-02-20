#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if(n < 2) {
        printf("At least two elements required\n");
        return 0;
    }

    int arr[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;

    int minSum = INT_MAX;
    int first = arr[left], second = arr[right];

    while(left < right) {

        int sum = arr[left] + arr[right];

        if(abs(sum) < abs(minSum)) {
            minSum = sum;
            first = arr[left];
            second = arr[right];
        }

        if(sum < 0)
            left++;
        else
            right--;
    }

    printf("Pair closest to zero: %d %d\n", first, second);

    return 0;
}