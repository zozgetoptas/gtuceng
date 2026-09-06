#include <stdio.h>

/*
for data compression and other purposes, we often need to look for runs
(or sequences) of repeated characters in data. for example, in the str
abbbbccdeeeeef, there is a run of 4 bs, a run of 2 cs and a run of 5 es. we
also consider that the a, the d, and the f are all runs of length 1.
write a c func named compressString that, given an input character str,
prints a possibly compressed representation of the input character str, the 
new representation is determined by counting the lenghts of runs of a
single char, as demonstrated below:
given a str abbbbccdeeeeef, compressString prints 1a4b2c1d5e1f
a --> 1a
zzzzzzzzzzzzzzzzzzzzzzzzzz --> 26z
xxbbbxx --> 2x3b2x
aaAa --> 2a1A1a
"" --> ""
*/
void compressString(char *str)
{
    int i = 0;
    while(str[i])
    {
        int count = 1;
        char current = str[i];
        
        while(str[i+1] == current)
        {
            count++;
            i++;
        }
        
        printf("%d%c", count, current);
        i++;
    }
}

int main()
{
    compressString("sdfghjgggt");
    return 0;
}