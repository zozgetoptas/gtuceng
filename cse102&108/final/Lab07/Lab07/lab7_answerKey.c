#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 10
#define SENTINEL "END"

int main() {
    char names[MAX_STUDENTS][MAX_NAME_LENGTH];
    char *namePtrs[MAX_STUDENTS];
    double gpas[MAX_STUDENTS];

    int count = 0;
    int i, j, maxIndex;
    int tempGrade;
    char *tempPtr;

    printf("Enter student names and gpas.\n");
    printf("Type \"%s\" as the student name to stop.\n\n", SENTINEL);

    while (count < MAX_STUDENTS) {
        printf("Enter student name: ");
        scanf("%10s", names[count]);

        if (strcmp(names[count], SENTINEL) == 0) {
            break;
        }

        printf("Enter gpa: ");
        scanf("%lf", &gpas[count]);

        namePtrs[count] = names[count];
        count++;

        printf("\n");
    }

    for (i = 0; i < count - 1; i++) {
        maxIndex = i;

        for (j = i + 1; j < count; j++) {
            if (gpas[j] > gpas[maxIndex]) {
                maxIndex = j;
            }
        }

        if (maxIndex != i) {
            tempGrade = gpas[i];
            gpas[i] = gpas[maxIndex];
            gpas[maxIndex] = tempGrade;

            tempPtr = namePtrs[i];
            namePtrs[i] = namePtrs[maxIndex];
            namePtrs[maxIndex] = tempPtr;
        }
    }

    printf("Sorted student list:\n");
    printf("%-10s %s\n", "Name", "GPA");
    printf("%-10s %s\n", "----", "---");

    for (i = 0; i < count; i++) {
        printf("%-10s %.2lf\n", namePtrs[i], gpas[i]);
    }

    return 0;
}