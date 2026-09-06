struct student{
    char name[30];
    int id;
    float gpa;
};
#include <stdio.h>
int main()
{
    float sum = 0.0;
    FILE *in = fopen("students.txt", "r");
    if(!in)
        return 1;

    int i = 0;
    struct student students[50];
    while(fscanf(in, "%s %d %f", students[i].name, &students[i].id, &students[i].gpa) == 3)
        i++;
    i = 0;
    while(i < 50)
    {
        sum += students[i].gpa;
        i++;
    }
    int j = 0, k;
    while(j < 50)
    {
        k = j + 1;
        while(k < 50)
        {
            if(students[j].gpa > students[k].gpa)
            {
                struct student temp = students[j];
                students[j] = students[k];
                students[k] = temp;
            }
            k++;
        }
        j++;
    }
    j--;
    while(j > 44)
    {
        printf("%s %d %.2f\n", students[j].name, students[j].id, students[j].gpa);
        j--;
    }
    printf("%f\n", sum / 50);
    return 0;
}