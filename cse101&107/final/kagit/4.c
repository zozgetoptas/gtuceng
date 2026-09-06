#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int out(int *arr)
{
    int low, great;
    low = arr[0];
    great = arr[0];
    int i = 1;
    while(i < 20)
    {
        if(arr[i] < low)
            low = arr[i];
        if(arr[i] > great)
            great = arr[i];
        i++;
    }
    return ( great - low);
}

void print_arr(int *arr)
{
    printf("numbers: ");
    int i = 0;
    while(i < 20)
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
}


int main()
{
    srand(time(NULL));
    int arr[20];
    int i = 0;

    while(i < 20)
    {
        arr[i] = (rand() % 71) + 30;
        i++;
    }
    print_arr(arr);
    printf("%d\n", out(arr));

    return 0;
}