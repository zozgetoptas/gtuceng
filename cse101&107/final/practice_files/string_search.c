#include <stdio.h>
#include <string.h>

int compare(char *str, char **arr)
{
    int i = 0;
    while(arr[i])
    {
        if(strcmp(arr[i], str) == 0)
        {
            printf("found it!\n");
            return 1;
        }
        i++;
    }
    return 0;
}

int main()
{
    char *words[] = {"hello", "world", "test", "kanka", NULL};
    
    if(compare("hello", words))
        printf("yes\n");
    else
        printf("no\n");
    
    if(compare("xyz", words))
        printf("yes\n");
    else
        printf("no\n");
    
    return 0;
}