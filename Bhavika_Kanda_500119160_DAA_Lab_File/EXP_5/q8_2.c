#include <stdio.h>

void moveZeroesToEnd(int arr[], int n) {
    int count = 0;

    // Count non-zero elements
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[count++] = arr[i];
        }
    }

    // Fill remaining positions with zeroes
    while (count < n) {
        arr[count++] = 0;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {0, 1, 0, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    moveZeroesToEnd(arr, n);

    printf("Array after moving zeroes: ");
    printArray(arr, n);

    return 0;
}