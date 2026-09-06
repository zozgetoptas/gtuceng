int is_symetric(int matrix[3][3])
{
    int i = 0, j;
    while(i < 3)
    {
        j = 0;
        while(j < 3)
        {
            if(matrix[i][j] == matrix[j][i])
                j++;
            else
                break;
        }
        if(j != 3)
            break;
        i++;
    }
    if(i == 3 && j == 3)
        return 1;
    return 0;
}

#include <stdio.h>
int main()
{
    int matrix[3][3];
    matrix[0][0] = 1, matrix[0][1] = 5, matrix[0][2] = 4, matrix[1][0] = 5, matrix[1][1] = 2, matrix[1][2] = 3, matrix[2][0] = 4, matrix[2][1] = 3, matrix[2][2] = 6;
    if(is_symetric(matrix))
        printf("yes");
    else
        printf("no");
    return 0; 
}