#include <stdio.h>

// 1234 -> 4 3 2 1 şeklinde rakamları ters çıkarır
int reverse(int n)
{
    if(n == 0) 
        return 0;
    printf("%d ", n % 10);       // son rakamı yaz
    return reverse(n / 10);      // kalanı işle
}

// her satır için azalan aralıkla yaz
void print_lines(int n)
{
    if(n == 0) 
        return;
    reverse(n);                  // o anki sayının tersini yaz
    printf("\n");
    print_lines(n / 10); // bir rakam düşür (1234 -> 123 -> 12 -> 1)
}

int main()
{
    print_lines(1234);
}