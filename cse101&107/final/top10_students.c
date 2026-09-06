// bunu bi de function yazarak yap ve best worst studentı da yaz

#include <stdio.h>

typedef struct t_student{
    int grade[20];
    char names[20][20];
} student;

int main()
{
    student s = {{5, 15, 25, 35, 45, 55, 65, 75, 85, 95, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100}, {"ali", "ayşe", "mehmet", "ahmet", "can", "cem", "poyraz", "ege", "yusuf", "ozge", "semri", "feraye", "eylul", "aysu", "enes", "cagri","begum", "beren", "utku", "meryem"}};

    int indices[20];
    int i, j, min_idx;
    
    for(i = 0; i < 20; i++)
        indices[i] = i;
    
    for(i = 0; i < 10; i++)
    {
        min_idx = i;
        for(j = i + 1; j < 20; j++)
        {
            if(s.grade[indices[j]] < s.grade[indices[min_idx]])
                min_idx = j;
        }
        int temp = indices[i];
        indices[i] = indices[min_idx];
        indices[min_idx] = temp;
    }
    
    printf("the lowest grades and who got them:\n");
    for(i = 0; i < 10; i++)
        printf("%d. %s - grade: %d\n", i+1, s.names[indices[i]], s.grade[indices[i]]);
    int sum = 0;
    for(int i = 0; i < 10; i++)
        sum += s.grade[indices[i]];
    sum = 0;
    printf("the avarage of the ten lowest grades: %.2f\n", sum/10.0);
    for(int i = 0; i < 20; i++)
        sum += s.grade[indices[i]];
    printf("the avarage of all of the grades: %.2f\n", sum/20.0);
    
    return 0;
}