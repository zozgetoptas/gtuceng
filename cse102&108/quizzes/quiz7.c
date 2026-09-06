#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct point{
    double x_coord;
    double y_coord; 
};

struct polygon{
    struct point *data,
    int capacity;
    int size;
};
void append_to_polygon(struct polygon *poly, struct point p)
{
    if(poly-<capacity == poly->size)
    {
        struct point *newA = (struct point *)malloc(2 * poly->capacity * sizeof(struct point));
        for(int i = 0; i < poly->size; i++)
            newA[i] = poly->data[i];
    }
}
int main()
{
    struct point p;
    struct polygon pol;
    pol.capacity = 10;
    pol.size = 0;
    pol.data = (struct point *)malloc(poly->capacity * sizeof(struct point));

    append_t0_polygon(&pol, p);
}