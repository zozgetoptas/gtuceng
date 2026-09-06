#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define MAX_LEN 100
#define NOT_FOUND -1

char *delete(char *source, int index, int n);
char *do_edit(char *source, char command);
char get_command(void);
char *insert(char *source, const char *to_insert, int index);
int pos(const char *source, const char *to_find);

void fgets_clean(char *str, int size)
{
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';
}

int main()
{
    char source[MAX_LEN], command;
    printf("enter the source string:\n");
    fgets_clean(source, MAX_LEN);
    for(command = get_command(); command != 'Q'; command = get_command())
    {
        do_edit(source, command);
        printf("new source: %s\n\n", source);
    }
    printf("string after editing: %s\n", source);
    return 0;
}

char get_command()
{
    char command, ignore;
    printf("enter D(delete), I(insert), F(find), or Q(quit)> ");
    scanf(" %c", &command);
    do
        ignore = getchar();
    while(ignore != '\n');
    return toupper(command);
}

char *do_edit(char *source, char command)
{
    char str[MAX_LEN];
    int index;
    switch(command){
    case 'D':
        printf("string to delete> ");
        fgets_clean(str, MAX_LEN);
        index = pos(source, str);
        if(index == NOT_FOUND)
            printf("'%s' not found\n", str);
        else
            delete(source, index, strlen(str));
        break;
    case 'I':
        printf("string to insert> ");
        fgets_clean(str, MAX_LEN);
        printf("position of insertion> ");
        scanf("%d", &index);
        insert(source, str, index);
        break;
    case 'F':
        printf("string to find> ");
        fgets_clean(str, MAX_LEN);
        index = pos(source, str);
        if(index == NOT_FOUND)
            printf("'%s' not found\n", str);
        else
            printf("'%s' found at position %d\n", str, index);
        break;
    default:
        printf("invalid edit command '%c'\n", command);
    }
    return source;
}

int pos(const char *source, const char *to_find)
{
    int i = 0, find_len, found = 0, position;
    char substring[MAX_LEN];

    find_len = strlen(to_find);
    while(!found && i <= strlen(source) - find_len)
    {
        strncpy(substring, &source[i], find_len);
        substring[find_len] = '\0';
        if(strcmp(substring, to_find) == 0)
            found = 1;
        else
            ++i;
    }
    if(found)
        position = i;
    else
        position = NOT_FOUND;
    return position;
}

char *delete(char *source, int index, int n)
{
    char rest_str[MAX_LEN];
    if(strlen(source) <= index + n)
        source[index] = '\0';
    else
    {
        strcpy(rest_str, &source[index + n]);
        strcpy(&source[index], rest_str);
    }
    return source;
}

char *insert(char *source, const char *to_insert, int index)
{
    char rest_str[MAX_LEN];
    if(strlen(source) <= index)
        strcat(source, to_insert);
    else
    {
        strcpy(rest_str, &source[index]);
        strcpy(&source[index], to_insert);
        strcat(source, rest_str);
    }
    return source;
}
