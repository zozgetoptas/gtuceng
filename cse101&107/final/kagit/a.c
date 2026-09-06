#include <stdio.h>
#include <stddef.h>

typedef struct t_a{
    char c;
    char ch;
    int i;     // 4 byte
}aa;

typedef struct t_b{
    char c;
    int i;
    char ch;
         // 1 byte + 3 byte padding
}bb;

int main()
{
    aa a;
    bb b;
    a.i = 4;
    a.ch = 45;
    b.ch = 7;
    b.i = 5;
    a.c = 'a';
    b.c = 'b';

    printf("sizeof(aa) = %ld\n", sizeof(aa));
    printf("sizeof(bb) = %ld\n", sizeof(bb));

}