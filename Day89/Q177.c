#include <stdio.h>

int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages) return 0;

        if (sum + arr[i] > maxPages) {
            students++;
            sum = arr[i];
            if (students > m) return 0;
        } else {
            sum += arr[i];
        }
    }
    return 1;
}

int allocatePages(int arr[], int n, int m) {
    int low = 0, high = 0, result = 0;

    for (int i = 0; i < n; i++) {
        high += arr[i];
        if (arr[i] > low) low = arr[i];
    }

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int n, m;

    printf("Enter number of books and students: ");
    scanf("%d %d", &n, &m);

    int arr[n];

    printf("Enter pages in each book: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int ans = allocatePages(arr, n, m);
    printf("Minimum maximum pages: %d\n", ans);

    return 0;
}