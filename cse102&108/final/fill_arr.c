#include <stdio.h>

#define A_SIZE 20
#define SENT -1.0

void fill_to_sentinel(int dbl_max, double sentinel, double dbl_arr[], int *dbl_sizep)
{
    double data;
    int i, status;
    i = 0;
    status = scanf("%lf", &data);
    while(status == 1 && data != sentinel && i < dbl_max)
    {
        dbl_arr[i] = data;
        ++i;
        status = scanf("%lf", &data);
    }
    if(status != 1)
    {
        printf("\n*** error in data format ***\n");
        printf("*** using first %d data values ***\n", i);
    }
    else if(data != sentinel)
    {
        printf("\n*** error : too much data before sentinel ***\n");
        printf("*** using first %d data values ***\n", i);
    }
    *dbl_sizep = i;
}

int main()
{
    double arr[A_SIZE];
    int in_use, i;
    fill_to_sentinel(A_SIZE, SENT, arr, &in_use);

    printf("list of data values\n");
    for(i = 0; i < in_use; ++i)
        printf("%13.3f\n", arr[i]);
    return 0;
}