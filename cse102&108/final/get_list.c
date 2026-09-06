#include <stdio.h>
#include <stdlib.h>

#define SENT -1

// Derleyicinin tanıması için eksik olan yapı (struct) tanımı
typedef struct list_node_s {
    int digit;
    struct list_node_s *restp;
} list_node_t;

// Sizin yazdığınız özyinelemeli liste oluşturma fonksiyonu
list_node_t *get_list(void)
{
    int data;
    list_node_t *ansp;
    
    scanf("%d", &data);
    
    if(data == SENT)
        ansp = NULL;
    else
    {
        ansp = (list_node_t *)malloc(sizeof(list_node_t));
        ansp->digit = data;
        ansp->restp = get_list();
    }
    return ansp;
}

// Oluşturulan listeyi ekrana yazdırmak için yardımcı fonksiyon
void print_list(list_node_t *head) 
{
    list_node_t *current = head;
    while (current != NULL) 
    {
        printf("%d -> ", current->digit);
        current = current->restp;
    }
    printf("NULL\n");
}

// Bellek sızıntısını (memory leak) önlemek için listeyi temizleyen fonksiyon
void free_list(list_node_t *head) 
{
    if (head != NULL) 
    {
        free_list(head->restp); // Önce geri kalanı temizle
        free(head);             // Sonra mevcut düğümü (node) temizle
    }
}

int main()
{
    list_node_t *liste_basi;

    printf("Listeye eklenecek sayilari girin (Bitirmek icin -1 yazip Enter'a basin):\n");
    
    // Fonksiyonu çağırıp dönen başlangıç adresini kaydediyoruz
    liste_basi = get_list();

    printf("\nOlusturulan Bagli Liste:\n");
    // Listeyi ekrana yazdırıyoruz
    print_list(liste_basi);

    // İşimiz bittiğinde belleği sisteme iade ediyoruz
    free_list(liste_basi);

    return 0;
}