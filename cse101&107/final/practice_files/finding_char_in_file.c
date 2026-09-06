#include <stdio.h>
int main()
{
    printf("file name:\n");
    char file_name[50];
    char ch;
    scanf("%s", file_name);
    printf("char to look for:\n");
    scanf(" %c", &ch);
    FILE *file = fopen(file_name, "r");
    if(!file)
        return 1;
    int chr;
    while(1)
    {
        chr = getc(file);
        if(chr == ch)
        {
            printf("found it!\n");
            fclose(file);
            return 0;
        }
        if(chr == EOF)
        {
            fclose(file);
            printf("none\n");
            return 0;
        }
    }
}