#include <stdio.h>
#include <string.h>

#define MAX 5
#define SENTINEL "SON"
/*
int main()
{
    char names[MAX][20];
    double gpas[MAX];
    char *namePtrs[MAX];
    int n = 0;

    printf("Ogrenci adlari ve GPA giriniz.\n");
    printf("\"%s\" yazarak bitirin.\n\n", SENTINEL);

    while (n < MAX)
    {
        printf("Ad: ");
        scanf("%19s", names[n]);

        if (strcmp(names[n], SENTINEL) == 0)
            break;

        printf("GPA: ");
        scanf("%lf", &gpas[n]);

        namePtrs[n] = names[n];
        n++;
    }

    
    for (int i = 0; i < n - 1; i++)
    {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (gpas[j] > gpas[maxIdx])
                maxIdx = j;
        }

        char *tmpPtr = namePtrs[i];
        namePtrs[i]  = namePtrs[maxIdx];
        namePtrs[maxIdx] = tmpPtr;

        double tmpGpa = gpas[i];
        gpas[i]       = gpas[maxIdx];
        gpas[maxIdx]  = tmpGpa;
    }

    printf("\nSiralanmis liste:\n");
    printf("%-12s %s\n", "Ad", "GPA");
    printf("%-12s %s\n", "----", "---");

    for (int i = 0; i < n; i++)
        printf("%-12s %.2f\n", namePtrs[i], gpas[i]);

    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
typedef struct book {
    char isbn[20];
    char title[100];
    char author[50];
    struct book *next;
} book_t;

book_t *read_file(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Dosya acilamadi");
        return NULL;
    }

    book_t *head = NULL, *tail = NULL;

    while (1)
    {
        book_t *new_book = (book_t *)malloc(sizeof(book_t));

        if (fscanf(file, "%19s %99s %49s",
                   new_book->isbn,
                   new_book->title,
                   new_book->author) != 3)
        {
            free(new_book);
            break;
        }

        new_book->next = NULL;

        if (!head)
            head = tail = new_book;
        else
        {
            tail->next = new_book;
            tail = new_book;
        }
    }

    fclose(file);
    return head;
}

void write_according_to_writer(book_t *head, const char *author)
{
    book_t *cur = head;
    while (cur != NULL)
    {
        if (strcmp(cur->author, author) == 0)
            printf("ISBN: %s  Baslik: %s\n", cur->isbn, cur->title);
        cur = cur->next;
    }
}

void free_heap(book_t *head)
{
    while (head != NULL)
    {
        book_t *tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main()
{
    book_t *list = read_file("books.txt");

    if (!list)
    {
        printf("Liste bos veya dosya okunamadi.\n");
        return 1;
    }

    printf("Marquez'e ait kitaplar:\n");
    write_according_to_writer(list, "Marquez");

    free_heap(list);
    return 0;
}*/

typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
}node_t;

node_t *create_node(int data)
{
    node_t *new = (node_t *)malloc(sizeof(node_t));
    new->data = data;
    new->right = NULL;
    new->left = NULL;
    return new;
}
node_t *bst_add(node_t *root, int data)
{
    if(!root)
        return create_node(data);
    if(data < root->data)
        root->left = bst_add(root->left, data);
    else if(data > root->data)
        root->right = bst_add(root->right, data);
    return root;
    
}

int bst_search(node_t *root, int target, int *count)
{
    (*count)++;
    if(root == NULL)
        return 0;
    if(target == root->data)
        return 1;
    if(target < root->data)
        return bst_search(root->left, target, count);
    else
        return bst_search(root->right, target, count);
    
}
void inorder_write(node_t *root)
{
    if(!root)
        return;
    inorder_write(root->left);
    printf("%d  ", root->data);
    inorder_write(root->right);

}

void free_tree(node_t *root)
{
    if(!root)
        return;
    free_tree(root->left);
    free_tree(root->right);

}

int main()
{
    int numbers[] = {50, 30, 70, 20, 40, 60, 80};
    int n = 7;
    node_t *root = NULL;
    for(int i = 0; i < n; i++)
        root = bst_add(root, numbers[i]);
    printf("inorder: ");
    inorder_write(root);
    printf("\n");
    int count = 0;
    int found = bst_search(root, 40, &count);
    printf("40 %s, %d call\n", found ? "found" : "not found", count);
    free_tree(root);
    return 0;
}