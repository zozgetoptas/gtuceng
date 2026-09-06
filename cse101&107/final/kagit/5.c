typedef struct t_student{
    char name[10];
    int g1;
    int g2;
    int g3;
    int g4;
}student;

int is_passed(int grade)
{
    if(grade >= 53)
        return 1;
    return 0;
}

#include <stdio.h>

int main()
{
    FILE *scores = fopen("scores.txt", "r");
    if(!scores)
        return 1;
    FILE *pass, *fail;
    pass = fopen("A.txt", "w");
    if(!pass)
    {
        fclose(scores);
        return 1;
    }
    fail = fopen("B.txt", "w");
    if(!fail)
    {
        fclose(scores);
        fclose(pass);
        return 1;
    }
    student students[5];
    int i = 0;
    while(fscanf(scores, "%s %d %d %d %d", students[i].name, &students[i].g1, &students[i].g2, &students[i].g3, &students[i].g4) == 5)
        i++;
    fclose(scores);
    int j = 0, first, second, third, fourth;
    while(j < i)
    {
        first = students[j].g1;
        second = students[j].g2;
        third = students[j].g3;
        fourth = students[j].g4;
        if((is_passed(first) && is_passed(second) && is_passed(third)) || (is_passed(first) && is_passed(second) && is_passed(fourth)) || (is_passed(first) && is_passed(fourth) && is_passed(third)) || (is_passed(fourth) && is_passed(second) && is_passed(third)))
            fprintf(pass, "%s %d %d %d %d\n", students[j].name, first, second, third, fourth);
        else
            fprintf(fail, "%s %d %d %d %d\n", students[j].name, first, second, third, fourth);
        j++;
    }
    fclose(pass);
    fclose(fail);
    return 0;
}