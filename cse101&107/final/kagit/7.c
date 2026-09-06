#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;
    printf("a, b, c: \n");
    scanf("%d %d %d", &a, &b, &c);
    int delta = (b * b) - (4 * a * c);
    if(delta == 0)
    {
        printf("1 reel root\n");
        int root = (-1 * b) / (2 * a);
        printf("and it is: %d\n", root);
    }
    else if(delta < 0)
        printf("no reel roots\n");
    else
    {
        int root1 = ((-1 * b) - sqrt(delta)) / (2 * a);
        int root2 = ((-1 * b) + sqrt(delta)) / (2 * a);
        printf("2 reel roots\nand they are %d & %d\n", root1, root2);
    }
    return 0;
}