#include <stdio.h>
#include <stdbool.h>

#define N 8

bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    /* Check this row, column and the diagonals
       from top-left to bottom-right and from
       bottom-left to top-right */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueensUtil(int board[N][N], int col) {
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            if (solveNQueensUtil(board, col + 1))
                return true;

            board[i][col] = 0; // BACKTRACK
        }
    }

    return false;
}

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

int main() {
    int board[N][N] = {{0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}
                    };

    if (solveNQueensUtil(board, 0) == false) {
        printf("Solution does not exist");
        return 0;
    }

    printSolution(board);
    return 0;
}