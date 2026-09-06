#include <stdio.h>
#include <string.h>

void mergeStr(char result[], char str1[], char str2[]);

int main() {
    char str1[21], str2[21];
    char result[42];

    printf("Enter first string: ");
    scanf("%20s", str1);
    printf("Enter second string: ");
    scanf("%20s", str2);

    mergeStr(result, str1, str2);

    printf("Merged string: %s\n", result);
    return 0;
}

void mergeStr(char result[], char str1[], char str2[]) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int overlap = 0;

    // Find the largest i where last i chars of str1 == first i chars of str2
    int maxCheck;
    if (len1 < len2)
        maxCheck = len1;
    else
        maxCheck = len2;
    for (int i = 1; i <= maxCheck; i++) {
        if (strncmp(str1 + len1 - i, str2, i) == 0) {
            overlap = i;
        }
    }
    // Copy str1 into result
    strcpy(result, str1);
    // Append the non-overlapping part of str2
    strcat(result, str2 + overlap);
}