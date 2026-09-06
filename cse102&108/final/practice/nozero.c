#include <stdio.h>
#include <string.h>

void f(int* a, char* b, int* count)
{
    int stl = strlen(b);
    int current_int = 0;
    *count = 0;

    for(int i = 0; i < stl; i++)
    {
        if(b[i] != '0')
        {
            // '0' değil, rakamı sayıya ekle
            current_int = current_int * 10 + (b[i] - '0');
        }
        else
        {
            // '0' gördük, biriken sayıyı kaydet
            if(current_int != 0)
            {
                a[*count] = current_int;
                (*count)++;
                current_int = 0;
            }
        }
    }

    // String bittikten sonra kalan sayıyı kaydet
    if(current_int != 0)
    {
        a[*count] = current_int;
        (*count)++;
    }
}

int main()
{
    int a[100];
    int count;
    char b[] = "0110340044809";

    f(a, b, &count);

    printf("Sonuc: {");
    for(int i = 0; i < count; i++)
    {
        if(i != count - 1)
            printf("%d,", a[i]);
        else
            printf("%d", a[i]);
    }
    printf("}\n");

    return 0;
}