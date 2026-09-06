#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PAIRS 10
#define MAX_NAME  21

int parse_line(char *line, int values[MAX_PAIRS], char labels[MAX_PAIRS][MAX_NAME], int *count, double *number)
{
    *count = 0;
    char buffer[101];
    strcpy(buffer, line);
    char *token  = strtok(buffer, " \t");
    if (token == NULL) return 0;
    char *second = strtok(NULL, " \t");

    if (second == NULL)
    {
        sscanf(token, "%lf", number);
        return 1;
    }

    while (token != NULL && second != NULL)
    {
        sscanf(token, "%d", &values[*count]);
        strncpy(labels[*count], second, MAX_NAME - 1);
        labels[*count][MAX_NAME - 1] = '\0';
        (*count)++;
        token  = strtok(NULL, " \t");
        second = strtok(NULL, " \t");
    }
    return 2;
}

double ask_question(char name[], char parent[])
{
    int flag = 0;
    int values[MAX_PAIRS];
    char labels[MAX_PAIRS][MAX_NAME];
    int count = 0;
    double total = 0.0;
    char buffer[101];
    double value = 0.0;

    if (strlen(parent) == 0)
        printf("Define %s?\n> ", name);
    else
        printf("Define %s in %s?\n> ", name, parent);

    fgets(buffer, 101, stdin);
    int len = strlen(buffer);
    if (len > 0 && buffer[len-1] == '\n')
        buffer[len-1] = '\0';

    flag = parse_line(buffer, values, labels, &count, &value);

    if (flag == 1)
        total = value;
    else
    {
        for (int i = 0; i < count; i++)
            total += values[i] * ask_question(labels[i], name);
    }

    return total;
}

int main()
{
    char object_name[MAX_NAME];

    printf("Define the object\n> ");
    scanf("%20s", object_name);
    getchar(); // scanf'in bıraktığı newline'ı temizle

    double final_total = ask_question(object_name, "");

    printf("\nTotal cost of %s is: %.2f\n", object_name, final_total);

    return 0;
}