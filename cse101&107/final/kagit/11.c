typedef struct{
    int id;
    char name[10];
    float fee;
}product;

#include <stdio.h>

int main()
{
    FILE *file_in = fopen("products.txt", "r");
    if(!file_in)
        return 1;
    FILE *file_out = fopen("expensive.bin", "ab");
    if(!file_out)
    {
        fclose(file_in);
        return 1;
    }
    int counter = 0;
    product products[4];
    while(fscanf(file_in, "%d %s %f", &products[counter].id, products[counter].name, &products[counter].fee) == 3)
        counter++;
    int i = 0;
    while(i < counter)
    {
        if(products[i].fee > 100.00)
            fprintf(file_out, "%d %s %f\n", products[i].id, products[i].name, products[i].fee);
            i++;
    }
    return 0;
}
