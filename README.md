# TUGAS PRAKTIKUM 03 - FILE DAN VECTOR

**Nama:** M. Krisna Y.P  
**Kelas:** Malam Karyawan TI C  
**Mata Kuliah:** Struktur Data / Pemrograman C++

---

## 📋 Deskripsi Tugas

Program ini dibuat untuk menyelesaikan **Soal Latihan 9.7** yang meminta untuk:
1. Membuat file dengan format `.txt` bernama `bacaAku.txt`
2. Membaca file tersebut menggunakan C++
3. Menyimpan data ke dalam struktur data **Vector**

---

## 📁 Struktur File

```
TUGAS-PRAKTIKUM-03-FILE-DAN-VECTOR/
│
├── README.md                 # Dokumentasi project
├── main.cpp                  # Source code program utama
├── bacaAku.txt              # File data input (contoh)
└── program.exe              # Executable file (hasil compile)
```

---

## 📝 Format File Input

File `bacaAku.txt` memiliki format:
```
id; nama; nilai;
```

**Contoh isi file:**
```
1; Tono; 82;
2; Ani; 90;
```

**Keterangan:**
- `id` : Nomor identitas (integer)
- `nama` : Nama mahasiswa (string)
- `nilai` : Nilai mahasiswa (integer)
- Setiap field dipisahkan dengan titik koma (`;`)

---

## 🔧 Cara Kompilasi dan Menjalankan

### Kompilasi Program

**Menggunakan g++ (MinGW/GCC):**
```bash
g++ main.cpp -o program
```

**Menggunakan Dev-C++:**
- Buka file `main.cpp`
- Klik `Execute` → `Compile & Run` (F11)

### Menjalankan Program

**Windows:**
```bash
program.exe
```

**Linux/Mac:**
```bash
./program
```

---

## 💻 Cara Menggunakan Program

1. **Pastikan file `bacaAku.txt` sudah dibuat** dan berada di folder yang sama dengan program

2. **Jalankan program**
   - Program akan otomatis mencari file dengan berbagai variasi nama
   - Jika tidak ditemukan, program akan memberikan instruksi

3. **Program akan menampilkan:**
   - Proses pembacaan setiap baris
   - Parsing data (ID, Nama, Nilai)
   - Hasil akhir semua data yang berhasil dibaca

4. **Output akan menampilkan:**
   ```
   === PROGRAM BACA FILE ===
   
   Mencoba: bacaAku.txt ... BERHASIL!
   
   [OK] File ditemukan: bacaAku.txt
   Membaca isi file...
   
   Baris 1: [1; Tono; 82;]
     -> Berhasil: ID=1 Nama=Tono Nilai=82
   Baris 2: [2; Ani; 90;]
     -> Berhasil: ID=2 Nama=Ani Nilai=90
   
   =======================================
   HASIL AKHIR
   =======================================
   Total data berhasil dibaca: 2
   
   Data ke-1:
     ID    : 1
     Nama  : Tono
     Nilai : 82
   ---------------------------------------
   Data ke-2:
     ID    : 2
     Nama  : Ani
     Nilai : 90
   ---------------------------------------
   ```

---

## 🎯 Fitur Program

### ✅ Fitur Utama
- [x] Membaca file teks eksternal
- [x] Parsing data dengan delimiter (titik koma)
- [x] Menyimpan data ke struktur `struct`
- [x] Menggunakan `vector` sebagai container dinamis
- [x] Menampilkan data yang telah dibaca

### ✅ Fitur Tambahan
- [x] **Multi-attempt file opening** - Mencoba berbagai variasi nama file
- [x] **Error handling** - Try-catch untuk menangkap exception
- [x] **Data cleaning** - Menghapus spasi dan karakter tidak perlu
- [x] **Detailed debugging** - Menampilkan proses pembacaan setiap baris
- [x] **User-friendly messages** - Pesan error yang jelas dan instruktif

---

## 📚 Konsep yang Digunakan

### 1. **Struct (Structure)**
```cpp
struct Data {
    int id;
    string nama;
    int nilai;
};
```
Digunakan untuk mengelompokkan beberapa variabel dengan tipe data berbeda.

### 2. **Vector**
```cpp
vector<Data> dataVector;
```
Container dinamis dari C++ STL untuk menyimpan elemen dengan ukuran fleksibel.

### 3. **File Handling**
```cpp
ifstream file("bacaAku.txt");
getline(file, line);
```
Membaca file menggunakan `ifstream` dan `getline()`.

### 4. **String Manipulation**
```cpp
line.substr(pos1, pos2);
line.find(';');
```
Memisahkan dan mengambil bagian tertentu dari string.

### 5. **Exception Handling**
```cpp
try {
    // kode yang mungkin error
} catch (exception& e) {
    // tangani error
}
```
Menangkap dan menangani error saat runtime.

---

## 🔍 Algoritma Program

