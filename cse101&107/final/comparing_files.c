#include <stdio.h>

// dosyalardaki satir sayilarini da karsilastir

int CompareFiles(char *fileName1, char *fileName2)
{
    FILE *file1, *file2;
    int char1, char2;
    
    file1 = fopen(fileName1, "r");
    file2 = fopen(fileName2, "r");
    
    if(file1 == NULL || file2 == NULL)
    {
        if(file1 != NULL) 
            fclose(file1);
        if(file2 != NULL)
            fclose(file2);
        return 2;
    }
    
    while(1)
    {
        char1 = fgetc(file1);
        char2 = fgetc(file2);
        
        if(char1 != char2)
        {
            fclose(file1);
            fclose(file2);
            return 0;
        }
        
        if(char1 == EOF && char2 == EOF)
        {
            fclose(file1);
            fclose(file2);
            return 1;
        }
    }
}

int main()
{
    int result;
    char file1[100], file2[100];
    
    printf("first file name: ");
    scanf("%s", file1);
    
    printf("second file name: ");
    scanf("%s", file2);
    
    result = CompareFiles(file1, file2);
    
    if(result == 1)
        printf("IDENTICAL\n");
    else if(result == 0)
        printf("NOT IDENTICAL\n");
    else if(result == 2)
        printf("error opening files\n");
    
    return 0;
}