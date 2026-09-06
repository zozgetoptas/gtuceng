#include <stdio.h>

// Karakter sayma fonksiyonu
int count(char ch, const char *str)
{
    int ans;
    if(str[0] == '\0')
        ans = 0;
    else
    {
        if(ch == str[0])
            ans = 1 + count(ch, &str[1]);
        else
            ans = count(ch, &str[1]);
    }
    return ans;
}

#include <stdio.h>
#include <ctype.h>

#define STRSIZ 100

char *find_caps(char *caps, const char *str)
{
    char restcaps[STRSIZ];
    
    if(str[0] == '\0')
        caps[0] = '\0';
    else
    {
        if(isupper(str[0]))
            sprintf(caps, "%c%s", str[0], find_caps(restcaps, &str[1]));
        else
            find_caps(caps, &str[1]);
    }
    
    return caps;
}

int main()
{
    const char *metin = "C Programlama Dili Gercekten EGLENCELI";
    char buyuk_harfler[STRSIZ];
    
    find_caps(buyuk_harfler, metin);
    
    printf("Orijinal Metin : %s\n", metin);
    printf("Buyuk Harfler  : %s\n", buyuk_harfler);
    
    return 0;
}
/*
int main()
{
    // Test edilecek kelime veya cümle
    const char *metin = "programlama harika bir sey";
    
    // Sayılmak istenen karakter
    char aranacak_harf = 'a';
    
    // Fonksiyonu çağırıp sonucu bir değişkene atıyoruz
    int sonuc = count(aranacak_harf, metin);
    
    // Sonucu ekrana yazdırıyoruz
    printf("'%s' metni icinde '%c' harfi %d defa geciyor.\n", metin, aranacak_harf, sonuc);
    
    return 0;
}*/