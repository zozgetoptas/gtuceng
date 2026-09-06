#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_PATH 512
#define BUFFER_SIZE 4096
#define MAX_FOLDERS 10

void create_directories()
{
    mkdir("processed", 0777);

    mkdir("incoming1", 0777);
    mkdir("incoming2", 0777);
    mkdir("incoming3", 0777);
}

char *extract_text_from_html(const char *html_content)
{
    int html_len = strlen(html_content);
    char *plain_text = (char *)malloc(html_len + 1);
    
    if (plain_text == NULL)
    {
        fprintf(stderr, "memory allocation failed\n");
        return NULL;
    }
    
    int plain_index = 0;
    int in_tag = 0;
    
    for (int i = 0; i < html_len; i++)
    {
        if (html_content[i] == '<')
            in_tag = 1;
        else if (html_content[i] == '>')
            in_tag = 0;
        else if (!in_tag)
            plain_text[plain_index++] = html_content[i];
    }
    plain_text[plain_index] = '\0';
    return plain_text;
}

char *generate_output_filename(const char *input_filename)
{
    char *output_filename = (char *)malloc(MAX_PATH);
    if (output_filename == NULL)
        return NULL;
    char base_name[100];
    strcpy(base_name, input_filename);
    char *dot = strrchr(base_name, '.');
    if (dot != NULL)
        *dot = '\0';
    
    snprintf(output_filename, MAX_PATH, "processed/%s_processed.txt", base_name);

    int counter = 2;
    while (access(output_filename, F_OK) == 0)
    {
        snprintf(output_filename, MAX_PATH, "processed/%s_processed_%d.txt", base_name, counter);
        counter++;
    }
    return output_filename;
}

int process_file(const char *input_filename, const char *folder_name)
{
    char input_path[MAX_PATH];
    sprintf(input_path, "%s/%s", folder_name, input_filename);
    
    FILE *input_file = fopen(input_path, "r");
    if (input_file == NULL)
    {
        fprintf(stderr, "file opening failure! (%s)\n", input_path);
        return 0;
    }
    
    char *file_content = (char *)malloc(BUFFER_SIZE);
    if (file_content == NULL)
    {
        fprintf(stderr, "allocation failure\n");
        fclose(input_file);
        return 0;
    }
    
    int total_read = 0;
    int bytes_read;
    while ((bytes_read = fread(file_content + total_read, 1, BUFFER_SIZE - total_read - 1, input_file)) > 0)
    {
        total_read += bytes_read;
        
        if (total_read >= BUFFER_SIZE - 1)
        {
            char *temp = (char *)realloc(file_content, BUFFER_SIZE * 2);
            if (temp == NULL)
            {
                fprintf(stderr, "allocation failure\n");
                fclose(input_file);
                free(file_content);
                return 0;
            }
            file_content = temp;
        }
    }
    file_content[total_read] = '\0';
    fclose(input_file);
    
    char *plain_text = extract_text_from_html(file_content);
    free(file_content);
    if (plain_text == NULL)
        return 0;
    
    char *output_filename = generate_output_filename(input_filename);
    if (output_filename == NULL)
    {
        free(plain_text);
        return 0;
    }
    
    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL)
    {
        fprintf(stderr, "file opening failure! (%s)\n", output_filename);
        free(plain_text);
        free(output_filename);
        return 0;
    }
    
    if (fputs(plain_text, output_file) == EOF)
    {
        fprintf(stderr, "writing error (%s)\n", output_filename);
        fclose(output_file);
        free(plain_text);
        free(output_filename);
        return 0;
    }
    fclose(output_file);
    printf("[%s] successfully processed: %s -> %s\n", folder_name, input_filename, output_filename);

    if (remove(input_path) != 0)
        fprintf(stderr, "warning!! could not delete original file. (%s)\n", input_path);    
    
    free(plain_text);
    free(output_filename);
    return 1;
}

void scan_directory(const char *folder_name)
{
    DIR *dir = opendir(folder_name);
    if (dir == NULL)
    {
        fprintf(stderr, "error!! could not open %s/ directory\n", folder_name);
        return;
    }
    
    struct dirent *entry;
    int files_found = 0;
    
    printf("\n--- scanning %s/ directory ---\n", folder_name);
    
    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_REG)
        {
            char *ext = strrchr(entry->d_name, '.');
            if (ext != NULL && strcmp(ext, ".txt") == 0)
            {
                files_found = 1;
                printf("Found file in %s: %s\n", folder_name, entry->d_name);
                process_file(entry->d_name, folder_name);
            }
        }
    }
    closedir(dir);
    
    if (files_found == 0)
        printf("no .txt files found in %s/ directory right now\n", folder_name);
}

int main()
{
    printf("starting multi-folder poller\n");
    
    create_directories();
    
    // Taranacak klasörleri tanımla
    const char *folders[] = {"incoming1", "incoming2", "incoming3"};
    int folder_count = 3;
    
    while (1)
    {
        printf("\n========== NEW SCAN CYCLE ==========\n");
        
        // Her klasörü tarayıp işle
        for (int i = 0; i < folder_count; i++)
        {
            scan_directory(folders[i]);
        }
        
        printf("\nwaiting 10 seconds before next scan...\n");
        for(int i = 0; i < 10; i++)
        {
            printf("%d ", i + 1);
            fflush(stdout);
            sleep(1);
        }
        printf("\n");
    }
    
    return 0;
}
