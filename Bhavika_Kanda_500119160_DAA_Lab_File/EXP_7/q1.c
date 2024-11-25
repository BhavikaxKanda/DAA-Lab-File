#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n) {
    int K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main() {
    int val1[] = {60, 100, 120};
    int wt1[] = {10, 20, 30};
    int W1 = 50;
    int n1 = sizeof(val1) / sizeof(val1[0]);

    int val2[] = {2, 3, 1, 4};
    int wt2[] = {3, 4, 6, 5};
    int W2 = 8;
    int n2 = sizeof(val2) / sizeof(val2[0]);

    int val3[] = {2, 5, 8, 1};
    int wt3[] = {10, 15, 6, 9};
    int W3 = 50;
    int n3 = sizeof(val3) / sizeof(val3[0]);

    printf("Knapsack value for first set: %d\n", knapSack(W1, wt1, val1, n1));
    printf("Knapsack value for second set: %d\n", knapSack(W2, wt2, val2, n2));
    printf("Knapsack value for third set: %d\n", knapSack(W3, wt3, val3, n3));

    return 0;
}