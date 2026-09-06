// Sabitler:
// Butonun bağlı olduğu dijital pini tanımla.
const int buttonPin = 2;

// Değişkenler:
int counter = 0;              // Butona basılma sayısını tutan ana sayaç.
int buttonState = 0;          // Butonun anlık kararlı durumunu tutar.
int lastButtonState = 0;      // Bir önceki döngüdeki kararlı durumu tutar (debounce için).
long lastDebounceTime = 0;    // Son durum değişikliğinden bu yana geçen süreyi tutar.
long debounceDelay = 50;      // Debounce için gecikme süresi (milisaniye).

void setup() {
  // Serial haberleşmeyi 9600 baud hızında başlat.
  Serial.begin(9600);

  // Buton pinini dahili pull-up direnci ile giriş (INPUT_PULLUP) olarak ayarla.
  pinMode(buttonPin, INPUT_PULLUP);
  
  // *** BAŞLANGIÇ HATASINI ÖNLEME ***
  // Program başladığında butonun gerçek durumunu okuyarak değişkenleri ayarla.
  // Bu, LOW'dan HIGH'a (varsayılan değerlerden) hayali bir geçiş algılanmasını engeller.
  int initialReading = digitalRead(buttonPin);
  buttonState = initialReading;
  lastButtonState = initialReading;
  
  Serial.println("Arduino Buton Sayici Hazir. Baslayabilirsiniz.");
  // Not: Serial Monitor'ü açıp kapattığınızda bu mesaj tekrar görünebilir. 
  // Bu, Arduino'nun otomatik resetleme özelliğidir, kod hatası değildir.
}

void loop() {
  // Butonun mevcut ham durumunu oku (basilinca LOW, serbestken HIGH).
  int reading = digitalRead(buttonPin);

  // 1. Debounce Kontrolü: Butonun ham durumu değişti mi?
  if (reading != lastButtonState) {
    // Evet, değişti. Debounce zamanlayıcısını sıfırla.
    lastDebounceTime = millis();
  }

  // 2. Debounce Gecikmesi: Gecikme süresi (50ms) doldu mu?
  if ((millis() - lastDebounceTime) > debounceDelay) {
    
    // Gecikme doldu ve yeni okuma, kaydettiğimiz kararlı durumdan farklıysa...
    if (reading != buttonState) {
      // Yeni kararlı durumu kaydet.
      buttonState = reading;

      // 3. Kenar Tetikleme (Basılıp Bırakılma Kontrolü):
      // Sayaç, buton serbest bırakıldığında (HIGH) artsın. 
      // Bu, basılı tutulurken sürekli saymayı engeller (once per press).
      if (buttonState == HIGH) {
        // Sayaç artırımı
        counter++;
        
        // Seri Çıktı
        Serial.print("Butona basildi. Yeni sayac degeri: ");
        Serial.println(counter);
      }
    }
  }

  // Mevcut okumayı bir sonraki döngü için lastButtonState olarak kaydet.
  lastButtonState = reading;
}
