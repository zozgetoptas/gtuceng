/*
write the necessary structures/unions and functions for the following
scenario: you have a directory tree. each node is either a directory or
a file. files and directories have names. directories hold other files
and directroies as sub-trees. files do not hold any information other than a
name. (you can add more fields if you need) fill in the following functions
and define other necessary functions so that the main funciton works as
expected.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct inode{
    char name[30];
    int type;
    struct inode *next;
    struct inode *children;
};

// Function prototypes
struct inode *create_a_directory(char *name);
struct inode *create_a_file(char *name);
void add_to_directory(struct inode *parent, struct inode *child);
void list_directory(struct inode *dir, int level);
void delete_tree(struct inode *node);

/*
this function dynamically allocates an inode struct and sets its type to
be a directory.
*/
struct inode *create_a_directory(char *name)
{
    struct inode *nd = malloc(sizeof(struct inode));
    nd->type = 0;
    nd->next = NULL;
    nd->children = NULL;
    strcpy(nd->name, name);
    return nd;
}

// Create a file (type = 1)
struct inode *create_a_file(char *name)
{
    struct inode *nd = malloc(sizeof(struct inode));
    nd->type = 1;
    nd->next = NULL;
    nd->children = NULL;
    strcpy(nd->name, name);
    return nd;
}

// Add a file or directory to a parent directory
void add_to_directory(struct inode *parent, struct inode *child)
{
    if(parent->type == 1)  // Can't add to a file
    {
        printf("Error: Can't add to a file!\n");
        return;
    }
    if(parent->children == NULL)
        parent->children = child;
    else
    {
        struct inode *curr = parent->children;
        while(curr->next != NULL)
            curr = curr->next;
        curr->next = child;
    }
}

// List all files and directories in a directory
void list_directory(struct inode *dir, int level)
{
    if(dir->type == 1)  // It's a file
    {
        for(int i = 0; i < level; i++)
            printf("  ");
        printf("FILE: %s\n", dir->name);
        return;
    }
    for(int i = 0; i < level; i++)
        printf("  ");
    printf("DIR: %s/\n", dir->name);
    struct inode *curr = dir->children;
    while(curr != NULL)
    {
        list_directory(curr, level + 1);
        curr = curr->next;
    }
}

// Delete a directory tree
void delete_tree(struct inode *node)
{
    if(node == NULL)
        return;
    struct inode *curr = node->children;
    while(curr != NULL)
    {
        struct inode *temp = curr;
        curr = curr->next;
        delete_tree(temp);
    }
    
    free(node);
}

int main()
{
    // Create root directory
    struct inode *root = create_a_directory("root");
    
    // Create some directories and files
    struct inode *home = create_a_directory("home");
    struct inode *usr = create_a_directory("usr");
    struct inode *file1 = create_a_file("readme.txt");
    struct inode *file2 = create_a_file("data.txt");
    
    // Add to root
    add_to_directory(root, home);
    add_to_directory(root, usr);
    add_to_directory(root, file1);
    
    // Add to home
    struct inode *documents = create_a_directory("documents");
    struct inode *file3 = create_a_file("note.txt");
    add_to_directory(home, documents);
    add_to_directory(home, file3);
    
    // Add to documents
    add_to_directory(documents, file2);
    
    // List the directory tree
    printf("Directory Tree:\n");
    list_directory(root, 0);
    
    // Clean up
    delete_tree(root);
    
    return 0;
}