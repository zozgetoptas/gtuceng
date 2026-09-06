#include <stdio.h>
#include <string.h>

// kacinci olduğunu da yazdir

int is_string_in_array(char *str, char *array[], int array_size)
{
    for(int i = 0; i < array_size; i++)
    {
        if(strcmp(str, array[i]) == 0)
            return 1;
    }
    return 0;
}

int main()
{
    char *names[] = {"ali", "ayşe", "mehmet", "ahmet", "can"};
    int size = 5;
    
    char search[50];
    printf("give me the name u want to search for: \n");
    scanf("%s", search);
    
    if(is_string_in_array(search, names, size))
        printf("FOUND!\n");
    else
        printf("NOT FOUND!\n");
    
    return 0;
}
