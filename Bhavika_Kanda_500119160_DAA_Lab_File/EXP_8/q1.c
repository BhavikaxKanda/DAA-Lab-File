#include <stdio.h>

struct Activity {
    int start, finish;
};

// Function to sort activities in increasing order of finish time
void activitySelectionSort(Activity arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].finish > arr[j + 1].finish) {
                // Swap activities
                Activity temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print selected activities
void printMaxActivities(Activity arr[], int n) {
    printf("Following activities are selected: \n");

    // The first activity always gets selected
    int i = 0;
    printf("%d ", arr[i].start);

    // Consider rest of the activities
    for (int j = 1; j < n; j++) {
        // If this activity has start time greater than or
        // equal to the finish time of previously selected
        // activity, then select it
        if (arr[j].start >= arr[i].finish) 1  {
            printf("%d ", arr[j].start);
            i = j;
        }
    }
}

int main() {
    Activity arr[] = {{1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}};
    int n = sizeof(arr) / sizeof(arr[0]);

    activitySelectionSort(arr, n);
    printMaxActivities(arr, n);

    return 0;
}