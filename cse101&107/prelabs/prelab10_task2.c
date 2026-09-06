#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int swap_count_bubble = 0;
int swap_count_quick = 0;

// bubble sort - descending
void bubble_sort(int arr[], int n)
{
    swap_count_bubble = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap_count_bubble++;
            }
        }
    }
}

// quick sort - ascending
void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int i = low - 1;
        
        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                swap_count_quick++;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        swap_count_quick++;
        
        quick_sort(arr, low, i);
        quick_sort(arr, i + 2, high);
    }
}

int main(void)
{
    int sizes[] = {10000, 20000, 30000, 200000, 300000, 500000};
    int num_sizes = 6;

    printf("Sorting Performance Comparison\n");
    printf("==============================\n");
    printf("Array Size    Bubble Sort (ms)    Quick Sort (ms)\n");
    printf("----------------------------------------------\n");

    for (int s = 0; s < num_sizes; s++)
    {
        int n = sizes[s];

        // bubble sort test
        int *arr1 = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            arr1[i] = rand() % n;

        clock_t start_bubble = clock();
        bubble_sort(arr1, n);
        clock_t end_bubble = clock();
        double time_bubble = ((double)(end_bubble - start_bubble) / CLOCKS_PER_SEC) * 1000;

        // quick sort test
        int *arr2 = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            arr2[i] = rand() % n;

        clock_t start_quick = clock();
        quick_sort(arr2, 0, n - 1);
        clock_t end_quick = clock();
        double time_quick = ((double)(end_quick - start_quick) / CLOCKS_PER_SEC) * 1000;

        printf("%-10d    %-16.2f    %.2f\n", n, time_bubble, time_quick);

        free(arr1);
        free(arr2);
    }

    printf("\nThe program is completed!\n");

    return 0;
}
