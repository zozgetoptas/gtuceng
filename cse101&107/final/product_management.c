#include <stdio.h>

typedef struct t_product
{
    char name[20];
    long fee;
    long stock;
} product;

int main()
{
    product p[20];
    FILE *file = fopen("products.txt", "r");
    int count = 0;
    if(!file)
        return 1;
    while(fscanf(file, "%s %ld %ld", p[count].name, &p[count].fee, &p[count].stock) == 3)
        count++;
    fclose(file);
    long expensive = p[0].fee;
    int i = 1;
    int expensive_index = 0;
    while(i < count)
    {
        if(p[i].fee > expensive)
        {
            expensive = p[i].fee;
            expensive_index = i;
        }
        i++;
    }
    long sum = 0;
    printf("the most expensive product is: %s, and the price is: %ld\n\n", p[expensive_index].name, p[expensive_index].fee);
    for(int i = 0; i < count; i++)
        sum += p[i].fee * p[i].stock;

    for(int i = 0; i < count - 1; i++)
    {
        for(int j = i + 1; j < count; j++)
        {
            if(p[j].stock < p[i].stock)
            {
                product temp = p[j];
                p[j] = p[i];
                p[i] = temp;
            }
        }
    }
    printf("the top 3 product with the least stock: %s %s %s\n\n", p[0].name, p[1].name, p[2].name);
    printf("the total worth is: %ld\n", sum);
    return 0;
}