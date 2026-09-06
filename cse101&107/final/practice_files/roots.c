// b^2 -4ac
#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;
    printf("a: \n");
    scanf("%d", &a);
    printf("b: \n");
    scanf("%d", &b);
    printf("c: \n");
    scanf("%d", &c);
    int delta = b*b - (4*a*c);
    if(delta < 0)
    {
        printf("no reel root!\n");
        return 0;
    }
    else
    {
        if(delta == 0)
        {
            printf("only 1 reel root!\n");
            printf("and it is: %d\n", ((-1)*b) / (2*a));
        }
        else
        {
            printf("2 reel roots!\n");
            printf("first one is: %d\n", (int)(((-1)*b) - sqrt(delta)) / (2*a));
            printf("second one is: %d\n", (int)(((-1)*b) + sqrt(delta)) / (2*a));
        }
    }
    return 0;
}