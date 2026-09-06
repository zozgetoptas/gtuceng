#include <stdio.h>

typedef struct t_student
{
    char name[20];
    int grade;
} student;

int main()
{
    student s[20];
    FILE *file = fopen("name_note.txt", "r");
    if(!file)
        return 1;
    int count = 0;
    while(fscanf(file, "%s %d", s[count].name, &s[count].grade) == 2)
        count++;
    for(int i = 0; i < count; i++)
    {
        for(int j = i + 1; j < count; j++)
        {
            if(s[i].grade > s[j].grade)
            {
                student temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    FILE *best = fopen("best5.txt", "w");
    if(!best)
        return 1;
    FILE *worst = fopen("worst5.txt", "w");
    if(!worst)
        return 1;

    for(int i = 1; i <= 5; i++)
        fprintf(best, "%s %d\n", s[count - i].name, s[count - i].grade);
    for(int i = 0; i < 5; i++)
        fprintf(worst, "%s %d\n", s[i].name, s[i].grade);
    
    fclose(file);
    fclose(best);
    fclose(worst);
    
    return 0;
}