#include <stdio.h>

typedef struct t_cars{
    char label[20];
    char model[20];
    long long fee;
    int year;
}cars;

int main()
{
    cars car1 = {"abc", "23f", 567890, 2020};
    cars car2 = {"aaaaa", "244444", 511167890, 2021};
    cars car3 = {"q", "SD", 50, 2022};

    cars cheapest = car1;
    
    if(car2.fee < cheapest.fee)
        cheapest = car2;
    if(car3.fee < cheapest.fee)
        cheapest = car3;

    printf("the cheapest one:\n");
    printf("label: %s\n", cheapest.label);
    printf("model: %s\n", cheapest.model);
    printf("fee: %lld\n", cheapest.fee);
    printf("year: %d\n", cheapest.year);
    
    return 0;
}