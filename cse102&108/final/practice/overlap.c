#include <stdio.h>
#include <string.h> // Included to use the strlen function

void mergeWords(const char *word1, const char *word2, char *result) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int overlap = 0;
    int index = 0;

    // The maximum possible overlap is the length of the shorter word
    int minLen = (len1 < len2) ? len1 : len2;

    // Search for the overlap starting from the longest possible match and going backwards
    for (int t = minLen; t > 0; t--) {
        int matched = 1; // 1: Matched, 0: Not matched

        // Compare the last 't' characters of word1 with the first 't' characters of word2
        for (int i = 0; i < t; i++) {
            if (word1[len1 - t + i] != word2[i]) {
                matched = 0; // If even one character differs, the match is broken
                break;
            }
        }

        // If all characters matched perfectly, record the overlap length and stop searching
        if (matched == 1) {
            overlap = t;
            break;
        }
    }

    // Step 1: Copy the entire first word into the 'result' array
    for (int i = 0; i < len1; i++) {
        result[index++] = word1[i];
    }

    // Step 2: Append only the NON-OVERLAPPING part of the second word to the 'result' array
    for (int i = overlap; i < len2; i++) {
        result[index++] = word2[i];
    }

    // Step 3: Add the Null character to indicate the end of the string in C
    result[index] = '\0';
}

int main() {
    // We allocate the memory here in main instead of using a 'static' array inside the function
    char resultArray[256]; 
    
    // Pass the words and the array that will hold the result to the function
    mergeWords("zeynepabc", "abcozge", resultArray);
    
    // Print the final result
    printf("Merged text: %s\n", resultArray);
    
    return 0;
}