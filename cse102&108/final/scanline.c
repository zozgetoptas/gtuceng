#include <stdio.h>
#include <stdlib.h>

char *scanline()
{
    char *dest = malloc(100);  /* stack yerine heap */
    int i, ch;
    i = 0;
    for(ch = getchar(); ch != '\n' && ch != EOF && i < 99; ch = getchar())
        dest[i++] = ch;
    dest[i] = '\0';
    while(ch != '\n' && ch != EOF)
        ch = getchar();
    return dest;
}

int main()
{
    char *line;
    printf("Bir satir girin: ");
    line = scanline();
    printf("Okunan: %s\n", line);
    free(line);
    return 0;
}