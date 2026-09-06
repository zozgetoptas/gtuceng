#include <stdio.h>
#include <string.h>

#define NOT_FOUND -1
#define STRSIZ 40

char *nums_to_string_date(char *date_string, int month, int day, int year, const char *month_names[]);
int search(const char *arr[], const char *target, int n);
void string_date_to_nums(const char *date_string, int *monthp, int *dayp, int *yearp, const char *month_names[]);

int main()
{
    const char *month_names[12] = {"jan", "feb", "march", "apr", "may", "june", "july", "aug", "sept", "oct", "nov", "dec"};
    int m, y, mon, year, day;
    char date_string[STRSIZ];
    for(y = 1993; y < 2010; y += 10)
    {
        for(m = 1; m <= 12; ++m)
        {
            printf("%s", nums_to_string_date(date_string, m, 15, y, month_names));
            string_date_to_nums(date_string, &mon, &day, &year, month_names);
            printf(" = %d/%d/%d\n", mon, day, year);
        }
    }
    return 0;
}

char *nums_to_string_date(char *date_string, int month, int day, int year, const char *month_names[])
{
    sprintf(date_string, "%d %s %d", day, month_names[month - 1], year);
    return date_string;
}
int search(const char *arr[], const char *target, int n)
{
    int i, found = 0, where;
    i = 0;
    while(!found && i < n)
    {
        if(strcmp(arr[i], target) == 0)
            found = 1;
        else
            ++i;
    }
    if(found)
        where = i;
    else
        where = NOT_FOUND;
    return where;
}

void string_date_to_nums(const char *date_string, int *monthp, int *dayp, int *yearp, const char *month_names[])
{
    char mth_nam[STRSIZ];
    int month_index;
    sscanf(date_string, "%d%s%d", dayp, mth_nam, yearp);
    month_index = search(month_names, mth_nam, 12);
    *monthp = month_index + 1;
}