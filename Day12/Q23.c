#include <stdio.h>

int main() {
    int m, n;
    printf("Enter matrix size: \n");
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    printf("Enter matrix elements: \n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                printf("Not a Symmetric Matrix");
                return 0;
            }
        }
    }

    printf("Symmetric Matrix");
    return 0;
}