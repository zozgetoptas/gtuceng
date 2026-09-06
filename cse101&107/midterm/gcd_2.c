#include <stdio.h>

int ft_gcd(int n1, int n2)
{
    int small;
    int big;
    if(n1 == n2)
        return n1;
    if(n1 < n2)
    {
        small = n1;
        big = n2;
    }
    if(n1 > n2)
    {
        small = n2;
        big = n1;
    }
    while(small >= 1)
    {
        if((n1 % small == 0) && (n2 % small == 0))
            return small;
        small--;
    }
}
int main()
{
    printf("%d", ft_gcd(24, 72));
}