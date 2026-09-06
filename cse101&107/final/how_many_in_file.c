#include <stdio.h>

int main()
{
    FILE *file = fopen("the_file.txt", "r");
    int all[256] = {0};
    if(!file)
        return 1;
    unsigned int c;
    int space = 0;
    while((c = getc(file)) != EOF)
    {
        if(c == ' ')
            space++;
        all[c]++;
    }
    fclose(file);
    
    printf("space: %d\n", space);
    
    for(int i = 0; i < 5; i++)
    {
        int max = 0;
        int max_char = -1;
        for(int j = 0; j < 256; j++)
        {
            if(all[j] > max && j != ' ')
            {
                max = all[j];
                max_char = j;
            }
        }
        if(max_char != -1)
        {
            printf("'%c': %d\n", max_char, max);
            all[max_char] = 0;
        }
    }
    
    return 0;
}