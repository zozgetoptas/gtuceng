/*
write a func that splits a string according to the delimeter character
and saves each substring in a cell of one dynamic arr. the function
should take the string and the delimeter char as inputs. you should
not use any library functions from string.h or any other libraries
other than strlen. example: if the str is "a,b,c,d" adn delimeter
is "," are given, the function will have 4 tokens in its return
argument as four separate strings "a", "b", "c", and "d". (hint:
you have to count the number of tokens and create dynamic arr of strs.)
*/

// use the following func header. inp is the input, dlm is the delimeter

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
  
int split (const char *inp, char dlm, char ***tokens)
{
    int token_count = 1;
    int i = 0;
    while(inp[i])
    {
        if(inp[i] == dlm)
            token_count++;
        i++;
    }
    
    *tokens = (char **)malloc(sizeof(char *) * token_count);
    
    int token_idx = 0;
    int start = 0;
    
    for(i = 0; i <= strlen(inp); i++)
    {
        if(inp[i] == dlm || inp[i] == '\0')
        {
            int len = i - start;
            
            if(len > 0)
            {
                (*tokens)[token_idx] = (char *)malloc(sizeof(char) * (len + 1));
                int j = 0;
                while(j < len)
                {
                    (*tokens)[token_idx][j] = inp[start + j];
                    j++;
                }
                (*tokens)[token_idx][len] = '\0';
                
                token_idx++;
            }
            
            start = i + 1;
        }
    }
    
    return token_count;
}


int main()
{
    char ***tokens = (char ***)malloc(sizeof(char **));
    const char *str = "a,b,c,d";
    char delimiter = ',';
    
    int count = split(str, delimiter, tokens);
    
    printf("Split result for \"%s\" with delimiter '%c':\n", str, delimiter);
    printf("Number of tokens: %d\n\n", count);
    
    for(int i = 0; i < count; i++)
    {
        printf("Token %d: %s\n", i + 1, (*tokens)[i]);
    }
    
    // Bellek temizle
    for(int i = 0; i < count; i++)
    {
        free((*tokens)[i]);
    }
    free(*tokens);
    free(tokens);
    
    return 0;
}