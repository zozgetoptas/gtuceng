#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char full_name[100];
    long long id;
    char department[50];
    int grade;
} student;

#define FILENAME "StudentEncription.bin"

char encrypt(char ch)
{
    int shift = 12;
    if(ch >= 'A' && ch <= 'Z')
        return ((ch - 'A' + shift) % 26) + 'A';
    else if(ch >= 'a' && ch <= 'z')
        return ((ch - 'a' + shift) % 26) + 'a';
    return ch;
}
char decrypt(char ch)
{
    int shift = 12;
    if(ch >= 'A' && ch <= 'Z')
        return ((ch - 'A' - shift + 26) % 26) + 'A';
    else if(ch >= 'a' && ch <= 'z')
        return ((ch - 'a' - shift + 26) % 26) + 'a';
    return ch;
}
// add a record to file .
void the_create(void)
{
    FILE *file = fopen(FILENAME, "ab"); // add & binary mode
    if (file == NULL)
    {
        printf("file opening failure! Path: %s\n", FILENAME);
        perror("Error");
        return;
    }
    student s;
    printf("name of the student: ");
    fgets(s.full_name, sizeof(s.full_name), stdin);
    s.full_name[strcspn(s.full_name, "\n")] = '\0';
    int i = 0;
    while(s.full_name[i])
    {
        s.full_name[i] = encrypt(s.full_name[i]);
        i++;
    }
    s.full_name[i] = '\0';
    printf("id: ");
    scanf("%lld", &s.id);
    getchar();
    printf("department: ");
    fgets(s.department, sizeof(s.department), stdin);
    s.department[strcspn(s.department, "\n")] = '\0';
    i = 0;
    while(s.department[i])
    {
        s.department[i] = encrypt(s.department[i]);
        i++;
    }
    s.department[i] = '\0';
    printf("grade: ");
    scanf("%d", &s.grade);
    getchar();
    fwrite(&s, sizeof(student), 1, file);
    fclose(file);
    printf("record added successfully!\n");
}

// get a record from file .
void the_get_a_record(void)
{
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL)
    {
        printf("file finding failure!\n");
        return;
    }
    int order;
    printf("enter the order of the record (starting from 1): ");
    scanf("%d", &order);
    getchar();
    student s;
    fseek(file, (order - 1) * sizeof(student), SEEK_SET);
    if (fread(&s, sizeof(student), 1, file) == 1)
    {
        int i = 0;
        while(s.full_name[i])
        {
            s.full_name[i] = decrypt(s.full_name[i]);
            i++;
        }
        s.full_name[i] = '\0';
        printf("\n=== record (order %d) ===\n", order);
        printf("| name       | %s\n", s.full_name);
        printf("| id         | %lld\n", s.id);
        printf("| department | %s\n", s.department);
        printf("| grade      | %d\n", s.grade);
    }
    else
        printf("no record at this order!\n");
    
    fclose(file);
}

// get all records from file .
void the_get_all_records(void)
{
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL)
    {
        printf("file finding failure!\n");
        return;
    }
    
    student s;
    int count = 0;
    
    printf("\n=== all records ===\n");
    while (fread(&s, sizeof(student), 1, file))
    {
        int i = 0;
        while(s.full_name[i])
        {
            s.full_name[i] = decrypt(s.full_name[i]);
            i++;
        }
        s.full_name[i] = '\0';
        i = 0;
        while(s.department[i])
        {
            s.department[i] = decrypt(s.department[i]);
            i++;
        }
        s.department[i] = '\0';
        count++;
        printf("\n| record     | %d\n", count);
        printf("| name       | %s\n", s.full_name);
        printf("| id         | %lld\n", s.id);
        printf("| department | %s\n", s.department);
        printf("| grade      | %d\n", s.grade);
    }
    
    if (count == 0)
        printf("no records in file!\n");
    
    fclose(file);
}

int main(void)
{
    int choice;
    
    while (1)
    {
        printf("\n========== menu ==========\n");
        printf("1. add a record\n");
        printf("2. get a record\n");
        printf("3. get all records\n");
        printf("0. exit\n");
        printf("enter your choice: ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice)
        {
            case 1:
                the_create();
                break;
            case 2:
                the_get_a_record();
                break;
            case 3:
                the_get_all_records();
                break;
            case 0:
                printf("exiting...\n");
                return 0;
            default:
                printf("invalid choice!\n");
        }
    }
}