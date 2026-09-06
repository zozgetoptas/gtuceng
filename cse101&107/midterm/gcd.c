#include <stdio.h>

int ft_gcd(int n1, int n2)
{
    int result = 1;
    int i = 2;

    while(i <= n1 && i <= n2)
    {
        if ((n1 % i == 0) && (n2 % i == 0))
            result = i;
        i++;
    }
    return result;
}
int ft_lcm(int n1, int n2)
{
    int result;

    if(n1 == n2)
        return n1;
    if(n1 < n2)
        result = n2;
    else
        result = n1;
    while(1)
    {
        if((result % n1 == 0) && (result % n2 == 0))
            return result;
        result++;
    }
}


int main(void)
{
    //printf("%d", ft_gcd(18, 45));
    printf("%d", ft_lcm(18, 45));
    return 0;
}