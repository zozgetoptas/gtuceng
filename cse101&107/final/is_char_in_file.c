#include <stdio.h>

int main()
{
    char c, a;
    printf("give me the char to search for: \n");
    scanf(" %c", &c);
    FILE *file = fopen("the_file.txt", "r");
    if(!file)
        return 1;
    while((a = getc(file)) != EOF)
    {
        if(a == c)
        {
            printf("there is %c in the file\n", c);
            fclose(file);
            return 0;
        }
    }
    fclose(file);
    printf("there is no %c in the file\n", c);
    return 0;
}