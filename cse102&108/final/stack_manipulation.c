#include <stdio.h>
#include <stdlib.h>

// Yığına eklenecek veri tipini belirliyoruz (Karakter eklediğiniz için char yaptık)
typedef char stack_element_t;

// Yığının her bir düğümünü (node) temsil eden yapı
typedef struct stack_node_s {
    stack_element_t element;       // Veriyi tutan kısım
    struct stack_node_s *restp;    // Bir sonraki düğümü gösteren işaretçi
} stack_node_t;

// Yığının en üstünü (top) takip eden ana yapı
typedef struct {
    stack_node_t *topp;
} stack_t;

// Fonksiyon prototipleri
void push(stack_t *sp, stack_element_t c);
stack_element_t pop(stack_t *sp);

int main()
{
    // Yığını başlatıyoruz (en üstü NULL)
    stack_t s = {NULL};
    
    // Elemanları yığına ekliyoruz
    push(&s, '2');
    push(&s, '+');
    push(&s, 'C');
    push(&s, '/');
    
    printf("\nemptying stack: \n");
    
    // Yığın boşalana kadar elemanları çıkarıp yazdırıyoruz
    while(s.topp != NULL)
        printf("%c\n", pop(&s));
        
    return 0;
}

void push(stack_t *sp, stack_element_t c)
{
    stack_node_t *newp;
    
    // Yeni düğüm için bellekten yer ayır
    newp = (stack_node_t *)malloc(sizeof(stack_node_t));
    
    // HATA DÜZELTİLDİ: Gelen veriyi (c) yeni düğüme atamayı unutmuyoruz
    newp->element = c; 
    
    // Yeni düğümü mevcut yığının en üstüne bağlıyoruz
    newp->restp = sp->topp;
    
    // Yığının yeni en üst noktasını (top) bu yeni düğüm yapıyoruz
    sp->topp = newp;
}

stack_element_t pop(stack_t *sp)
{
    stack_node_t *to_freep;
    stack_element_t ans;
    
    // Silinecek olan en üstteki düğümü işaretle
    to_freep = sp->topp;
    
    // Döndürülecek veriyi al
    ans = to_freep->element;
    
    // Yığının en üst noktasını bir altındaki düğüme kaydır
    sp->topp = to_freep->restp;
    
    // Eski en üst düğümü bellekten sil
    free(to_freep);
    
    // Veriyi geri döndür
    return ans;
}