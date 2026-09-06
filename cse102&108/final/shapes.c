/*
.define a struct Rectangle which holds the width and height informaiton 
of a rectangle.
.define a struct Circle which holds the radius information of a circle.
.define a struct Shape which represents a shape. a shape can be either
a rectangle or a circle. (hint: you need to use a union in order to represent both
shapes with a single struct.) (this shape struct also represents a node of
a linked list. so, dont forget the pointer component.)
.write a func get_shape() which asks the user to enter a shape type and
information. this function scans shape information, dynamically allocates a
shape, stores the information and returns the address of the shape. if the
user enters 'R', it creates a Shape struct which holds a rectangle
information. if the usser enters 'C', Shape struct holds the circle
information. if the user enters a different char, this func returns NULL.
after user enters 'R' or 'C' , ask the user to enter shape information.
for a rectangle, the user enters two doubles (width and height). for a circle,
the user enters a double (radius).
.write a main program according to the following description:
-ask user to enter shape information in a loop (call get_shape func), store
the dynamically created Shape struct in a linked list. exit the loop if
get_shape func returns NULL.
-print areas of each shape in the linked list. for this, you need to define a
func called area(). this func takes a shape struct and returns the area
of the shape.
-delete dynamically created Shape structs in the linked list. for this, you
need to traverse the linked list and delete nodes.
you can define additional functions and/or macros.
*/
struct Rectangle{
    double width;
    double height;
};
struct Circle{
    double radius;
};
union shape{
    struct Rectangle rect;
    struct Circle circ;
};
struct Shape{
    int type;  // 0 for Rectangle, 1 for Circle
    union shape s;
    struct Shape *next;
};

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
struct Shape *get_shape(void);
double area(struct Shape *shape);

struct Shape *get_shape()
{
    struct Shape *new_shape = (struct Shape *)malloc(sizeof(struct Shape));
    char type;
    
    printf("Enter shape type (R for Rectangle, C for Circle): ");
    scanf(" %c", &type);
    
    if(type == 'R' || type == 'r')
    {
        new_shape->type = 0;
        printf("Enter width and height: ");
        scanf("%lf %lf", &new_shape->s.rect.width, &new_shape->s.rect.height);
        new_shape->next = NULL;
        return new_shape;
    }
    else if(type == 'C' || type == 'c')
    {
        new_shape->type = 1;
        printf("Enter radius: ");
        scanf("%lf", &new_shape->s.circ.radius);
        new_shape->next = NULL;
        return new_shape;
    }
    else
    {
        free(new_shape);
        return NULL;
    }
}

double area(struct Shape *shape)
{
    if(shape->type == 0)
        return shape->s.rect.width * shape->s.rect.height;
    else if(shape->type == 1)
        return 3.14159 * shape->s.circ.radius * shape->s.circ.radius;
    return 0;
}

int main()
{
    struct Shape *head = NULL;
    struct Shape *current;

    while(1)
    {
        struct Shape *new_shape = get_shape();
        if(new_shape == NULL)
            break;
        if(head == NULL)
            head = new_shape;
        else
        {
            current = head;
            while(current->next != NULL)
                current = current->next;
            current->next = new_shape;
        }
    }
    printf("\n--- Shape Areas ---\n");
    current = head;
    int i = 1;
    while(current != NULL)
    {
        char *type_str;
        if(current->type == 0)
            type_str = "Rectangle";
        else
            type_str = "Circle";
        
        printf("Shape %d (%s): Area = %.2f\n", i, type_str, area(current));
        current = current->next;
        i++;
    }
    current = head;
    while(current != NULL)
    {
        struct Shape *temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}
