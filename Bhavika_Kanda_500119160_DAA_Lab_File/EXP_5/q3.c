#include <stdio.h>

void toLowerCase(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
        i++;
    }
}

int main() {
    char str[] = "HELLO WORLD";
    toLowerCase(str);
    printf("%s\n", str);
    return 0;
}