```
1. START
2. Deklarasi vector<Data> untuk menyimpan data
3. Coba buka file dengan berbagai variasi nama:
   - bacaAku.txt
   - bacaaku.txt
   - BacaAku.txt
   - BACAAKU.TXT
4. IF file tidak ditemukan THEN
     Tampilkan pesan error dan instruksi
     EXIT
   END IF
5. WHILE ada baris dalam file DO
     Baca satu baris
     IF baris kosong THEN
       CONTINUE
     END IF
     Parse data:
       - Cari posisi titik koma (delimiter)
       - Extract ID dari awal hingga titik koma pertama
       - Extract Nama dari titik koma pertama hingga kedua
       - Extract Nilai dari titik koma kedua hingga akhir
       - Bersihkan spasi pada setiap field
     Simpan ke struct Data
     Push struct ke vector
   END WHILE
6. Tutup file
7. Tampilkan semua data dari vector
8. END
```

---

## 🛠️ Troubleshooting

### ❌ Problem: File tidak ditemukan

**Solusi:**
1. Pastikan file bernama **persis** `bacaAku.txt` (perhatikan huruf besar/kecil)
2. Letakkan file di **folder yang sama** dengan program `.exe`
3. Pastikan ekstensi file `.txt` bukan `.txt.txt`
4. Buka File Explorer → View → Centang "File name extensions" untuk melihat ekstensi

### ❌ Problem: Data tidak terbaca dengan benar

**Solusi:**
1. Pastikan format data benar: `id; nama; nilai;`
2. Gunakan titik koma (`;`) sebagai pemisah
3. Buat file menggunakan **Notepad**, bukan Word
4. Saat save, pilih "All Files (*.*)" bukan "Text Documents"

### ❌ Problem: Error saat compile

**Solusi:**
1. Pastikan compiler C++ sudah terinstall (MinGW/GCC)
2. Pastikan semua library tersedia (`iostream`, `fstream`, `vector`, `string`, `cstdlib`)
3. Gunakan C++11 atau lebih baru

---

## 📊 Contoh Test Case

### Test Case 1: File Normal
**Input (bacaAku.txt):**
```
1; Tono; 82;
2; Ani; 90;
```
**Output:**
```
Total data berhasil dibaca: 2
Data ke-1: ID=1 Nama=Tono Nilai=82
Data ke-2: ID=2 Nama=Ani Nilai=90
```

### Test Case 2: File dengan Spasi Berlebih
**Input:**
```
1  ;   Tono   ;   82  ;
2;Ani;90;
```
**Output:**
```
Total data berhasil dibaca: 2
Data ke-1: ID=1 Nama=Tono Nilai=82
Data ke-2: ID=2 Nama=Ani Nilai=90
```

### Test Case 3: File dengan Baris Kosong
**Input:**
```
1; Tono; 82;

2; Ani; 90;
```
**Output:**
```
Total data berhasil dibaca: 2
(Baris kosong di-skip)
```

---

## 📖 Library yang Digunakan

| Library | Fungsi |
|---------|--------|
| `<iostream>` | Input/output standar (cout, cin) |
| `<fstream>` | File handling (ifstream, ofstream) |
| `<vector>` | Container vector dinamis |
| `<string>` | Manipulasi string |
| `<cstdlib>` | Fungsi system (pause) |

---

## 🎓 Pembelajaran

Dari tugas ini, saya mempelajari:

1. ✅ Cara membaca file eksternal di C++
2. ✅ Penggunaan `ifstream` dan `getline()`
3. ✅ Implementasi struct untuk data terstruktur
4. ✅ Penggunaan vector sebagai container dinamis
5. ✅ String manipulation (substring, find, trim)
6. ✅ Exception handling dengan try-catch
7. ✅ Best practices dalam file handling
8. ✅ User experience dalam error messaging

---

## 📝 Catatan Penting

⚠️ **Perhatian:**
- File input HARUS dalam format yang benar
- Program case-sensitive pada beberapa sistem operasi
- Pastikan file di folder yang sama dengan executable
- Gunakan Notepad untuk membuat file `.txt`, bukan Word

💡 **Tips:**
- Backup file `bacaAku.txt` sebelum dimodifikasi
- Gunakan debugging output untuk melihat proses pembacaan
- Jika error, baca pesan error dengan teliti

---

## 👨‍💻 Informasi Pengembang

**Nama:** M. Krisna Y.P  
**Kelas:** Malam Karyawan TI C  
**Tahun:** 2025  

---

## 📄 Lisensi

Project ini dibuat untuk keperluan tugas praktikum mata kuliah Struktur Data / Pemrograman C++.

---

## 🙏 Terima Kasih

Terima kasih kepada:
- Dosen pengampu mata kuliah
- Teman-teman kelas yang sudah membantu
- Komunitas Stack Overflow dan C++ documentation

---

**Last Updated:** Januari 2025
