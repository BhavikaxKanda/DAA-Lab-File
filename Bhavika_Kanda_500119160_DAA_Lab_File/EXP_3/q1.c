int sum_recursive(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + sum_recursive(n - 1);
    }
}