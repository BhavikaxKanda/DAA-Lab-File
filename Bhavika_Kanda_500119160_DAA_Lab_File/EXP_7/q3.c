#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int LCS(char *X, char *Y, int m, int n) {
    int L[m + 1][n + 1];
    int i, j;

    /* Following steps build L[m+1][n+1] in bottom up manner */
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    /* L[m][n] contains length of LCS */
    return L[m][n];
}

int main() {
    char X[] = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
    char Y[] = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
    int m = strlen(X);
    int n = strlen(Y);

    printf("Length of LCS is %d\n", LCS(X, Y, m, n));

    return 0;
}