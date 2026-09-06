#include <stdio.h>

int calculateF(int n);
int helperF(int current, int a, int b, int c);

int helperF(int current, int a, int b, int c) {
    if (current == 0) return a;
    return helperF(current - 1, b + c, a, b);
}

int calculateF(int n) {
    if (n == 1 || n == 2 || n == 3) return 1;
    return helperF(n - 3, 1, 1, 1);
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("F_%d = %d\n", n, calculateF(n));
    return 0;
}