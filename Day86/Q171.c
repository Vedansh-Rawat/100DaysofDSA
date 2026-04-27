#include <stdio.h>

int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    int low = 0, high = n, ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if ((long long)mid * mid == n) {
            ans = mid;
            break;
        }
        else if ((long long)mid * mid < n) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    printf("Square root: %d", ans);

    return 0;
}