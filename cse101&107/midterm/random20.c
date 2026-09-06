/*
bir arrayi, 30 ile 100 arasında bulunan rastgele 20 integer ile dolduran
ve bu arrayin barındırdığı en küçük ve en büyük sayı arasındaki farkı hesaplayan C kodu
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int greatest_minus_lowest(int *arr)
{
    int i = 1;
    int lowest = arr[0];
    int greatest = arr[0];

    while(i < 20)
    {
        if (arr[i] < lowest)
            lowest = arr[i];
        i++;
    }
    i = 1;
    while(i < 20)
    {
        if (arr[i] > greatest)
            greatest = arr[i];
        i++;
    }
    int result = greatest - lowest;
    return result;
}
int main()
{
    srand(time(NULL));
    int arr[20];
    int i = 0;

    while(i < 20)
    {
        arr[i] = rand() % 71 + 30;
        i++;
    }
    i = 0;
    while(i < 20)
    {
        printf("%d:%d\n", i + 1, arr[i]);
        i++;
    }
    int result = greatest_minus_lowest(arr);
    printf("\nresult: %d\n", result);
    return 0;
}