/*
write a recursive func. which returns the count of even
numbers in an int arr
*/
#include <stdio.h>

int count_evens(int *arr, int size, int i)
{
    if(i < size)
    {
        if(arr[i] % 2 == 0)
            return (1 + count_evens(arr, size, i + 1));
        else
            return count_evens(arr, size, i + 1);
    }
    return 0;
}
int main()
{
    int arr[5] = {238, 5, 67, 8, 34};
    printf("%d\n", count_evens(arr, 5, 0));
}
