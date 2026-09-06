#include <stdio.h>

typedef struct t_car{
    char brand[20];
    char model[20];
    long fee;
    int  year;
}car;
int main()
{
    car car1 = {"hyundai", "a10", 350000, 2019};
    car car2 = {"opel", "aa", 100, 2001};
    car car3 = {"porche", "yeey", 54675210, 2025};
    car cheapest = car1;
    if(car2.fee < cheapest.fee)
        cheapest = car2;
    if(car3.fee < cheapest.fee)
        cheapest = car3;
    printf("%s %s %ld %d\n", cheapest.brand, cheapest.model, cheapest.fee, cheapest.year);
    return 0;
}