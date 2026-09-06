/*
a set, stores unique (not repeating) items. we want to define 2 structs.
- L_Set: this represents a set which stores elements in a linked list.
- A_Set: this represents a set which stores elements in a dynamically
allocated arr.
element type is int.
in addition to these structs we want to create an abstraction by defining
another struct:
- Set
a set can be either an L_Set or an A_Set. define a union compenent
inside Set which stores information for L_Set or A_Set.
.define a struct L_Set which holds the head of the linked list of numbers.
(you also need to define a .node structure for the linked list)
.define a struct A_Set which holds a pointer to the dynamically created arr
of numbers.
.define a struct Set which represents a set. this struct holds the count
of elements in the set, a union component which is either an L_Set or an A_Set
instance. you candefine additional components if you need to.
.write a function add_to_set(Set *s, int element). for this, you need to
figure out the type of the Set *s and add the elemt according to the type. if
it is an L_Set, you need to allocate a new node and append it to the 
existing linked list. if it is an A_Set, you need to check the empty space
in the dynamically created arr. if it is full, you need to create a bigger arr,
copy all the elements and delete the old one. dont forget to check the
existance of the element.
.write a func Set *get_set() which creates a new Set instance dynamically and
asks the user to enter numbers for a set.
-ask the user how to store the elements.
-if the user enters L, the elements will be stored in an L_Set. if the user
enters A, the elements will be stored in an A_Set.
-the user enters numbers in a loop. store each element in the set if the
element is not already in the set. call add_to_set() func here.
-if the user enters 0, the set is complete. return the addr of the dynamically
created instance of Set.
.write a func int get_many_sets(Set **set_array). this func creates many
sets in a loop and stores the addresses of each one in set_array.
-ask the user the number of sets to be created.
-dynamically allocate apointer arr of sets. store the address of this
arr in set_array.
-call get_set() func in a loop.
-return the number of created sets.
.write a func void erase(Set ** all_sets) which deallocates all the memory.
the input argument is the array created in get_many_sets() function.
you can define additional funcs and/or macros.*/
#include <stdio.h>
#include <stdlib.h>

struct node{
    int d;
    struct node *n;
};

struct L_Set{
    struct node *head;
};

struct A_Set{
    int *arr;
    int size;
};

union s{
    struct L_Set LS;
    struct A_Set AS;
};

typedef struct Set{
    int type;
    int count;
    union s handle;
}Set;

void add_to_set(Set *s, int element);
Set *get_set(void);
int get_many_sets(Set **set_array);
void erase(Set *all_sets, int num_sets);

Set *get_set()
{
    Set *s = malloc(sizeof(Set));
    char type;
    int num;
    
    printf("Enter set type (L for Linked List, A for Array): ");
    scanf(" %c", &type);
    
    s->count = 0;
    if(type == 'A')
        s->type = 1;
    else
        s->type = 0;
    
    if(s->type)
    {
        s->handle.AS.arr = malloc(sizeof(int) * 10);
        s->handle.AS.size = 10;
    }
    else
        s->handle.LS.head = NULL;
    printf("Enter numbers (0 to end): ");
    char *filename = malloc(sizeof(char) * 100);
    printf("filename: \n");
    scanf("%s", filename);
    FILE *fp = fopen(filename, "r");
    while(1)
    {
        fscanf(fp, "%d", &num);
        if(num == 0)
            break;
        add_to_set(s, num);
    } 
    return s;
}

int get_many_sets(Set **set_array)
{
    int num_of_sets;
    printf("How many sets to create? ");
    scanf("%d", &num_of_sets);
    *set_array = (Set *)malloc(sizeof(Set) * num_of_sets);
    for(int i = 0; i < num_of_sets; i++)
    {
        Set *temp = get_set();
        (*set_array)[i] = *temp;
        free(temp);
    }
    return num_of_sets;
}
void add_to_set(Set *s, int element)
{
    if(s->type)
    {
        int flag = 1;
        for (int i = 0; i < s->count; i++)
        {
            if(s->handle.AS.arr[i] == element)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            if(s->handle.AS.size <= s->count)
            {
                int *na = malloc(sizeof(int) * 2 * s->handle.AS.size);
                for(int j = 0; j < s->count; j++)
                    na[j] = s->handle.AS.arr[j];
                int *tmp = s->handle.AS.arr;
                s->handle.AS.arr = na;
                s->handle.AS.size = 2 * s->handle.AS.size;
                free(tmp);
            }
            s->handle.AS.arr[s->count] = element;
            s->count++;
        }
    }
    else
    {
        struct node *curr = s->handle.LS.head;
        while(curr)
        {
            if(curr->d == element)
                return;
            curr = curr->n;
        }
        struct node *newNode = malloc(sizeof(struct node));
        newNode->d = element;
        newNode->n = s->handle.LS.head;
        s->handle.LS.head = newNode;
        s->count++;
    }
}

void erase(Set *all_sets, int num_sets)
{
    for(int i = 0; i < num_sets; i++)
    {
        if(all_sets[i].type)
        {
            free(all_sets[i].handle.AS.arr);
        }
        else
        {
            struct node *curr = all_sets[i].handle.LS.head;
            while(curr)
            {
                struct node *tmp = curr;
                curr = curr->n;
                free(tmp);
            }
        }
    }
    free(all_sets);
}

int main()
{
    Set *set_array = NULL;
    int num_sets = get_many_sets(&set_array);
    
    printf("\nSets created successfully!\n");
    for(int i = 0; i < num_sets; i++)
    {
        char *type_str;
        if(set_array[i].type)
            type_str = "Array";
        else
            type_str = "LinkedList";
        
        printf("Set %d: Count = %d, Type = %s\n", i+1, set_array[i].count, type_str);
    }
    
    erase(set_array, num_sets);
    return 0;
}