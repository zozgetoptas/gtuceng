#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int ret = 0;
    int i = 7;
    int d = 1;
    char str[8];
    printf("binary:\n");
    scanf("%s", str);
    int n = atoi(str);
    while(i >= 0)
    {
        ret += (str[i] - 48) * d;
        d *= 2;
        i --;
    }
    printf("decimal: %d\n", ret);
    return (0);
}