#include <stdio.h>

int get_min_range(int list[], int first, int last)
{
    int i, index_of_min;
    index_of_min = first;
    for (i = first + 1; i <= last; ++i)
    {
        if (list[i] < list[index_of_min])
            index_of_min = i;
    }
    return index_of_min;
}

void select_sort(int list[], int n)
{
    int fill, temp, index_of_min;
    for (fill = 0; fill < n - 1; ++fill)
    {
        index_of_min = get_min_range(list, fill, n - 1);
        if (fill != index_of_min)
        {
            temp = list[index_of_min];
            list[index_of_min] = list[fill];
            list[fill] = temp;
        }
    }
}

int main(void)
{
    int i;
    int dizi[] = {64, 25, 12, 22, 11};
    int n = sizeof(dizi) / sizeof(dizi[0]);

    printf("Siralama oncesi: ");
    for (i = 0; i < n; ++i)
        printf("%d ", dizi[i]);
    printf("\n");

    select_sort(dizi, n);

    printf("Siralama sonrasi: ");
    for (i = 0; i < n; ++i)
        printf("%d ", dizi[i]);
    printf("\n");

    return 0;
}