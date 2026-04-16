#include <stdio.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:\n");

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0, max_len = 0;

    int prefix[1000];
    int index[1000];
    int size = 0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(sum == 0) {
            max_len = i + 1;
        }

        int found = 0;

        for(int j = 0; j < size; j++) {
            if(prefix[j] == sum) {
                found = 1;
                if(i - index[j] > max_len) {
                    max_len = i - index[j];
                }
                break;
            }
        }

        if(!found) {
            prefix[size] = sum;
            index[size] = i;
            size++;
        }
    }

    printf("Length of largest subarray with zero sum: %d\n", max_len);

    return 0;
}