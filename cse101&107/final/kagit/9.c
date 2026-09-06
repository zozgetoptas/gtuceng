#include <stdio.h>
int CompareFiles(char *file1_name, char* file2_name)
{
    FILE *file1, *file2;
    int char1, char2;
    file1 = fopen(file1_name, "r");
    if(!file1)
        return 2;
    file2 = fopen(file2_name, "r");
    if(!file2)
    {
        fclose(file1);
        return 2;
    }
    while(1)
    {
        char1 = getc(file1);
        char2 = getc(file2);
        if(char1 != char2)
        {
            fclose(file1);
            fclose(file2);
            return 0;
        }
        if((char1 == EOF) && (char2 == EOF))
        {
            fclose(file1);
            fclose(file2);
            return 1;
        }
    }
}

int main()
{
    int result = CompareFiles("file1.txt", "file2.txt");
    if(result == 1)
        printf("same\n");
    else if(result == 0)
        printf("different\n");
    else
        printf("error\n");
    return 0;
}