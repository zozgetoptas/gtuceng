#include <stdio.h>
#include <stdlib.h>
struct n{
    int d;
    struct n *prew;
};
struct n *prt(struct n *t)
{
    if(t != NULL)
    {
        printf("%d ", t->d);
        return(t->prew);
    }
}
int main()
{
    struct n *tail = malloc(5 * sizeof(struct n));
    for(int i = 0; i <= 4; i++) 
    {
        tail[i].d = i;
        if(i < 4)
            tail[i].prew = tail + i + 1;
        else
            tail[i].prew = NULL;     
    }
    printf("%d ", prt(prt(prt(prt(prt(prt(tail)))) - 2) - 1)->d);
}