#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c;
    int flag = 0; // state variable: 0 = plain text, 1 = inside a tag
    FILE *fp = fopen("labwork6.html", "r"); // opens the HTML file in read mode
    if(!fp)
    {
        perror("failed to open labwork6.html.\n"); 
        return (1);
    }
    FILE *out = fopen("out.txt", "w+"); // opens the output file in write mode
    if(!out)
    {
        perror("failed to open out.txt.\n");
        fclose(fp);
        return (1);
    }
    while((c = fgetc(fp)) != EOF)
    {
        if(c == '<')
            flag = 1; // set flag 1, do not print the character yet
        if(flag == 0)
            fputc(c, out); // if flag is 0 write the character to the output file
        if(c == '>' && flag == 1)
            flag = 0;
    }
    fclose(fp);
    fclose(out);

    return(0); // success
}