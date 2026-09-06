#include <stdio.h>

int circulararray(int* a, int n, int i)
{
    return a[((i % n) + n) % n];
}

int main()
{
    int a[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int n = 8;

    printf("a[9]  = %d\n", circulararray(a, n, 9));   // 2. eleman = 20
    printf("a[-1] = %d\n", circulararray(a, n, -1));  // son eleman = 80
    printf("a[-2] = %d\n", circulararray(a, n, -2));  // 7. eleman = 70
    printf("a[0]  = %d\n", circulararray(a, n, 0));   // 1. eleman = 10
    printf("a[8]  = %d\n", circulararray(a, n, 8));   // 1. eleman = 10
    printf("a[-9] = %d\n", circulararray(a, n, -9));  // 7. eleman = 70

    return 0;
}