#include <stdio.h>
/*

int main()
{
    char str[15];
    printf("+%d\n", scanf("%s%c", str, str +15));
    printf("%s\n", str);
    printf("%c\n", *(str + 15));

}*/
/*
int main()
{
    int a = 2;
    int **pptr;
    **pptr = &(&a);
    **pptr = 3;
    printf("%d", **pptr);
}

int main()
{
    int a = 2;
    int *ptr = &a;
    int **pptr = &ptr;
    
    **pptr = 3;
    printf("%d", **pptr);
}*/
#include <string.h>
#include <stdlib.h>
/*
int main()
{
    char *c = (char *)calloc(100, sizeof(char));
    strcpy(c, "jay");
    char *t =  c;
    char *b = c;
    while(*t != '\0')
    {
        printf("%s ", b);
        strcpy(c++, "z");
        printf("%s ", c-1);
        t = t+2;
    }
    
}*//*

union u{
    int a;
    union u *next;
};
struct s
{
    char t;
    union u g;
};
void fun(struct s *a)
{
    if(a->t == 'i')
        printf("%d", a->g.a);
    else
        a->g.next->a = 2;
    
}
int main()
{
    struct s s1, s2;
    s1.t = 'i';
    s1.g.a = 3;
    s2.t = 'p';
    s2.g.next = &s1.g;
    fun(&s1);
    printf("%d", s1.g.a);
    fun(&s2);
    printf("%d", s1.g.a);

}*/
/*
void f(int **z, int *a)
{
    *z = a;
    printf("%d ", **z);
    *a = 4;
}
int main()
{
    int *z;
    int a = 2;
    z = &a;
    f(&z, z);
    printf("%d ", *z);
    f(&z, &a);
    printf("%d ", *z);
}*/

void rec1(int *a, int *b)
{
    if(a[0] < b[0])
    {
        printf("%d ", *a);
        *a = *(a + 1) - 1;
        rec1(b, b + 1);
    }
}
int main()
{
    int a[5] = {1, 2, 3, 4, 0};
    rec1(a, a + 1);
    printf("%d", a[0]);
    

}
