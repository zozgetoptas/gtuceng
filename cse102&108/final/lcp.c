/*
write a func that takes two strs as input and finds the longest
common prefix (lcp) of the 2 strs. assume that the size of a str is less 
than 100. example: lcp of "destination" and "description" is "des". lcp
of "terminal" and "term" is "term". lcp of "text" and "air" is empty
str "". etc...
*/
#include <stdio.h>

char *lcp(char str1[100], char str2[100])
{
    static char res[100];
    int i = 0;
    int j = 0;
    res[0] = '\0';
    
    while(str1[i] && str2[i])
    {
        if(str1[i] == str2[i])
        {
            res[j] = str1[i];
            j++;
        }
        else
            break;
        i++;
    }
    res[j] = '\0';
    return res;
}
int main()
{
    char str1[100] = "destination";
    char str2[100] = "air";
    char *ret = lcp(str1,str2);
    printf("%s",ret);
}