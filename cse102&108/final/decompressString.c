/*
write a c func names decompressString that, given a possibly compressed
representation of character string prints an uncompressed version of the
character string. the compressed representaiton is deteermined by
counting the lengths of runs of a single char. examples:
1a4b2c1d5e1f --> abbbbccdeeeeef
1a --> a
26z --> zzzzzzzzzzzzzzzzzzzzzzzzzz etc
*/

#include <stdlib.h>
#include <stdio.h>

void decompressString(char *str)
{
    int repeat;
    char number_str[100];
    int i = 0;
    int j;
    while(str[i])
    {
        j = 0;
        while(str[i] <= '9' && str[i] >= '0')
        {
            number_str[j] = str[i];
            j++;
            i++;
        }
        number_str[j] = '\0';
        repeat = atoi(number_str);
        for(int k = 0; k < repeat; k++)
            printf("%c", str[i]);
        i++;
    }
}

int main()
{
    decompressString("1a4b2c1d5e1f");
}