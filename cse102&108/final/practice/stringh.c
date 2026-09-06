#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *a = malloc(10);
    strcpy(a, "ozge");
    strcpy(a, "sa"); 
    printf("%s\n", a);
    //printf("%s", a+2);
    for(int i = 0; i < 5; i++)
        printf("%c   .", a[i]);
}