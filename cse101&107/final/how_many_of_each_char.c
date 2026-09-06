#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    int count[256] = {0};
    int i = 0;
    
    printf("give a string: \n");
    fgets(input, sizeof(input), stdin);
    
    input[strcspn(input, "\n")] = '\0';
    while(input[i])
    {
        if(input[i] != ' ')
            count[(unsigned char)input[i]]++;
        i++;
    }
    
    printf("\ncounts for chars:\n");
    for(i = 0; i < 256; i++)
    {
        if(count[i] > 0)
            printf("'%c': %d\n", (char)i, count[i]);
    }
    
    return 0;
}