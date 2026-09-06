float av_odd(int *arr, int n)
{
    if(!arr)
        return (-1);
    int sum = 0;
    int i = 0;
    int counter = 0;

    while(i < n)
    {
        if(arr[i] % 2 == 1)
        {
            sum  += arr[i];
            counter++;
        }
        i++;
    }
    return ((float)sum / counter);
}

#include <stdio.h>

int main()
{
    int arr[5] = {1, 4, 84, 2, 8};
    printf("%.2f\n", av_odd(arr, 5));
    return 0;
}