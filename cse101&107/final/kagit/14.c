int findStringByPointer(char *arr[], int size, char *target)
{
    int i = 0;
    while(i < size)
    {
        if(arr[i] == target)
            return i;
        i++;
    }
    return -1;
}

#include <stdio.h>

int main()
{
    char *arr[5] = {"zeynepzoge", "toptas", "ozgetoptas", "asdfghjkl", "zozge"};
    printf("%d\n", findStringByPointer(arr, 5, "topas"));
    return 0;
}