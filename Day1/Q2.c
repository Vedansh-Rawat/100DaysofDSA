#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numSize, int target, int* returnSize){
    int* result = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < numSize; i++){
        for (int j = i+1; j < numSize; j++){
            if (nums[i] + nums[j] == target){
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }

    *returnSize = 0;
    return NULL;
}

int main(){
    int numSize, target;

    printf("Enter number of elements:\n");
    scanf("%d", &numSize);

    if (numSize < 2) {
        printf("Need at least 2 elements\n");
        return 0;
    }

    int* nums = (int*)malloc(numSize * sizeof(int));

    printf("Enter array elements:\n");
    for (int i = 0; i < numSize; i++){
        scanf("%d", &nums[i]);
    }

    printf("Enter target:\n");
    scanf("%d", &target);

    int returnSize = 0;
    int* result = twoSum(nums, numSize, target, &returnSize);

    if (returnSize == 2){
        printf("Index: %d %d\n", result[0], result[1]);
        printf("Values: %d %d\n", nums[result[0]], nums[result[1]]);
        free(result);
    } else {
        printf("No solution.\n");
    }

    free(nums);
    return 0;
}
