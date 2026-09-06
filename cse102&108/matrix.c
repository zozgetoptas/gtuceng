/*
pointer alan fonksiyon matrix simetrik mi kontrol etsin, simetrikse true 
değilse false returnlesin, main ona göre print yapsın.
*/
#include <stdio.h>
#include <stdbool.h>

// Pointer ve matris boyutunu (n) alan fonksiyon
bool isSymmetric(int *matrix, int n) {
    for (int i = 0; i < n; i++) {
        // Sadece köşegenin sağ üst tarafını kontrol etmek yeterlidir (j = i + 1)
        for (int j = i + 1; j < n; j++) {
            
            // Pointer aritmetiği ile matris[i][j] ve matris[j][i] değerlerine erişim
            int eleman1 = *(matrix + i * n + j); 
            int eleman2 = *(matrix + j * n + i);
            
            // Eğer karşılıklı elemanlar eşit değilse simetrik değildir
            if (eleman1 != eleman2)
                return false;
        }
    }
    // Döngü bittiyse ve eşitsizlik bulunmadıysa matris simetriktir
    return true;
}

int main()
{
    int n = 3;
    //simetrik
    int matris1[3][3] = {
        {1, 2, 3},
        {2, 4, 5},
        {3, 5, 6}
    };
    //simetrik değil
    int matris2[3][3] = {
        {1, 2, 3},
        {8, 5, 6},
        {7, 8, 9}
    };

    if (isSymmetric((int *)matris1, n))
        printf("1. Matris simetriktir.\n");
    else
        printf("1. Matris simetrik degildir.\n");

    if (isSymmetric((int *)matris2, n))
        printf("2. Matris simetriktir.\n");
    else
        printf("2. Matris simetrik degildir.\n");
    return 0;
}