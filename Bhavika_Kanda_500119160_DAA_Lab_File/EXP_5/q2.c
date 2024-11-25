#include <stdio.h>

void insertElement(int arr[], int n, int element, int pos) {
    if (pos < 0 || pos > n) {
        printf("Invalid position\n");
        return;
    }

    // Shift elements to the right to create space for the new element
    for (int i = n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }

    arr[pos] = element;
}

void deleteElement(int arr[], int n, int pos) {
    if (pos < 0 || pos >= n) {
        printf("Invalid position\n");
        return;
    }

    // Shift elements to the left to fill the gap
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Decrease the size of the array
    n--;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original 1  array: ");
    printArray(arr, n);

    int element = 10;
    int insertPos = 2;
    insertElement(arr, n, element, insertPos);
    n++; // Increase the size of the array after insertion

    printf("Array after insertion: ");
    printArray(arr, n);

    int deletePos = 3;
    deleteElement(arr, n, deletePos);
    n--; // Decrease the size of the array after deletion

    printf("Array after deletion: ");
    printArray(arr, n);

    return 0;
}