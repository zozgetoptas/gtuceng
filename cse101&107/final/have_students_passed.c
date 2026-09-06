#include <stdio.h>

typedef struct t_student{
    char name[20];
    int g1;
    int g2;
    int g3;
    int g4;
} student;

int main()
{
    FILE *scores;
    FILE *a;
    FILE *b;

    scores = fopen("scores.txt", "r");
    if(!scores)
        return 1;
    a = fopen("passed.txt", "w");
    if(!a)
    {
        fclose(scores);
        return 1;
    }
    b = fopen("not_passed.txt", "w");
    if(!b)
    {
        fclose(scores);
        fclose(a);
        return 1;
    }
    student cur_student;
    while(fscanf(scores, "%s %d %d %d %d", cur_student.name, &cur_student.g1, &cur_student.g2, &cur_student.g3, &cur_student.g4) == 5)
    {
        if((cur_student.g1 >= 53 && cur_student.g2 >= 53 && cur_student.g3 >= 53) || (cur_student.g1 >= 53 && cur_student.g2 >= 53 && cur_student.g4 >= 53) || (cur_student.g1 >= 53 && cur_student.g4 >= 53 && cur_student.g3 >= 53) || (cur_student.g2 >= 53 && cur_student.g3 >= 53 && cur_student.g4 >= 53))
            fprintf(a, "%s %d %d %d %d\n", cur_student.name, cur_student.g1, cur_student.g2, cur_student.g3, cur_student.g4);
        else
            fprintf(b, "%s %d %d %d %d\n", cur_student.name, cur_student.g1, cur_student.g2, cur_student.g3, cur_student.g4);
    }
    fclose(scores);
    fclose(a);
    fclose(b);
    return 0;
}