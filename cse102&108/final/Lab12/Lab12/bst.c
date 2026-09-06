#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

Node* bst_insert(Node* root, int data) {
    if (root == NULL)
        return create_node(data);
    if (data < root->data)
        root->left = bst_insert(root->left, data);
    else if (data > root->data)
        root->right = bst_insert(root->right, data);
    return root;
}

int bst_search(Node* root, int data, int *recurse_call_count) {
    (*recurse_call_count)++;
    if (root == NULL)
        return 0;
    if (root->data == data)
        return 1;
    if (data < root->data)
        return bst_search(root->left, data, recurse_call_count);
    return bst_search(root->right, data, recurse_call_count);
}

Node* build_bst_helper(FILE* file, Node* root, int* count) {
    int value;
    if (fscanf(file, "%d", &value) != 1)
        return root;
    root = bst_insert(root, value);
    (*count)++;
    return build_bst_helper(file, root, count);
}

Node* build_bst(const char* filename, int* count) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    Node* root = build_bst_helper(file, NULL, count);
    fclose(file);
    return root;
}

void analyze_bst_search_performance(Node* root, const char* filename, int count) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    int value;
    double total_recursive_calls = 0;

    while (fscanf(file, "%d", &value) == 1) {
        int recursive_call_count = 0;
        bst_search(root, value, &recursive_call_count);
        total_recursive_calls += recursive_call_count;
    }

    fclose(file);

    printf("===== BINARY SEARCH TREE SEARCH STATISTICS =====\n");
    printf("For %d numbers, each search required an average of %.2f recursive call.\n",
           count, total_recursive_calls / count);
}

void free_bst(Node* root) {
    if (root == NULL)
        return;
    free_bst(root->left);
    free_bst(root->right);
    free(root);
}

int main(void) {
    int count = 0;

    Node* root = build_bst("numbers.txt", &count);

    printf("The number of nodes inside binary search tree: %d\n", count);

    analyze_bst_search_performance(root, "numbers.txt", count);

    free_bst(root);

    return 0;
}