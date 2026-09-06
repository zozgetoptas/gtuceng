/*
some of the elements violate the ascending (increasing) order of an array.
write a function which finds these elements and removes them. example:
a[] = {1, 2, 3, 2, 3, 4, 1, 5}. 4th and 7th elements should be removed.
after the function call: a[] = {1, 2, 3, 3, 4, 5, 0, 0}. the rest of
elements are shifted towards the beginning in order to occupy the empty
space. the tail is padded with a 0s. assume: the elements to be removed
are separated by at least two numbers which are in ascending order. assume:
the first two numbers are in ascending order.
*/

void violate(int *a, int n)
{
    int j = 0;
    for(int i = 0; i < n - 1; i++)
    {
        if(a[i] > a[i + 1])
        {
            for(j = i + 1; j < n - 1; j++)
                a[j] = a[j + 1];
            a[n - 1] = 0;
        }
    }
}

#include <stdio.h>

int main()
{
    int a[] = {1, 2, 3, 2, 3, 4, 1, 5};
    int n = 8;
    
    printf("Before: ");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    
    violate(a, n);
    
    printf("After: ");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    
    return 0;
}