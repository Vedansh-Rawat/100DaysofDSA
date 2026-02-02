#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }

    return maxProfit;
}

int main() {
    int n;

    printf("Enter number of days:\n");
    scanf("%d", &n);

    if (n <= 1) {
        printf("0\n");
        return 0;
    }

    int prices[n];
    printf("Enter stock prices:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    int profit = maxProfit(prices, n);
    printf("Maximum Profit: %d\n", profit);

    return 0;
}
