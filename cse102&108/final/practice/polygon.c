#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct point{
    double x_coord;
    double y_coord; 
};

struct polygon{
    struct point *data;
    int capacity;
    int size;
};

void append_to_polygon(struct polygon *poly, struct point p);
struct polygon *create_a_polygon(double *x_c, double *y_c, int num_of_c)
{
    // Poligon yapısını oluşturuyoruz ve verilen koordinatları ekliyoruz
    struct polygon *poly = (struct polygon *)malloc(sizeof(struct polygon));
    poly->capacity = 10;
    poly->size = 0;
    poly->data = (struct point *)malloc(poly->capacity * sizeof(struct point));
    struct point p;
    for(int i = 0; i < num_of_c ;i++)
    {
        p.x_coord = x_c[i];
        p.y_coord = y_c[i];
        append_to_polygon(poly, p);
    }
    return poly;
}

void polygon_copy(struct polygon *d, struct polygon *s)
{
    free(d->data);
    d->size = s->size;
    d->capacity =s->capacity;
    d->data = malloc(d->capacity * sizeof(struct point));
    for(int i = 0; i < d->size; i++)
        d->data[i] = s->data[i];
}
void append_to_polygon(struct polygon *poly, struct point p)
{
    // Poligonun kapasitesi dolmuşsa, kapasiteyi iki katına çıkararak yeni bir dizi oluşturuyoruz ve eski verileri yeni diziye kopyalıyoruz
    if(poly->capacity == poly->size)
    {
        struct point *newA = (struct point *)malloc(2 * poly->capacity * sizeof(struct point));
        for(int i = 0; i < poly->size; i++)
            newA[i] = poly->data[i];
        newA[poly->size] = p;
        poly->capacity = 2 * poly->capacity;
        free(poly->data);
        poly->data = newA;
    }
    else
        poly->data[poly->size] = p;
    poly->size++;
}
int main()
{
    struct point p;
    struct point r;
    struct polygon poly;    
    poly.capacity = 10; 
    poly.size = 0;  
    poly.data = (struct point *)malloc(poly.capacity * sizeof(struct point));   
    append_to_polygon(&poly, p);
    printf("Poligon boyutu: %d\n", poly.size);
    printf("Noktalar: (%.2f, %.2f)\n", poly.data[0].x_coord, poly.data[0].y_coord);
    append_to_polygon(&poly, r);
    printf("Poligon boyutu: %d\n", poly.size);
    printf("Noktalar: (%.2f, %.2f)\n", poly.data[0].x_coord, poly.data[0].y_coord);
    free(poly.data);
    return 0;   
}