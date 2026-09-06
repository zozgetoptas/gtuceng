#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* int main(void)
{
    int n1;
    int n2;
    printf("sayi gir: \n");
    scanf("%d", &n1);
    printf("diger sayiyi gir: \n");
    scanf("%d", &n2);
    printf("toplam: %d\n", n1 + n2);
    if(n1 >= n2)
        printf("fark: %d\n", n1 - n2);
    else
        printf("fark:%d\n", n2 - n1);
    return 0;
} */
/* int main(void)
{
    unsigned char c;
    printf("karakter gir: \n");
    scanf(" %c", &c);
    if(isalpha(c))
        printf("bu bir harf\n");
    else if(isdigit(c))
        printf("bu bir rakam\n");
    else
        printf("ozel karakter\n");
    return 0;
} */
/* int main()
{
    double a = pow(3,5);
    printf("%.2f\n", a);
    printf("%f\n", sqrt(4));
    printf("%f\n", fabs(-7));
    printf("%f\n", sin(90));
    printf("%f\n", cos(90));
    printf("%f\n", tan(45));

    return 0;
} */
/* int main()
{
    for(int i = 1; i <= 10; i++)
    {
        double d = pow(i, 3);
        printf("%d sayisinin küpü: %.2f\n", i, d);
    }
    return (0);
} */
/* int main()
{
    int toplam = 0;
    int sayi;
    while(1)
    {
        printf("bir sayi gir:\n");
        scanf("%d", &sayi);
        if(sayi == 0)
            break;
        toplam += sayi;
    }
    printf("toplam: %d\n", toplam);
    return 0;
} */
/* int main()
{
    srand(time(NULL));
    int i = 0;
    while(i < 5)
    {
        int d = (rand() % 100) + 1;
        printf("%d: %d\n", i + 1, d);
        i++;
    }
    return 0;
} */
/* int main()
{
    char str1[15] = "zeynep";
    char str2[10] = "ozge";
    char str3[10] = "toptas";

    printf("%ld\n", strlen(str2));
    char str4[10];
    strcpy(str4, str1);
    printf("%s\n", str4);
    printf("%s\n", strcat(str1, str2));
    printf("%d\n", strcmp(str2, "ozget"));
    printf("%s\n", strstr(str1, "yn"));
    return 0;
} */
/* int main()
{
    int a = atoi("116");
    float b = atof("45");
    printf("%d  %.2f\n", a, b);
} */
/* int main()
{
    char buffer[100];
    sprintf(buffer, "ad: ozge soyad: toptas numara: %ld\n", 240104004006);
    char ad[20];
    char soyad[20];
    long numara;
    sscanf(buffer, "ad: %s soyad: %s numara: %ld", ad, soyad,& numara);
    printf("%s", buffer);
    printf("ad: %s\n", ad);  
    printf("soyad: %s\n", soyad); 
    printf("numara: %ld\n", numara);
} */
/* int main()
{
    int arr[10];
    int i = 0;
    while(i < 10)
    {
        int n;
        printf("enter a number:\n");
        scanf("%d", &n);
        arr[i] = n;
        i++;
    }
    i = 1;
    int greatest = arr[0];
    while(i < 10)
    {
        if(arr[i] > greatest)
            greatest = arr[i];
        i++;
    }
    printf("greatest argument in the array is: %d\n", greatest);
    return 0;
} */
/* void add_one(int *arr, int length)
{
    int i = 0;
    while(i < length)
    {
        arr[i] += 1;
        i++;
    }
}
int main()
{
    int arr[5] = {1, 3, 7, 14, 9};
    add_one(arr, 5);
    int i = 0;
    while(i < 5)
    {
        printf("%d  ",arr[i]);
        i++;
    }
} */
/* int *greater_addr(int *f, int *s)
{
    int *result;
    if(*f >= *s)
        result = f;
    else
        result = s;
}
int main()
{
    int a = 34;
    int b = 5;
    int *res = greater_addr(&a, &b);
    printf("%d\n", *res);

    printf("%p", res);
} */
/* float area_of_circle(int r)
{
    float pi = 3.14;
    return(pi * r * r); 
}
int main()
{
    printf("%.3f", area_of_circle(4));
} */
/* void compare_strings(char *str1, char *str2)
{
    if(strcmp(str1, str2))
        printf("different");
    else
        printf("same");
}
int main()
{
    compare_strings("zeynepozge", "ozge");
    printf("\n");
    compare_strings("ozge", "ozge");
} */
/* void multiply_by_two(int *n)
{
   *n *= 2;
}
int main()
{
    int a = 56;
    int b = -3;
    printf("a: %d | b: %d\n", a, b);
    multiply_by_two(&a);
    multiply_by_two(&b);
    printf("a: %d | b: %d\n", a, b);
} */