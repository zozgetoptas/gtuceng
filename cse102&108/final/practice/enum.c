/*
Görev 2: Etkinlik Katılımcı Tablosu (Enum ve 2 Boyutlu Diziler)
Senaryo: Hafta sonu sürecek büyük bir teknoloji etkinliği 
(örneğin bir GeekDay) organize ediyorsun. Etkinlik Cumartesi ve Pazar 
günleri yapılıyor ve her gün 4 farklı oturum var.
İstenen:

Günleri temsil eden (saturday, sunday) bir enum tanımla.

Her günün her oturumundaki katılımcı sayısını tutacak 2x4 boyutunda bir int 
matrisi (2 boyutlu dizi) oluştur ve main içinde başlangıç değerleri ata.

Bu 2 boyutlu diziyi parametre olarak alan ve sadece Cumartesi gününün 
toplam katılımcı sayısını hesaplayıp ekrana yazdıran bir fonksiyon yaz. 
Döngülerinde indeks olarak tanımladığın enum değerlerini kullan.
*/

#include <stdio.h>

enum days{
    saturday, sunday
};
void print_sat(int arr[2][4])
{
    int i = 0;
    int sum = 0;
    while(i<4)
    {
        sum += arr[saturday][i];
        i++;
    }
    printf("%d\n", sum);
}
int main()
{
    enum days event;
    int arr[2][4] = {{100, 80, 40, 90}, {12, 467, 53, 600}};
    print_sat(arr);
    
}