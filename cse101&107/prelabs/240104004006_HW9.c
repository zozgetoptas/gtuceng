#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char full_name[100];
    long long id;
    char department[50];
    int grade;
} student;

#define FILENAME "Student.bin"

// add a record to file
void the_create(void)
{
    FILE *file = fopen(FILENAME, "ab"); // add & binary mode
    if (file == NULL)
    {
        printf("file opening failure!\n");
        return;
    }
    student s;
    printf("name of the student: ");
    fgets(s.full_name, sizeof(s.full_name), stdin);
    s.full_name[strcspn(s.full_name, "\n")] = '\0';
    printf("id: ");
    scanf("%lld", &s.id);
    getchar();
    printf("department: ");
    fgets(s.department, sizeof(s.department), stdin);
    s.department[strcspn(s.department, "\n")] = '\0';
    printf("grade: ");
    scanf("%d", &s.grade);
    getchar();
    fwrite(&s, sizeof(student), 1, file);
    fclose(file);
    printf("record added successfully!\n");
}

// search for a record
void the_search(void)
{
    FILE *file = fopen(FILENAME, "rb"); // read & binary mode
    if (file == NULL)
    {
        printf("file finding failure!\n");
        return;
    }
    long long search_id;
    printf("id to to be found: ");
    scanf("%lld", &search_id);
    getchar();
    student s;
    int found = 0;   
    while (fread(&s, sizeof(student), 1, file))
    {
        if (s.id == search_id)
        {
            printf("\n=== record is found ===\n");
            printf("| name       | %s\n", s.full_name);
            printf("| id         | %lld\n", s.id);
            printf("| department | %s\n", s.department);
            printf("| grade      | %d\n", s.grade);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("no such record is found!\n"); 
    fclose(file);
}

// update a record
void the_update(void)
{
    FILE *file = fopen(FILENAME, "r+b"); // read and write & binary mode
    if (file == NULL)
    {
        printf("file finding failure!\n");
        return;
    } 
    long long search_id;
    printf("enter the order of the record (starting from 1): ");
    int order;
    scanf("%d", &order);
    getchar();
    
    student s;
    fseek(file, (order - 1) * sizeof(student), SEEK_SET);
    
    if (fread(&s, sizeof(student), 1, file) == 1)
    {
        printf("\n=== current record ===\n");
        printf("| name       | %s\n", s.full_name);
        printf("| id         | %lld\n", s.id);
        printf("| department | %s\n", s.department);
        printf("| grade      | %d\n", s.grade);
        printf("\n=== new informations about the record ===\n");
        printf("new name: ");
        fgets(s.full_name, sizeof(s.full_name), stdin);
        s.full_name[strcspn(s.full_name, "\n")] = '\0';
        printf("new department: ");
        fgets(s.department, sizeof(s.department), stdin);
        s.department[strcspn(s.department, "\n")] = '\0';
        printf("new grade: ");
        scanf("%d", &s.grade);
        fseek(file, -sizeof(student), SEEK_CUR);
        fwrite(&s, sizeof(student), 1, file);
        printf("record has been updated successfully!\n");
    }
    else
        printf("no record at this order!\n");
    fclose(file);
}

// delete a record
void the_delete(void)
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
    FILE *temp_file = fopen("temp.bin", "wb");
    student s;
    int count = 0;
    int found = 0;
    while (fread(&s, sizeof(student), 1, file))
    {
        count++;
        if (count != order)
            fwrite(&s, sizeof(student), 1, temp_file);
        else
            found = 1;
    }
    fclose(file);
    fclose(temp_file);
    
    if (found)
    {
        remove(FILENAME);
        rename("temp.bin", FILENAME);
        printf("record deleted successfully!\n");
    }
    else 
    {
        printf("no record at this order!\n");
        remove("temp.bin");
    }
}

// get a record from file
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

// get all records from file
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
        printf("2. search for a record\n");
        printf("3. update a record\n");
        printf("4. delete a record\n");
        printf("5. get a record\n");
        printf("6. get all records\n");
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
                the_search();
                break;
            case 3:
                the_update();
                break;
            case 4:
                the_delete();
                break;
            case 5:
                the_get_a_record();
                break;
            case 6:
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
