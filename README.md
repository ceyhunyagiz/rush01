<div align="center">

# 🏙️ 42 Rush01 - Skyscrapers Puzzle Solver

**42 Piscine | Backtracking Algoritması ile 4x4 Gökdelen Bulmacası Çözücü**

![Language](https://img.shields.io/badge/Language-C-blue.svg?style=flat-square)
![Norminette](https://img.shields.io/badge/Norminette-v4.1-success.svg?style=flat-square)
![Campus](https://img.shields.io/badge/42-Kocaeli-black.svg?style=flat-square)
![School](https://img.shields.io/badge/Piscine-2026-orange.svg?style=flat-square)

</div>

---

## 📌 Proje Genel Bakışı

**Rush01**, dünyada *Skyscrapers (Gökdelenler)* olarak bilinen mantık bulmacasının C dili ve **Backtracking (Geri İzleme)** algoritması kullanılarak çözülmesidir.

$4 \times 4$'lük bir ızgara üzerinde binaların yükseklikleri $1$ ile $4$ arasında değişir. Projenin ana hedefi, dışarıdan verilen bakış açılarındaki (yukarı, aşağı, sol, sağ) görünür bina sayılarını tam olarak karşılayan tek ve geçerli matris dizilimini üretmektir.

---

## 🧠 Temel Oyun Kuralları

* **Sudoku Kuralı:** Her satırda ve sütunda $1, 2, 3, 4$ sayılarından yalnızca birer adet bulunabilir (tekrar yasaktır).
* **Görünürlük (Perspektif) Kuralı:** Daha uzun bir bina, arkasında kalan kendisinden daha kısa olan binaların görünmesini engeller.
  * *Örnek Sıra:* `[2] [3] [1] [4]`
    * **Soldan Bakış:** $3$ bina görünür (`2`, `3` ve `4`). (`1` sayısı `3`'ün arkasında kaldığı için gizlenir).
    * **Sağdan Bakış:** Yalnızca $1$ bina görünür (En baştaki `4` tüm arkasını kapatır)[cite: 7].

---

## 🏗️ Proje Mimarisi

42 Norminette kurallarına (maksimum 25 satır/fonksiyon, 5 değişken/fonksiyon) tam uyum sağlamak adına modüler bir yapı kurulmuştur[cite: 6, 7]:

| Dosya Adı | Açıklama |
| :--- | :--- |
| **`main.c`** | Terminalden gelen parametreleri (`argc`, `argv`) denetler, 16 sayılık diziyi doğrular ve çözücüyü başlatır[cite: 7]. |
| **`solver.c`** | Rekürsif Backtracking motorudur; hücreleri dener, çıkmaza girince geri adım atar ve çözümü terminale basar[cite: 7]. |
| **`check.c`** | Bir sayının o satır/sütunda tekrar edip etmediğini (`is_duplicate`) ve sınır koşullarını doğrular[cite: 7]. |
| **`views.c`** | 4 farklı yönden (`col_up`, `col_down`, `row_left`, `row_right`) bakıldığında görünen bina sayısını hesaplar[cite: 7]. |

---

## ⚙️ Algoritma: Backtracking (Geri İzleme)

Program deterministik bir arama uzayı taraması yapar:
1. `(0, 0)` hücresinden başlayarak $1$'den $4$'e kadar olan sayıları hücreye yerleştirmeyi dener[cite: 7].
2. Sayı satır veya sütunda tekrar etmiyorsa bir sonraki hücreye geçer[cite: 7].
3. Bir satır veya sütun tamamlandığında dış kısıtları (`views.c`) test eder[cite: 7].
4. Kural ihlali oluştuğunda hücre sıfırlanır (`grid[r][c] = 0`) ve bir önceki adıma dönülerek diğer alternatifler taranır.

---

## 🚀 Derleme ve Kullanım

### Derleme
42 standart derleme bayrakları ile derlenir[cite: 7]:

```bash
cc -Wall -Wextra -Werror -o rush01 *.c
