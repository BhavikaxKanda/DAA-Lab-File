#include <stdio.h>
#include <limits.h>

int matrixChainOrder(int p[], int n) {
    int m[n][n];

    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j++) {
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                }
            }
        }
    }

    return m[1][n-1];
}

int main() {
    int arr1[] = {40, 20, 30, 10, 30};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);

    int arr2[] = {10, 30, 5, 60};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    printf("Minimum number of multiplications for arr1: %d\n", matrixChainOrder(arr1, n1));
    printf("Minimum number of multiplications for arr2: %d\n", matrixChainOrder(arr2, n2));

    return 0;
}