#include <stdio.h>

int main() {
    int num;

    for (num = 100; num <= 200; num++) {
        if (num % 2 == 0) {
            printf("%d ", num);
        }
    }

    printf("\n");

    return 0;
}