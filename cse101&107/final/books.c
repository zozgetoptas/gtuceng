typedef struct t_book{
    char name[20];
    int page;
    float fee;
}book;

#include <stdio.h>

int main()
{
    FILE *file = fopen("books.txt", "r");
    if(!file)
        return 1;
    book books[10];
    int counter = 0;
    while(fscanf(file, "%s %d %f", books[counter].name, &books[counter].page, &books[counter].fee) == 3)
        counter++;
    fclose(file);
    int i = 0;
    FILE *out = fopen("thick.txt", "wr");
    if(!out)
        return 1;
    while(i < counter)
    {
        if(books[i].page >= 200)
            fprintf(out, "%s\n", books[i].name);
        else
            printf("%s\n", books[i].name);
        i++;
    }
    return 0;
}