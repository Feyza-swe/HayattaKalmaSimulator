# Hayatta Kalma Simulatörü

## Genel Bakış

Hayatta Kalma Simulatörü, bir metin tabanlı macera oyunudur. Oyunda sağlık, enerji ve kaynakları yönetirken çeşitli zorlukların üstesinden gelmeyi amaçlarsınız. Her kararınız oyunun sonucunu etkileyecektir.

## Oyun Mekanikler

### Temel Kaynaklar

- **Sağlık (Saglik)**: 0-100 arasında değişen değer. Sağlık 0'a ulaştığında oyun biter.
- **Enerji (Enerji)**: 0-100 arasında değişen değer. Enerji 0'a ulaştığında oyun biter.
- **Yemek (Yemek)**: Avlanarak elde edebileceğiniz kaynaktır.
- **Sığınak (Siginak)**: Dinleme sırasında sağlık ve enerji geri kazanmanızı sağlar.

## Oyun Komutları

| Komut | Açıklama |
|-------|----------|
| **A** | Avlanma - Yemek edinmeyi deneyin (enerji: -20) |
| **S** | Sığınak Arama - Güvenli bir sığınak bulmaya çalışın |
| **E** | Envanter - Mevcut kaynakları görün |
| **R** | Dinlenme - Enerji ve sağlık geri kazanın |
| **F** | Tehlike - Tehlike bölgesinden kurtulmaya çalışın |
| **P** | Şifre - Şifreli kapıyı açmayı deneyin |
| **X** | Çıkış - Oyundan çıkın |

## Komutların Detaylı Açıklaması

### A - Avlanma
Hayatta kalmak için yemek bulmanız gerekir. Avlanırken:
- Enerji 20 azalır
- %60 ihtimalle başarısız olursunuz
- %30 ihtimalle yaralanırsınız (sağlık -20)
- Başarılı olursanız yemek sayınız artar

### S - Sığınak Arama
Dinleme sırasında sağlık kazanmak için sığınağa ihtiyacınız vardır:
- Zaten sığınağınız varsa yeni bir arama yapamazsınız
- %40 ihtimalle sığınak bulursunuz (veya yüksek enerjiniz varsa garantili)
- Başarısız olursanız tekrar deneyebilirsiniz

### E - Envanter
Mevcut durumunuzu kontrol etmek için kullanılır. Hiç bir ceza yoktur.

### R - Dinlenme
Enerji ve sağlık geri kazanmak için:
- Enerji 30 artar (maksimum 100)
- Sığınağınız varsa sağlık da 10 artar
- Sığınaksız dinlenirseniz sadece enerji artar

### F - Tehlike
Tehlike bölgesinde 5 tur hayatta kalmaya çalışırsınız:
- Her turda %20 ihtimalle kurtulursunuz
- %40 ihtimalle 5-14 sağlık kaybedersiniz
- %40 ihtimalle güvenli kalırsınız
- Sağlık sıfıra inerse oyun biter

### P - Şifre
Şifreli kapıyı açmak için çalışırsınız:
- Doğru cevap: **G**
- Her 2 yanlış denemede enerji 5 azalır
- Başarılı olursanız 2 yemek ödülü kazanırsınız

## Oyun Bitişi Koşulları

Oyun aşağıdaki durumlarda biter:
- **Sağlık ≤ 0**: Ölüm
- **Enerji ≤ 0**: Tamamen bitkinlik
- **X komutunu girme**: Oyundan çıkma

## Strateji İpuçları

1. **Dengeyi koruyun**: Sağlık ve enerji her ikisini de yönetmeye çalışın.
2. **Sığınak bulun**: Erken oyunda sığınak bulmak öncelikli olmalıdır.
3. **Tehlikeden kaçının**: Tehlike bölgesine girmeden önce enerji ve sağlık yeterli seviyede olmalıdır.
4. **Şifre bonusu**: Şifreli kapıyı açmak iyi bir ödül sağlar (2 yemek).

## Teknik Gereksinimler

- C derleyicisi (gcc, clang, vb.)
- Standart C kütüphaneleri
- Terminal veya konsol uygulaması

## Derleme ve Çalıştırma

```bash
gcc survival_simulator.c -o simulator
./simulator
```

## Oyun Özeti

Bu oyun, kaynak yönetimi ve risk almanın stratejik kombinasyonunu gerektiren eğlenceli bir metin tabanlı macera sunur. Hayatta kalmak için her kararı iyi düşünmelisiniz!
