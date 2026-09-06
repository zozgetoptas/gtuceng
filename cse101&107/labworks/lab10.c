#include <stddef.h>

size_t ft_strlen(const char *str)
{
    if(!str)
        return 0;
    size_t i = 0;
    while(str[i])
        i++;
    return i;
}
int ft_strcmp(const char *s1, const char *s2)
{
    if(!s1 || !s2)
        return 1;
    int i = 0;
    while(s1 && s2 && s1[i] == s2[i])
        i++;
    return(s1[i] - s2[i]);
}