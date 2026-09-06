#include <string.h>

void reverseString(char *str)
{
    if(!str)
        return;
    int len = strlen(str);
    int i = 0;
    while(i < len / 2)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - 1 - i] = temp;

        i++;
    }
}
#include <stdio.h>

int main()
{
    char str[20] = "zeynepozge";
    reverseString(str);
    printf("%s\n", str);
    return(0);
}