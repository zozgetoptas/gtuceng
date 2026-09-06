#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct course{
    char name[50];
    struct course *prereq[10];
    int size;
}course_t;

typedef struct node{
    course_t *data;
    struct node *next;
}node_t;

typedef struct student{
    char name[30];
    course_t *passed_courses[10];
    int passed_count;
    course_t *to_register[10];
    int register_count;
}student_t;

int getnextline(FILE *fp, char *buffer);
void splitline(char *line, char parts[][10], int *number_of_parts);
course_t *find_course_by_name(node_t *courses, char *name);


node_t *read_input(node_t **courses, char *filename)
{
    node_t *tail = *courses;
    FILE *fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("Dosya açılamadı: %s\n", filename);
        return NULL;
    }

    char buffer[1000];
    while(getnextline(fp, buffer))
    {
        int number_of_parts;
        char parts[11][10];

        splitline(buffer, parts, &number_of_parts);

        if(number_of_parts == 0)
            continue;

        course_t *cr = (course_t *)malloc(sizeof(course_t));
        strcpy(cr->name, parts[0]);
        for(int i = 0; i < number_of_parts - 1; i++)
            cr->prereq[i] = find_course_by_name(*courses, parts[i + 1]);
        cr->size = number_of_parts - 1;

        node_t *temp = (node_t *)malloc(sizeof(node_t));
        temp->data = cr;
        temp->next = NULL;

        if(*courses == NULL)
        {
            *courses = temp;
            tail = *courses;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    fclose(fp);
    return *courses;
}

course_t *find_course_by_name(node_t *courses, char *name)
{
    while(courses != NULL)
    {
        if(strcmp(courses->data->name, name) == 0)
            return courses->data;
        courses = courses->next;
    }
    return NULL;
}

int getnextline(FILE *fp, char *buffer)
{
    if(fp == NULL)
        return 0;
    if(fgets(buffer, 1000, fp) != NULL)
    {
        // \r\n (Windows) veya \n (Unix) satır sonlarını temizle
        buffer[strcspn(buffer, "\r\n")] = '\0';
        return 1;
    }
    return 0;
}

void splitline(char *line, char parts[][10], int *number_of_parts)
{
    *number_of_parts = 0;
    char *copy = (char *)malloc(strlen(line) + 1);
    strcpy(copy, line);
    // \r ve \n artık getnextline'da temizleniyor, sadece boşluk ve tab'a göre böl
    char *token = strtok(copy, " \t");
    while(token != NULL && *number_of_parts < 11)
    {
        strcpy(parts[*number_of_parts], token);
        (*number_of_parts)++;
        token = strtok(NULL, " \t");
    }
    free(copy);
}

int main()
{
    node_t *courses = NULL;
    read_input(&courses, "input.txt");

    char course_name[50];
    printf("Ders adı girin: ");
    scanf("%s", course_name);

    course_t *course = find_course_by_name(courses, course_name);

    if(course == NULL)
        printf("Ders bulunamadı!\n");
    else
    {
        printf("Ders: %s\n", course->name);
        if(course->size == 0)
            printf("Ön Şartlar: Yok\n");
        else
        {
            printf("Ön Şartlar: ");
            for(int i = 0; i < course->size; i++)
                printf("%s ", course->prereq[i]->name);
            printf("\n");
        }
    }

    return 0;
}