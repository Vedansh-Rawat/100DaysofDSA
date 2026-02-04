#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    for (int j = 0; j < numsSize; j++){
        if (nums[j] != val){
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}

int main() {
    int n;
    printf("Enter length of array: \n");
    scanf("%d", &n);

    int nums[n];
    printf("Enter array elements: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int val;
    printf("Enter element to remove: \n");
    scanf("%d", &val);

    int k = removeElement(nums, n, val);

    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}