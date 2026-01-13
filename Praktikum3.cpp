#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

// Struct untuk menyimpan data dari file
struct Data {
    int id;
    string nama;
    int nilai;
};

int main() {
    vector<Data> dataVector;

    cout << "=== PROGRAM BACA FILE ===" << endl << endl;

    // Coba beberapa nama file yang mungkin
    string filenames[] = {
        "bacaAku.txt",
        "bacaaku.txt",
        "BacaAku.txt",
        "BACAAKU.TXT"
    };

    ifstream file;
    string namaFileBenar = "";

    // Coba satu per satu
    for (int i = 0; i < 4; i++) {
        cout << "Mencoba: " << filenames[i] << " ... ";
        file.open(filenames[i]);
        if (file.is_open()) {
            namaFileBenar = filenames[i];
            cout << "BERHASIL!" << endl;
            break;
        }
        else {
            cout << "tidak ada" << endl;
            file.clear();
        }
    }

    if (!file.is_open()) {
        cout << "\n[ERROR] File tidak ditemukan dengan berbagai variasi nama!" << endl;
        cout << "\nCek hal berikut:" << endl;
        cout << "1. Pastikan file bernama PERSIS: bacaAku.txt" << endl;
        cout << "2. Bukan bacaAku.txt.txt (ekstensi ganda)" << endl;
        cout << "3. File di folder yang sama dengan program .exe ini" << endl;
        cout << "\nCara membuat file yang benar:" << endl;
        cout << "- Buka Notepad" << endl;
        cout << "- Ketik data (lihat contoh di bawah)" << endl;
        cout << "- File > Save As" << endl;
        cout << "- Save as type: pilih 'All Files (*.*)'" << endl;
        cout << "- File name: bacaAku.txt" << endl;
        cout << "- Klik Save" << endl;
        cout << "\nContoh isi file:" << endl;
        cout << "1; Tono; 82;" << endl;
        cout << "2; Ani; 90;" << endl;

        system("pause");
        return 1;
    }

    cout << "\n[OK] File ditemukan: " << namaFileBenar << endl;
    cout << "Membaca isi file...\n" << endl;

    string line;
    int baris = 0;

    while (getline(file, line)) {
        baris++;
        cout << "Baris " << baris << ": [" << line << "]" << endl;

        if (line.empty() || line == "\r" || line == "\n") {
            cout << "  -> Baris kosong, skip" << endl;
            continue;
        }

        // Parsing data
        try {
            Data temp;
            size_t pos1 = line.find(';');
            size_t pos2 = line.find(';', pos1 + 1);
            size_t pos3 = line.find(';', pos2 + 1);

            if (pos1 == string::npos) {
                cout << "  -> ERROR: Tidak ada titik koma pertama!" << endl;
                continue;
            }

            // Ambil ID
            string id_str = line.substr(0, pos1);
            temp.id = stoi(id_str);

            // Ambil Nama
            string nama_str = line.substr(pos1 + 1, pos2 - pos1 - 1);
            // Hapus spasi
            size_t start = nama_str.find_first_not_of(" \t\r\n");
            size_t end = nama_str.find_last_not_of(" \t\r\n");
            if (start != string::npos && end != string::npos) {
                temp.nama = nama_str.substr(start, end - start + 1);
            }
            else {
                temp.nama = nama_str;
            }

            // Ambil Nilai
            string nilai_str = line.substr(pos2 + 1);
            // Hapus spasi dan karakter lain
            start = nilai_str.find_first_not_of(" \t\r\n;");
            end = nilai_str.find_last_not_of(" \t\r\n;");
            if (start != string::npos && end != string::npos) {
                nilai_str = nilai_str.substr(start, end - start + 1);
            }
            temp.nilai = stoi(nilai_str);

            dataVector.push_back(temp);
            cout << "  -> Berhasil: ID=" << temp.id << " Nama=" << temp.nama << " Nilai=" << temp.nilai << endl;

        }
        catch (exception& e) {
            cout << "  -> ERROR parsing: " << e.what() << endl;
        }
    }

    file.close();

    // Tampilkan hasil akhir
    cout << "\n=======================================" << endl;
    cout << "HASIL AKHIR" << endl;
    cout << "=======================================" << endl;
    cout << "Total data berhasil dibaca: " << dataVector.size() << endl << endl;

    if (dataVector.size() > 0) {
        for (size_t i = 0; i < dataVector.size(); i++) {
            cout << "Data ke-" << (i + 1) << ":" << endl;
            cout << "  ID    : " << dataVector[i].id << endl;
            cout << "  Nama  : " << dataVector[i].nama << endl;
            cout << "  Nilai : " << dataVector[i].nilai << endl;
            cout << "---------------------------------------" << endl;
        }
    }
    else {
        cout << "Tidak ada data yang berhasil dibaca!" << endl;
    }

    system("pause");
    return 0;
}