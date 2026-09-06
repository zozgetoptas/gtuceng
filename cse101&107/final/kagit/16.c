#include <stdlib.h>
#include <stdio.h>

int *mergeAndSort(int *arr1, int size1, int *arr2, int size2, int *resultSize)
{
    int *new = (int *)malloc((size1 + size2) * sizeof(int));
    if(!new)
        return NULL;
    int i = 0;
    while(i < size1)
    {
        new[i] = arr1[i];
        i++;
    }
    int j = 0;
    while(j < size2)
    {
        new[i] = arr2[j];
        i++;
        j++;
    }
    j = 0;
    int k;
    while(j < i)
    {
        k = j + 1;
        while(k < i)
        {
            if(new[j] > new[k])
            {
                int temp = new[j];
                new[j] = new[k];
                new[k] = temp;
            }
            k++;
        }
        j++;
    }
    return new;
}
int main()
{
    int arr1[4] = {13, 2, 78, 3};
    int arr2[3] = {9, -5, 77};
    int *a = mergeAndSort(arr1, 4, arr2, 3, a);
    int i = 0;
    while(i < 7)
    {
        printf("%d ", a[i]);
        i++;
    }
    return 0;
}