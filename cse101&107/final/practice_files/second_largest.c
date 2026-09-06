#include <stdio.h>
#include <limits.h>

void find_second_largest(int arr[], int size)
{
    if(size < 2)
        return;
    int first_largest = INT_MIN;
    int second_largest = INT_MAX;
    int i = 0;
    while(i < size)
    {
        if(arr[i] > first_largest)
        {
            second_largest = first_largest;
            first_largest = arr[i];
        }
        else if(arr[i] > second_largest)
            second_largest = arr[i];
        i++;
    }
    if(second_largest == INT_MIN)
        printf("no second large\n");
    else
        printf("first largest:%d\nsecond large:%d\n", first_largest, second_largest);
}

int main()
{
    int arr[5] = {4, 80, 7, 6, 13};
    find_second_largest(arr, 5);
    return 0;
}