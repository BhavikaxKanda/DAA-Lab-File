#include <stdio.h>

int binary_search_recursive(int arr[], int low, int high, int key) {
    if (low > high) {
        return -1; // Key not found
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == key) {
        return mid; // Key found
    } else if (arr[mid] < key) {
        return binary_search_recursive(arr, mid + 1, high, key); // Search right half
    } else {
        return binary_search_recursive(arr, low, mid - 1, key); // Search left half
    }
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    int result = binary_search_recursive(arr, 0, n - 1, key);
    (result == -1) ? printf("Element is not present in array")
                  : printf("Element is present at index %d", result);
    return 0;
}