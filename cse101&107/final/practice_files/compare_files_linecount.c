#include <stdio.h>
#include <string.h>

int compareFiles(FILE *fp1, FILE *fp2, int *lineCount1, int *lineCount2)
{
    if(fp1 == NULL || fp2 == NULL)
        return 2;
    
    char line1[256], line2[256];
    *lineCount1 = 0;
    *lineCount2 = 0;
    
    while(fgets(line1, 256, fp1) != NULL)
    {
        (*lineCount1)++;
        if(fgets(line2, 256, fp2) == NULL)
        {
            (*lineCount2)++;
            return 0; // fp2 daha kısa
        }
        (*lineCount2)++;
        
        if(strcmp(line1, line2) != 0)
            return 0; // Satırlar farklı
    }
    
    // fp1 bitti, fp2'de daha satır varsa
    if(fgets(line2, 256, fp2) != NULL)
        return 0; // fp1 daha kısa
    
    // Satır sayıları eşit ve tüm satırlar aynı
    return 1;
}

int main()
{
    FILE *fp1 = fopen("file1.txt", "r");
    FILE *fp2 = fopen("file2.txt", "r");
    
    if(fp1 == NULL || fp2 == NULL)
    {
        printf("Dosya açılış hatası!\n");
        return 1;
    }
    
    int lineCount1, lineCount2;
    int result = compareFiles(fp1, fp2, &lineCount1, &lineCount2);
    
    printf("File1 satır sayısı: %d\n", lineCount1);
    printf("File2 satır sayısı: %d\n", lineCount2);
    
    if(result == 1)
        printf("Dosyalar tamamen aynı\n");
    else if(result == 0)
        printf("Dosyalar farklı\n");
    else
        printf("Dosya açılış hatası\n");
    
    fclose(fp1);
    fclose(fp2);
    
    return 0;
}