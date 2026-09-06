#include <stdio.h>

int main()
{
    char str[100];
    int all[256] = {0};
    printf("string: \n");
    scanf("%s", str);
    int i = 0;
    while(str[i])
    {
        all[str[i]]++;
        i++;
    }
    i = 0;
    while(i < 256)
    {
        if(all[i] != 0)
        {
            printf("%c %d\n", (char)i, all[i]);
        }
        i++;
    }
    return 0;
}