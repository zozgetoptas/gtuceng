#include <stdio.h>

int is_symetric(int **matrix, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(matrix[i][j] != matrix[j][i])
                return 0; 
        }
    }
    return 1;
}

int main()
{
    int n = 3;
    int matrix[3][3] =
    {
        {1, 2, 3},
        {2, 5, 4},
        {3, 4, 9}
    };
    
    int *ptr_matrix[3];
    for(int i = 0; i < 3; i++)
        ptr_matrix[i] = matrix[i];
    
    int sonuc = is_symetric((int **)ptr_matrix, n);
    
    if(sonuc == 1)
        printf("symetric\n");
    else
        printf("not symetric\n");
    
    return 0;
}