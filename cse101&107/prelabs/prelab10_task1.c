#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[20];
    int grade;
} student;

int swap_count = 0;

// for the most successfull
void bubble_sort(student arr[], int n)
{
    swap_count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].grade < arr[j + 1].grade)
            {
                student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap_count++;
            }
        }
    }
}

// for the least successfull
void quick_sort(student arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high].grade;
        int i = low - 1;
        
        for (int j = low; j < high; j++)
        {
            if (arr[j].grade < pivot)
            {
                i++;
                student temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                swap_count++;
            }
        }
        student temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        swap_count++;
        int pi = i + 1;
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

char get_letter_grade(int grade)
{
    if (grade >= 90)
        return 'A';
    else if (grade >= 80)
        return 'B';
    else if (grade >= 70)
        return 'C';
    else if (grade >= 60)
        return 'D';
    else
        return 'F';
}
void show_most_successful(student arr[], int n)
{
    student temp_arr[n];
    for (int i = 0; i < n; i++)
        temp_arr[i] = arr[i];
    bubble_sort(temp_arr, n);
    printf("\nMost Successful Student:\n");
    printf("Score: %d\n", temp_arr[0].grade);
    printf("Letter Grade: %c\n", get_letter_grade(temp_arr[0].grade));
    printf("Swap count: %d\n", swap_count);
    printf("Student: %s\n", temp_arr[0].name);
}

void show_most_unsuccessful(student arr[], int n)
{
    student temp_arr[n];
    for (int i = 0; i < n; i++)
        temp_arr[i] = arr[i];
    swap_count = 0;
    quick_sort(temp_arr, 0, n - 1);
    printf("\nMost Unsuccessful Student:\n");
    printf("Score: %d\n", temp_arr[0].grade);
    printf("Letter Grade: %c\n", get_letter_grade(temp_arr[0].grade));
    printf("Swap count: %d\n", swap_count);
    printf("Student: %s\n", temp_arr[0].name);
}

void show_letter_grade_statistics(student arr[], int n)
{
    int count_a = 0, count_b = 0, count_c = 0, count_d = 0, count_f = 0;

    for (int i = 0; i < n; i++)
    {
        char letter = get_letter_grade(arr[i].grade);
        if (letter == 'A')
            count_a++;
        else if (letter == 'B')
            count_b++;
        else if (letter == 'C')
            count_c++;
        else if (letter == 'D')
            count_d++;
        else
            count_f++;
    }
    printf("\n%d student got letter 'A'\n", count_a);
    printf("%d student got letter 'B'\n", count_b);
    printf("%d student got letter 'C'\n", count_c);
    printf("%d student got letter 'D'\n", count_d);
    printf("%d student got letter 'F\n", count_f);
}

void show_average_grade(student arr[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i].grade;
    double average = sum / n;
    printf("\nThe average score of 30 student is: %.2f\n", average);
}

void show_all_data(student arr[], int n)
{
    show_most_successful(arr, n);
    show_most_unsuccessful(arr, n);
    show_letter_grade_statistics(arr, n);
    show_average_grade(arr, n);
}

int main(void)
{
    FILE *file = fopen("input.txt", "r");
    if (file == NULL)
    {
        printf("Error opening input.txt!\n");
        return 1;
    }
    student students[30];
    int count = 0;

    while (fscanf(file, "%s %d", students[count].name, &students[count].grade) == 2)
        count++;
    fclose(file);

    int choice;
    while (1)
    {
        printf("\n===== Student Score Calculator Menu for %d Student =====\n\n", count);
        printf("1) Most Successful Student\n");
        printf("2) Most Unsuccessful Student\n");
        printf("3) Letter Grade Statistics\n");
        printf("4) Calculate Average\n");
        printf("5) Show all Data\n");
        printf("0) Quit\n");
        printf("Make Selection: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                show_most_successful(students, count);
                break;
            case 2:
                show_most_unsuccessful(students, count);
                break;
            case 3:
                show_letter_grade_statistics(students, count);
                break;
            case 4:
                show_average_grade(students, count);
                break;
            case 5:
                show_all_data(students, count);
                break;
            case 0:
                printf("\n\nQuit selected!\n");
                return 0;
            default:
                printf("Invalid selection!\n");
        }
    }
    return (0);
}
