#include <stdio.h>

int main()
{
    int n;
    printf("input:");
    scanf("%d", &n);

    int i = 2;
    while(i < n)
    {
        if(n % i == 0)
            break;
        i++;
    }
    if(i == n)
    {
        printf("asal");
        return 0;
    }
    printf("asal değil\n");
}