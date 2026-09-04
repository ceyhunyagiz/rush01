<div align="center">

# 🏙️ Rush01 — Skyscraper Puzzle Solver

**42 Piscine · C Language · Backtracking Algorithm**

![C](https://img.shields.io/badge/language-C-00599C?style=for-the-badge&logo=c&logoColor=white)
![42](https://img.shields.io/badge/42-Piscine-000000?style=for-the-badge)
![Norm](https://img.shields.io/badge/norminette-passing-brightgreen?style=for-the-badge)
![Build](https://img.shields.io/badge/build-passing-success?style=for-the-badge)

*4×4 bir ızgara üzerinde, verilen görünürlük ipuçlarına göre bina yüksekliklerini yerleştiren backtracking tabanlı bir bulmaca çözücüsü.*

</div>

---

## 📖 Proje Hakkında

**Rush01**, klasik *skyscraper puzzle* (gökdelen bulmacası) mantığını C dilinde, sadece `write`, `malloc` ve `free` fonksiyonlarına izin verilerek çözen bir programdır — `printf`, `atoi`, `string.h` yasak, her şey sıfırdan yazıldı.

Program, komut satırından 16 sayılık tek bir string alır (4 sütun-üst, 4 sütun-alt, 4 satır-sol, 4 satır-sağ görünürlük değeri) ve bu kısıtları sağlayan **ilk** 4×4 çözümü ekrana yazdırır. Çözüm yoksa `Error` basar.

---

## 🧩 Kurallar

| Kural | Açıklama |
|---|---|
| **Benzersizlik** | Her satır ve her sütunda `1, 2, 3, 4` değerleri **birer kez** bulunur (Latin kare). |
| **Görünürlük** | Bir yönden bakıldığında, kendisinden önceki **tüm** binalardan daha yüksek olan bina "görünür" sayılır. Kısa binalar, önündeki uzun binanın arkasında saklanır. |

**Örnek:** Bir satır soldan sağa `3 2 4 1` diye dizilmişse:

```
Soldan bakış:  3 → görünür (ilk bina)
               2 → görünmez (3'ten kısa, arkada kaldı)
               4 → görünür (3'ten uzun, öne çıktı)
               1 → görünmez (4'ün arkasında)
=> Soldan görünen bina sayısı: 2

Sağdan bakış:  1 → görünür (en sağdaki her zaman görünür)
               4 → görünür (1'den uzun)
               2, 3 → görünmez (4'ün arkasında)
=> Sağdan görünen bina sayısı: 2
```

---

## 📂 Dosya Yapısı

```
ex00/
├── main.c      → Girdi doğrulama, ayrıştırma ve programın başlatılması
├── solver.c    → Rekürsif backtracking motoru + çıktı basma
├── check.c     → Tekrar kontrolü ve satır/sütun kısıt doğrulaması
└── views.c     → 4 yönden görünürlük hesaplayan fonksiyonlar
```

---

## 🔍 Kod Detayları

### `main.c` — Girdi ve Akış Kontrolü

| Fonksiyon | Görevi |
|---|---|
| `parse_args()` | Gelen string'i karakter karakter gezer; `'1'`–`'4'` arası karakterleri sayıya çevirip `entry[]` dizisine yazar, boşlukları atlar. Geçersiz karakter, aralık dışı değer veya 16'dan farklı sayıda giriş varsa `0` döner (hata). |
| `ft_puterror()` | `write` ile doğrudan `"Error\n"` yazdırır — `printf` yasak olduğu için kendi hata basma fonksiyonumuz. |
| `main()` | Argüman sayısını (`argc == 2`) ve `parse_args()` sonucunu kontrol eder, grid'i sıfırlar, `solve()`'u çağırır; sonuca göre `print_grid()` veya `ft_puterror()` çalıştırır. |

### `solver.c` — Backtracking Motoru

| Fonksiyon | Görevi |
|---|---|
| `solve()` | Izgarayı sırayla (satır-satır) doldurur. Her hücrede 1–4 arasını dener; `is_duplicate()` ile satır/sütun tekrarını, `check_case()` ile görünürlük kısıtını kontrol eder. Uymazsa hücreyi sıfırlayıp bir sonraki değeri dener (**backtrack**). 16. hücreye ulaşınca çözüm bulunmuş demektir. |
| `print_grid()` | Çözülmüş 4×4 ızgarayı `write` ile, sayılar arasında tek boşluk ve satır sonunda `\n` ile ekrana basar. |

### `check.c` — Kısıt Doğrulama

| Fonksiyon | Görevi |
|---|---|
| `is_duplicate()` | Bir sayının, o hücrenin bulunduğu satır veya sütunda daha önce kullanılıp kullanılmadığını kontrol eder. |
| `check_case()` | **Akıllı erken eleme (pruning):** Bir sütun tamamlandığında (`row == 3`) o sütunun üst/alt görünürlüğünü, bir satır tamamlandığında (`col == 3`) o satırın sol/sağ görünürlüğünü anında kontrol eder — yanlış yola en baştan girmeyi önler, aramayı hızlandırır. |

### `views.c` — Görünürlük Hesaplama

| Fonksiyon | Yön |
|---|---|
| `check_col_up()` | Sütunu yukarıdan aşağı tarar (üstten bakış). |
| `check_col_down()` | Sütunu aşağıdan yukarı tarar (alttan bakış). |
| `check_row_left()` | Satırı soldan sağa tarar (soldan bakış). |
| `check_row_right()` | Satırı sağdan sola tarar (sağdan bakış). |

Her fonksiyon, o yöndeki "o ana kadarki en yüksek bina" değerini takip ederek görünen bina sayısını sayar ve beklenen değerle karşılaştırır.

---

## ⚙️ Derleme ve Çalıştırma

```bash
cc -Wall -Wextra -Werror -o rush01 *.c
```

```bash
./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
```

```
1 2 3 4
2 3 4 1
3 4 1 2
4 1 2 3
```

**Girdi formatı:** `col1top col2top col3top col4top col1bottom col2bottom col3bottom col4bottom row1left row2left row3left row4left row1right row2right row3right row4right` — 16 sayı, her biri `1`–`4` arası.

---

## ✅ Norm ve Kısıt Uyumluluğu

- ✔️ `-Wall -Wextra -Werror` ile **uyarısız** derleme
- ✔️ Sadece izin verilen fonksiyonlar: `write`, `malloc`, `free`
- ✔️ `for` / `switch` / `case` / `goto` / ternary **kullanılmadı** — tüm döngüler `while`
- ✔️ 42 Norm'a uygun isimlendirme, girinti, fonksiyon/değişken sınırları
- ✔️ Geçersiz girdi ve çözümsüz durumlar için tutarlı `Error` çıkışı

---

## 👥 Ekip

**42 Kocaeli — C Piscine**

---

<div align="center">

*Bu proje, 42 Piscine'in AI politikasına uygun şekilde, ekip üyeleri tarafından anlaşılıp savunulabilecek biçimde geliştirilmiştir.*

</div>