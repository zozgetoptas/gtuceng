# Lab7 - Taylor Serisi ile Trigonometrik Fonksiyonlar

## Proje Açıklaması
Bu program, **sin(x) ve cos(x) trigonometrik fonksiyonlarını Taylor serisini kullanarak hesaplayan** bir C uygulamasıdır. Kulllanıcı derece cinsinden açı girişi yapar ve program radyana çevirerek sin ve cos değerlerini 12 ondalak basamak hassasiyetiyle hesaplar.

---

## Kodun Mimarisi

### Yardımcı Fonksiyonlar

#### 1. Faktöriyel Hesaplama
```c
double iterative_factorial(double nb)   // İteratif versiyon (döngü ile)
double recursive_factorial(double nb)   // Rekürsif versiyon (kendini çağırarak)
```
- **Amaç:** n! = 1 × 2 × 3 × ... × n hesaplar
- **Hata Kontrolü:** Negatif sayılar için 0 döndürür
- **Kullanım:** Taylor serisinde payda hesaplaması için gerekli

#### 2. Üs Hesaplama (Power)
```c
double iterative_power(double nb, int power)    // İteratif versiyon
double recursive_power(double nb, int power)    // Rekürsif versiyon
```
- **Amaç:** nb^power (nb üssü power) hesaplar
- **Örnek:** 2^3 = 8, 3^2 = 9
- **Hata Kontrolü:** 
  - Negatif üsler için 0
  - 0. üs için 1 (herhangi bir sayının 0. kuvveti 1'dir)
- **Kullanım:** Taylor serisinde pay hesaplaması için gerekli

---

### Ana Trigonometrik Fonksiyonlar

#### 3. sinx(double a) - Sine Hesaplama

**Taylor Serisi Formülü:**
$$\sin(x) = x - \frac{x^3}{3!} + \frac{x^5}{5!} - \frac{x^7}{7!} + \frac{x^9}{9!} - ...$$

**Algoritma:**
```c
while(i <= 25)
{
    if(i % 2 == 0)          // çift iterasyonlarda
        result -= ...        // terim çıkarılır (-)
    else if(i % 2 != 0)     // tek iterasyonlarda
        result += ...        // terim eklenir (+)
    i++;
}
```

**Özellikler:**
- 25 iterasyon kullanılarak yüksek hassasiyet sağlanır
- Her iterasyonda: `a^(2i-1) / (2i-1)!` terimi eklenir/çıkarılır
- Alternatif işaret (+/-) sağlamak için modulo operatörü kullanılır

---

#### 4. cosx(double a) - Cosine Hesaplama

**Taylor Serisi Formülü:**
$$\cos(x) = 1 - \frac{x^2}{2!} + \frac{x^4}{4!} - \frac{x^6}{6!} + \frac{x^8}{8!} - ...$$

**Algoritma:**
```c
while(i <= 50)
{
    if(i % 2 != 0)          // tek iterasyonlarda
        result += ...        // terim eklenir (+)
    else if(i % 2 == 0)     // çift iterasyonlarda
        result -= ...        // terim çıkarılır (-)
    i++;
}
```

**Özellikler:**
- 50 iterasyon kullanılarak çok yüksek hassasiyet sağlanır
- Her iterasyonda: `a^(2i-2) / (2i-2)!` terimi eklenir/çıkarılır
- sin'den daha fazla iterasyon kullanır çünkü yakınsama yavaştır

---

### Ana Program (main)

```c
int main()
{
    double a;
    scanf("%lf", &a);           // Kullanıcıdan derece cinsinden açı al
    a *= M_PI/180;              // Radyana dönüştür
    printf("sin: %.12lf \n", sinx(a));      // sin(a) değerini yazdır
    printf("cos: %.12lf", cosx(a));         // cos(a) değerini yazdır
    return 0;
}
```

**İşlem Adımları:**
1. Kullanıcıdan derece cinsinden açı girişi
2. Radyana çevirme: radyan = derece × π/180
3. sin ve cos fonksiyonlarını çağırma
4. Sonuçları 12 ondalak basamak hassasiyetiyle ekrana yazdırma

---

## Kullanım Örnekleri

### Örnek 1: 90 Derece
```
Girdi: 90
sin: 1.000000000000
cos: 0.000000000000
```
- 90° = π/2 radyan
- sin(π/2) = 1
- cos(π/2) = 0

### Örnek 2: 45 Derece
```
Girdi: 45
sin: 0.707106781187
cos: 0.707106781187
```
- 45° = π/4 radyan
- sin(π/4) ≈ 0.707
- cos(π/4) ≈ 0.707

### Örnek 3: 0 Derece
```
Girdi: 0
sin: 0.000000000000
cos: 1.000000000000
```
- 0° = 0 radyan
- sin(0) = 0
- cos(0) = 1

---

## Teknik Detaylar

### Taylor Serisi Nedir?
Taylor serisi, bir fonksiyonu polinom serisi olarak yaklaşıklaştıran matematiksel bir yöntemdir. Trigonometrik fonksiyonlar gibi karmaşık fonksiyonları toplama ve bölme işlemleriyle hesaplamayı mümkün kılar.

### Neden Rekürsif Power ve Factorial Kullanılıyor?
- Rekürsif yapı daha temiz ve anlaşılması kolay kod sağlar
- Her çağrıda değer azalarak sonunda taban duruma ulaşır
- Laboratuvar çalışması olması nedeniyle öğretim amacıdır

### Hassasiyet
- 12 ondalak basamak (%.12lf) kullanılarak yüksek doğruluk sağlanır
- sin için 25 iterasyon, cos için 50 iterasyon yapılır
- Bu sayılar çoğu pratik uygulama için yeterli doğruluk verir

### Hata Kontrolü
- Negatif faktöriyel ve üs işlemleri kontrol edilir
- Geçersiz girişlerde 0 döndürülür

---

## Derlemek ve Çalıştırmak

```bash
gcc -o lab7_try lab7_try.c -lm
./lab7_try
```

**Not:** `-lm` bayrağı math.h kütüphanesi için gereklidir (M_PI sabitini içerir).

---

## Matematiksel Temel

### Sinüs Taylor Serisi Türetimi
$$\sin(x) = \sum_{n=0}^{\infty} \frac{(-1)^n}{(2n+1)!} x^{2n+1}$$

### Kosinüs Taylor Serisi Türetimi
$$\cos(x) = \sum_{n=0}^{\infty} \frac{(-1)^n}{(2n)!} x^{2n}$$

Burada:
- n iterasyon sayısı
- x radyan cinsinden açı
- (-1)^n alternatif işaret (+ ve - dönüşümlü) sağlar

---

## Geliştirilecek Noktalar
- Giriş doğrulama yapılabilir (örn: -360 ile 360 arası kontrol)
- tanx, cotx gibi diğer trigonometrik fonksiyonlar eklenebilir
- İteratif versiyonlar daha verimli olabilir
- Hata toleransı belirlenebilir (belli hassasiyata ulaşınca durma)
