#include <stdio.h>

struct Item {
    int value, weight;
};

// Utility function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Greedy function to solve the fractional knapsack problem
double fractionalKnapsack(int W, struct Item arr[], int n) {
    // Sort items in decreasing order of value per unit weight
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((double)arr[j].value / arr[j].weight < (double)arr[j + 1].value / arr[j + 1].weight) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }

    double totalValue = 0.0;
    int curWeight = 0;

    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            totalValue += arr[i].value;
        } else {
            int remainingWeight = W - curWeight;
            double fraction = (double)remainingWeight / arr[i].weight;
            totalValue += arr[i].value * fraction;
            break;
        }
    }

    return totalValue;
}

int main() {
    int W = 50; // Weight of knapsack
    struct Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function call
    printf("Maximum value in Knapsack = %.2f", fractionalKnapsack(W, arr, n));
    return 0;
}