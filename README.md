# 42 Rush01 - Skyscrapers Puzzle Solver

42 Piscine kapsamında geliştirilmiş, $4 \times 4$ ızgara üzerinde çalışan Backtracking tabanlı gökdelen bulmaca çözücüsü.

---

## Proje Hakkında

Rush01, dışarıdan verilen bakış açısı kısıtlarına (yukarı, aşağı, sol, sağ) uygun olarak $1$'den $4$'e kadar olan bina yüksekliklerini yerleştiren bir mantık algoritmasıdır.

### Temel Kurallar
* **Benzersizlik:** Her satır ve sütunda $1, 2, 3, 4$ sayıları yalnızca birer kez yer alabilir.
* **Görünürlük:** Yüksek binalar arkalarındaki daha kısa binaları gizler. Dışarıdan bakıldığında yalnızca kendisinden önceki tüm binalardan daha yüksek olan binalar sayılır.

---

## Dosya Yapısı

* `main.c`: Argüman denetimi, 16 sayılık dizinin ayrıştırılması (`parse_args`) ve hata yönetimi.
* `solver.c`: Rekürsif geri izleme motoru (`solve`) ve çözümün matris formatında ekrana yazdırılması (`print_grid`).
* `check.c`: Satır/sütun çakışma kontrolü (`is_duplicate`) ve sınır görünüm doğrulamaları (`check_case`).
* `views.c`: Dört yönden (`col_up`, `col_down`, `row_left`, `row_right`) görünen bina sayısını hesaplayan fonksiyonlar.

---