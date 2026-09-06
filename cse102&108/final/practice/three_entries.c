#include <stdio.h>

int main()
{
    int num;
    char chr;
    double val;
    int on = 1;

    while(1)
    {
        printf("please enter an integer, character and a real number: \n");
        scanf("%d %c %lf", &num, &chr, &val);
        
        if(num == -111 || chr == 'Z' || (val >= -0.02 && val <= 0.02))
            break;
        
    }
}