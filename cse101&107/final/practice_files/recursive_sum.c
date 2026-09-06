#include <stdio.h>
int sum(int *arr, int n)
{
    if(n <= 0)
        return 0;
    return (arr[n - 1] + sum(arr, n - 1));
}
int main()
{
    int arr[5] = {17, 25, 32, 8, 91};
    printf("%d\n", sum(arr, 5));
    return 0;
}