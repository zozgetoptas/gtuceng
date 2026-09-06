#include <stdio.h>

int main()
{
    int i = 5;
    for(int x = 2; x < 8; x++)
    {
        if(--i == 0)
            x--;
    }
    printf("%d", i);
    return 0;
}