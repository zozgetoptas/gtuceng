#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *c = (char *)calloc(100, sizeof(char));
    strcpy(c, "jay");
    char *t = c;
    char *b = c;
    while(*t != '\0')
    {
        printf("%s ", b);
        strcpy(c++, "z");
        printf("%s ", c-1);
        t = t+2;
    }

}