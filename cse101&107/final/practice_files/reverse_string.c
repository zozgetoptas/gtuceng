#include <stdio.h>
void reverse_str(char *str)
{
    if(!str)
        return;
    char *start = str, *end = str;
    while(*end)
        end++;
    end--;
    char temp;
    while(start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;
        end--;
        start++;
    }
}
int main()
{
    char str[20] = "zeynepozge";
    reverse_str(str);
    printf("%s", str);
    return 0;
}