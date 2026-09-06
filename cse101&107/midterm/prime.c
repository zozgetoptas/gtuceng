#include <stdio.h>
int is_prime(int n)
{
    int i = 2;
    while(i < n)
    {
        if(n % i == 0)
            return 0;
        i++;
    }
    return 1;
}
int main()
{
    int i = 2;
    while(i <= 100)
    {
        if(is_prime(i))
            printf("%d\n", i);
        i++;
    }
}