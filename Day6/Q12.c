#include <stdio.h>

int main() {
    int n;
    printf("Enter array size:\n");
    scanf("%d", &n);

    int nums[n];
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int k = 0;  


    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            nums[k] = nums[i];
            k++;
        }
    }

    for (int i = k; i < n; i++) {
        nums[i] = 0;
    }

    printf("Array after moving zeroes:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}