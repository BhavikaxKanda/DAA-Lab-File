#include <stdio.h>

void findRowAndColumnSums(int matrix[][100], int rows, int cols) {
    int rowSum[rows], colSum[cols];

    // Initialize row and column sums to 0
    for (int i = 0; i < rows; i++) {
        rowSum[i] = 0;
    }
    for (int i = 0; i < cols; i++) {
        colSum[i] = 0;
    }

    // Calculate row and column sums
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            rowSum[i] += matrix[i][j];
            colSum[j] += matrix[i][j];
        }
    }

    // Print row and column sums
    printf("Row-wise sum: ");
    for (int i = 0; i < rows; i++) {
        printf("%d ", rowSum[i]);
    }
    printf("\n");

    printf("Column-wise sum: ");
    for (int i = 0; i < cols; i++) {
        printf("%d ", colSum[i]);
    }
    printf("\n");
}

int main() {
    int rows, cols;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[100][100];

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]); 
        }
    }

    findRowAndColumnSums(matrix, rows, cols);

    return 0;
}