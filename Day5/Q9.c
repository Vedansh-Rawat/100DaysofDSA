#include <stdio.h>

int main() {
    int p, q;

    printf("Enter number of entries in server log 1:\n");
    scanf("%d", &p);

    int A[p];

    printf("Enter arrival times for server log 1:\n");
    for (int i = 0; i < p; i++) {
        scanf("%d", &A[i]);
    }

    printf("Enter number of entries in server log 2:\n");
    scanf("%d", &q);

    int B[q];

    printf("Enter arrival times for server log 2:\n");
    for (int i = 0; i < q; i++) {
        scanf("%d", &B[i]);
    }

    int i = 0, j = 0;

    printf("Merged arrival log:\n");

    while (i < p && j < q) {
        if (A[i] <= B[j]) {
            printf("%d ", A[i]);
            i++;
        } else {
            printf("%d ", B[j]);
            j++;
        }
    }

    while (i < p) {
        printf("%d ", A[i]);
        i++;
    }

    while (j < q) {
        printf("%d ", B[j]);
        j++;
    }

    return 0;
}