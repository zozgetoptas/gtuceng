/*
arabaların markası, modeli, fiyatı gibi özellikleri barındıran bir struct arrayi tanımlayıp 
en düşük fiyata sahip olan arabanın özelliklerini yazdıran C kodu
*/
#include <string.h>
#include <stdio.h>

typedef struct{
    char    *brand;
    int     fee;
    int     model;
}s_cars;

int main()
{
    s_cars *cars;

    strcpy(cars[0].brand,"audi");
    cars[0].fee = 2000;
    cars[0].model = 2;

    strcpy(cars[1].brand,"mercedes");
    cars[1].fee = 10000;
    cars[1].model = 5;

    if(cars[0].fee < cars[1].fee)
    {
        printf("%s\n", cars[0].brand);
        printf("%d\n", cars[0].fee);
        printf("%d\n", cars[0].model);
    }
    else
    {
        printf("%s\n", cars[1].brand);
        printf("%d\n", cars[1].fee);
        printf("%d\n", cars[1].model);
    }

}