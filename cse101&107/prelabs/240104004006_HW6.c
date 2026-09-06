#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int count_words_on_line_and_total_sentences(char *line, int *sentence_count)
{
    int word_counter = 0;
    int i = 0;
    int in_word = 0;

    while (isspace((unsigned char)line[i]))
        i++;

    while (line[i])
    {
        if (!isspace((unsigned char)line[i]))
        {
            if (!in_word)
                word_counter++;
            in_word = 1;

            if ((line[i] == '.' || line[i] == '!' || line[i] == '?') 
                && (isspace((unsigned char)line[i + 1]) || line[i + 1] == '\n' || line[i + 1] == '\0'))
                (*sentence_count)++;
        }
        else
            in_word = 0;
        i++;
    }
    return (word_counter);
}

int main()
{
    FILE *file;
    char buffer[4096];

    int line_counter = 0;
    int total_words = 0;
    int sentence_count = 0;

    file = fopen("data.txt", "r");

    if (file == NULL)
    {
        perror("file opening failed\n");
        return (1);
    }

    while (fgets(buffer, sizeof(buffer), file))
    {
        line_counter++;

        int words_in_line = count_words_on_line_and_total_sentences(buffer, &sentence_count);
        
        if (words_in_line > 0)
        {
            if(words_in_line == 1)
                printf("Line %d: %d word\n", line_counter, words_in_line);
            else
                printf("Line %d: %d words\n", line_counter, words_in_line);
            total_words += words_in_line;
        }
    }
    fclose(file);

    printf("Total sentences: %d\n", sentence_count);
    printf("Total words: %d\n", total_words);

    return (0);
}