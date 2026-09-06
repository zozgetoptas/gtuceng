/*
 * CSE108 - Lab #11
 * Linked Lists and File I/O
 *
 * Complete the missing parts marked with TODO.
 * Do not change the main function or the provided helper functions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEPS 10
#define MAX_NAME_LEN 20

/* ---- Struct Definitions (Given) ---- */

/* Represents a software package */
typedef struct package {
    char name[MAX_NAME_LEN];          /* package name */
    struct package* dependencies[MAX_DEPS]; /* pointers to dependency packages */
    int dep_count;                    /* number of dependencies */
} package_t;

/* Linked-list node for storing packages */
typedef struct node {
    package_t* data;   /* points to a dynamically created package_t */
    struct node* next;
} node_t;

/* Represents a developer */
typedef struct developer {
    char name[30];                       /* developer name */
    package_t* installed[MAX_DEPS];      /* packages already installed */
    package_t* to_install[MAX_DEPS];     /* packages the developer wants to install */
    int inst_count;                      /* number of installed packages */
    int want_count;                      /* number of packages to install */
} developer_t;


/* ---- Provided Helper Functions ---- */

/*
 * Reads the next line from the file into buffer.
 * Returns 1 on success, 0 at end of file.
 */
int getnextline(FILE* fp, char* buffer)
{
    if (fgets(buffer, 1000, fp) == NULL)
        return 0;

    /* Remove trailing newline */
    int len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n')
        buffer[len - 1] = '\0';

    return 1;
}

/*
 * Splits a line into space-separated parts.
 * parts[0], parts[1], ... will hold the individual words.
 * number_of_parts will hold the total count of words.
 */
void splitline(char* line, char parts[][MAX_NAME_LEN], int* number_of_parts)
{
    *number_of_parts = 0;
    char* token = strtok(line, " \t");
    while (token != NULL && *number_of_parts < MAX_DEPS + 1)
    {
        strcpy(parts[*number_of_parts], token);
        (*number_of_parts)++;
        token = strtok(NULL, " \t");
    }
}


/* ---- Function Prototypes ---- */

node_t* read_packages(char* filename);
void check_installations(developer_t* developers, int num_developers, node_t* package_list);


/* ---- Main Function (Do Not Change) ---- */

int main(void)
{
    /* Read packages from file */
    node_t* package_list = read_packages("packages.txt");

    /* Print the loaded packages */
    printf("Loaded packages:\n");
    node_t* current = package_list;
    while (current != NULL)
    {
        printf("  %s", current->data->name);
        if (current->data->dep_count > 0)
        {
            printf(" (depends on:");
            for (int i = 0; i < current->data->dep_count; i++)
                printf(" %s", current->data->dependencies[i]->name);
            printf(")");
        }
        printf("\n");
        current = current->next;
    }

    /* Create sample developers */
    developer_t developers[2];

    /* Developer 0: Alice - has gcc and make installed, wants cmake */
    strcpy(developers[0].name, "Alice");
    developers[0].inst_count = 2;
    developers[0].want_count = 1;

    /* Developer 1: Bob - has only gcc installed, wants cmake and valgrind */
    strcpy(developers[1].name, "Bob");
    developers[1].inst_count = 1;
    developers[1].want_count = 2;

    /* Link developer packages to the loaded package list */
    current = package_list;
    while (current != NULL)
    {
        /* Alice has gcc and make */
        if (strcmp(current->data->name, "gcc") == 0)
        {
            developers[0].installed[0] = current->data;
            developers[1].installed[0] = current->data;
        }
        if (strcmp(current->data->name, "make") == 0)
            developers[0].installed[1] = current->data;
        /* Alice wants cmake */
        if (strcmp(current->data->name, "cmake") == 0)
            developers[0].to_install[0] = current->data;
        /* Bob wants cmake and valgrind */
        if (strcmp(current->data->name, "cmake") == 0)
            developers[1].to_install[0] = current->data;
        if (strcmp(current->data->name, "valgrind") == 0)
            developers[1].to_install[1] = current->data;
        current = current->next;
    }

    /* Check installations */
    printf("\nDevelopers who cannot install all desired packages:\n");
    check_installations(developers, 2, package_list);

    /* Free allocated memory */
    current = package_list;
    while (current != NULL)
    {
        node_t* temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }

    return 0;
}



/* ---- TODO: Implement These Functions ---- */

/*
 * Helper function to find a package by name
 * in the linked list.
 */
package_t* find_package(node_t* head, char* name)
{
    node_t* current = head;
    while (current != NULL)
    {
        if (strcmp(current->data->name, name) == 0)
            return current->data;
        current = current->next;
    }
    return NULL;
}

/*
 * TODO: Implement read_packages
 *
 * This function reads the file given by filename.
 * Each line defines a package. The first word is the package name.
 * The remaining words are the names of its dependencies.
 *
 * Example file content (packages.txt):
 *   gcc
 *   make gcc
 *   cmake make
 *   valgrind gcc make
 *
 * The function must:
 *   1. Open the file.
 *   2. Read each line using getnextline.
 *   3. Split each line using splitline.
 *   4. Dynamically allocate a package_t for each package.
 *   5. Store the package name and find its dependencies
 *      in the already-built linked list.
 *   6. Append each package as a new node_t to the linked list.
 *   7. Return the head pointer of the linked list.
 *
 * Hint: Dependencies are always defined before the packages
 *       that depend on them.
 */
node_t* read_packages(char* filename)
{
    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
        return NULL;

    node_t* head = NULL;
    node_t* tail = NULL;

    char buffer[1000];
    char parts[MAX_DEPS + 1][MAX_NAME_LEN];
    int number_of_parts;

    while (getnextline(fp, buffer))
    {
        if (strlen(buffer) == 0)
            continue;
        splitline(buffer, parts, &number_of_parts);
        package_t* new_package = (package_t*)malloc(sizeof(package_t));
        strcpy(new_package->name, parts[0]);
        new_package->dep_count = number_of_parts - 1;
        for (int i = 1; i < number_of_parts; i++)
            new_package->dependencies[i - 1] = find_package(head, parts[i]);
        node_t* new_node = (node_t*)malloc(sizeof(node_t));
        new_node->data = new_package;
        new_node->next = NULL;

        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }
    fclose(fp);
    return head;
}

/*
 * TODO: Implement check_installations
 *
 * For each developer, check every package in their to_install list.
 * For each package to install, verify that ALL of its dependencies
 * are present in the developer's installed list.
 *
 * If any package cannot be installed (a dependency is missing),
 * print the developer's name.
 *
 * Example output:
 *   Bob
 *
 * (Because Bob wants cmake which needs make, but Bob only has gcc.)
 */
void check_installations(developer_t* developers, int num_developers, node_t* package_list)
{
    for (int i = 0; i < num_developers; i++)
    {
        int can_install_all = 1;
        
        for (int j = 0; j < developers[i].want_count; j++) 
        {
            package_t* pkg_to_install = developers[i].to_install[j];
            
            for (int k = 0; k < pkg_to_install->dep_count; k++)
            {
                package_t* required_dep = pkg_to_install->dependencies[k];
                int has_dependency = 0;
                
                for (int d = 0; d < developers[i].inst_count; d++)
                {
                    if (developers[i].installed[d] == required_dep)
                    {
                        has_dependency = 1;
                        break;
                    }
                }
                
                if (!has_dependency)
                {
                    can_install_all = 0;
                    break;
                }
            }
            if (!can_install_all)
                break;
        }
        
        if (!can_install_all)
            printf("%s\n", developers[i].name);
    }
}
