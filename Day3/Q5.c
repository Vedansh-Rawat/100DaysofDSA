#include <stdio.h>

int main(){
    int n, k;
    int comp = 0;
    int found = -1;

    printf("Enter array size: \n");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements: \n");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter key: \n");
    scanf("%d", &k);

    for (int i = 0; i < n; i++){
        comp++;
        if (arr[i] == k){
            found = i;
            break;
        }
    }

    if (found != -1){
        printf("Found at index %d.\n", found);
    }
    else{
        printf("Not found.\n");
    }

    printf("Comparisons: %d\n", comp);
}