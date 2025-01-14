#include <stdio.h>

int sumArrayRecursive(int arr[], int n) {
    if (n == 0) {
        return 0;
    } else {
        return arr[n - 1] + sumArrayRecursive(arr, n - 1);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = sumArrayRecursive(arr, n);

    printf("Sum of array elements: %d\n", sum);

    return 0;
}