#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm> // Untuk find_if
#include <iomanip>

using namespace std;


const int MAX_SIZE = 100; // Ukuran maksimal array barang

// Struktur data untuk menyimpan informasi barang
struct Barang {
  int id; // ID 4 angka unik untuk setiap barang
  string nama;
  string kategori;
  int stok;
};


enum StatusStok {
    STOK_HABIS,
    STOK_HAMPIR_HABIS,
    STOK_BANYAK
};

StatusStok hitungStatusStok(int stok) {
    if (stok == 0) {
        return STOK_HABIS;
    } else if (stok > 0 && stok <= 10) {
        return STOK_HAMPIR_HABIS;
    } else {
        return STOK_BANYAK;
    }
}

// Fungsi untuk menambahkan barang baru ke dalam sistem stok
void tambahBarang(Barang daftarBarang[], unordered_map<int, Barang>& mapBarang, int& count) {
    Barang barangBaru;
    cout << "Masukkan nama barang: ";
    cin >> barangBaru.nama;

    // Tambahkan pilihan kategori
    cout << "Pilih kategori barang:\n"
         << "1. Art\n"
         << "2. Sport\n"
         << "3. Furniture\n"
         << "4. School\n"
         << "5. Household\n"
         << "6. Fashion\n"
         << "7. Other\n"
         << "Pilihan: ";
    int kategoriPilihan;
    cin >> kategoriPilihan;
    switch (kategoriPilihan) {
        case 1:
            barangBaru.kategori = "Art";
            break;
        case 2:
            barangBaru.kategori = "Sport";
            break;
        case 3:
            barangBaru.kategori = "Furniture";
            break;
        case 4:
            barangBaru.kategori = "School";
            break;
        case 5:
            barangBaru.kategori = "Household";
            break;
        case 6:
            barangBaru.kategori = "Fashion";
            break;
        case 7:
            barangBaru.kategori = "Other";
            break;
        default:
            cout << "Pilihan kategori tidak valid." << endl;
            return;
    }

    cout << "Masukkan stok barang: ";
    cin >> barangBaru.stok;

    // Menambahkan ID 4 angka unik
  int id;
  do {
    id = rand() % 10000; // Menghasilkan angka random 4 digit
  } while (mapBarang.find(id) != mapBarang.end()); // Pastikan ID unik

  // Menambahkan barang ke array dan map
  if (count < MAX_SIZE) {
    daftarBarang[count].id = id;
    daftarBarang[count].nama = barangBaru.nama;
    daftarBarang[count].kategori = barangBaru.kategori;
    daftarBarang[count].stok = barangBaru.stok;
    mapBarang.insert(make_pair(id, daftarBarang[count]));
    count++;
    cout << "Barang berhasil ditambahkan ke dalam sistem." << endl;
  } else {
    // ... (kode untuk pesan sistem penuh)
  }
}

// Fungsi untuk melakukan pembaruan stok setelah transaksi pembelian atau penjualan
void updateStok(Barang daftarBarang[], unordered_map<int, Barang>& mapBarang, int count) {
  int idBarang;
  string namaBarang;
  int jumlahStokBaru;

  cout << "Masukkan ID barang yang ingin diperbarui stoknya: ";
  cin >> idBarang;
  cout << "Masukkan nama barang yang ingin diperbarui stoknya: ";
  cin >> namaBarang;
  cout << "Masukkan jumlah stok baru: ";
  cin >> jumlahStokBaru;

  // Mencari barang berdasarkan ID dan nama di mapBarang dan array daftarBarang
  auto it = mapBarang.find(idBarang);
  bool barangDitemukan = false;
  for (int i = 0; i < count; ++i) {
    if (daftarBarang[i].id == idBarang && daftarBarang[i].nama == namaBarang) {
      barangDitemukan = true;
      break;
    }
  }

  // Jika barang ditemukan
  if (it != mapBarang.end() && barangDitemukan) {
    // Memperbarui stok di mapBarang dan array
    it->second.stok = jumlahStokBaru;
    for (int i = 0; i < count; ++i) {
      if (daftarBarang[i].id == idBarang && daftarBarang[i].nama == namaBarang) {
        daftarBarang[i].stok = jumlahStokBaru;
        break;
      }
    }

    // Menampilkan pesan bahwa stok barang berhasil diperbarui
    cout << "Stok barang '" << namaBarang << "' dengan ID " << idBarang << " berhasil diperbarui." << endl;
  } else {
    // Jika barang tidak ditemukan
    cout << "Barang dengan ID " << idBarang << " dan nama '" << namaBarang << "' tidak ditemukan dalam sistem." << endl;
  }
}



// Fungsi untuk mencari barang berdasarkan kategori atau nama
void cariBarang(const unordered_map<int, Barang>& mapBarang) {
    cout << "Pilih kategori barang yang ingin dicari:\n"
        << "1. Art\n"
        << "2. Sport\n"
        << "3. Furniture\n"
        << "4. School\n"
        << "5. Household\n"
        << "6. Fashion\n"
        << "7. Other\n"
        << "Pilihan: ";
    int kategoriPilihan;
    cin >> kategoriPilihan;

    string kategori;
    switch (kategoriPilihan) {
        case 1:
            kategori = "Art";
            break;
        case 2:
            kategori = "Sport";
            break;
        case 3:
            kategori = "Furniture";
            break;
        case 4:
            kategori = "School";
            break;
        case 5:
            kategori = "Household";
            break;
        case 6:
            kategori = "Fashion";
            break;
        case 7:
            kategori = "Other";
            break;
        default:
            cout << "Pilihan kategori tidak valid." << endl;
            return;
    }

    cout << "Daftar barang dalam kategori '" << kategori << "':" << endl;

    // Iterate through the mapBarang to find matching items and display their latest stock information
    for (const auto& pair : mapBarang) {
        const Barang& barang = pair.second;
        if (barang.kategori == kategori) {
            cout << "ID: " << barang.id << ", Nama: " << barang.nama << ", Kategori: " << barang.kategori << ", Stok: " << barang.stok << endl;
            StatusStok status = hitungStatusStok(barang.stok);
            switch (status) {
                case STOK_HABIS:
                    cout << setw(20) << "Stok Habis" << endl;
                    break;
                case STOK_HAMPIR_HABIS:
                    cout << setw(20) << "Stok Hampir Habis" << endl;
                    break;
                case STOK_BANYAK:
                    cout << setw(20) << "Stok Banyak" << endl;
                    break;
            }
        }
    }
}

void insertionSort(Barang daftarBarang[], int count, int pilihan) {
    for (int i = 1; i < count; i++) {
        Barang key = daftarBarang[i];
        int j = i - 1;

        // Depending on the chosen criteria, adjust the comparison
        while (j >= 0 && ((pilihan == 1 && daftarBarang[j].kategori > key.kategori) ||
                          (pilihan == 2 && daftarBarang[j].nama > key.nama) ||
                          (pilihan == 3 && daftarBarang[j].stok > key.stok))) {
            daftarBarang[j + 1] = daftarBarang[j];
            j = j - 1;
        }
        daftarBarang[j + 1] = key;
    }
}

void sortBarang(Barang daftarBarang[], int count, int pilihan) {
    switch (pilihan) {
        case 1:
        case 2:
        case 3:
            insertionSort(daftarBarang, count, pilihan);
            break;
        default:
            cout << "Pilihan sorting tidak valid." << endl;
            return;
    }
}

void hapusBarang(unordered_map<int, Barang>& mapBarang, Barang daftarBarang[], int& count) {
    int idBarang;
    cout << "Masukkan ID barang yang ingin dihapus: ";
    cin >> idBarang;

    auto it = mapBarang.find(idBarang);
    if (it != mapBarang.end()) {
        // Remove from the map
        mapBarang.erase(it);

        // Find and remove from the array
        int index = -1;
        for (int i = 0; i < count; ++i) {
            if (daftarBarang[i].id == idBarang) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            for (int i = index; i < count - 1; ++i) {
                daftarBarang[i] = daftarBarang[i + 1];
            }
            count--;
        }

        cout << "Barang dengan ID " << idBarang << " berhasil dihapus." << endl;
    } else {
        cout << "Barang dengan ID tersebut tidak ditemukan." << endl;
    }
}


void lihatLaporan(Barang daftarBarang[], int count) {
    int kriteria;
    cout << "Pilih kriteria pengurutan:\n"
         << "1. Kategori (A-Z)\n"
         << "2. Nama Barang (A-Z)\n"
         << "3. Jumlah Stok (paling sedikit - paling banyak)\n"
         << "Pilihan: ";
    cin >> kriteria;
    
    sortBarang(daftarBarang, count, kriteria);

    cout << "=== Laporan Stok ===" << endl;
    cout << setw(5) << left << "ID" << setw(20) << left << "Nama Barang" << setw(15) << "Kategori" << setw(10) << "Stok" << setw(20) << "Status Stok" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    for (int i = 0; i < count; ++i) {
        cout << setw(5) << left << daftarBarang[i].id << setw(20) << left << daftarBarang[i].nama << setw(15) << daftarBarang[i].kategori << setw(10) << daftarBarang[i].stok;
        StatusStok status = hitungStatusStok(daftarBarang[i].stok);
        switch (status) {
            case STOK_HABIS:
                cout << setw(20) << "Stok Habis" << endl;
                break;
            case STOK_HAMPIR_HABIS:
                cout << setw(20) << "Stok Hampir Habis" << endl;
                break;
            case STOK_BANYAK:
                cout << setw(20) << "Stok Banyak" << endl;
                break;
        }
    }
}
// Fungsi untuk membeli barang
void beliBarang(Barang daftarBarang[], int count) {
    string kategori;
    cout << "Pilih kategori barang:\n"
         << "1. Art\n"
         << "2. Sport\n"
         << "3. Furniture\n"
         << "4. School\n"
         << "5. Household\n"
         << "6. Fashion\n"
         << "7. Other\n"
         << "Pilihan: ";
    int kategoriPilihan;
    cin >> kategoriPilihan;
    switch (kategoriPilihan) {
        case 1:
            kategori = "Art";
            break;
        case 2:
            kategori = "Sport";
            break;
        case 3:
            kategori = "Furniture";
            break;
        case 4:
            kategori = "School";
            break;
        case 5:
            kategori = "Household";
            break;
        case 6:
            kategori = "Fashion";
            break;
        case 7:
            kategori = "Other";
            break;
        default:
            cout << "Pilihan kategori tidak valid." << endl;
            return;
    }

    bool found = false;
  cout << "Daftar barang dalam kategori '" << kategori << "':" << endl;
  for (int i = 0; i < count; ++i) {
    if (daftarBarang[i].kategori == kategori) {
      cout << "ID: " << daftarBarang[i].id << ", Nama: " << daftarBarang[i].nama << ", Kategori: " << daftarBarang[i].kategori << ", Stok: " << daftarBarang[i].stok << endl;
      found = true;
    }
    }
    if (!found) {
        cout << "Tidak ada barang dalam kategori '" << kategori << "'." << endl;
        return;
    }

    string namaBarang;
  int idBarang;
  int jumlahBeli;
  cout << "Masukkan ID barang yang dibeli: ";
  cin >> idBarang;
  cout << "Masukkan nama barang yang dibeli: ";
  cin >> namaBarang; // Opsional: Tetap masukkan nama barang untuk verifikasi
  cout << "Masukkan jumlah barang yang dibeli: ";
  cin >> jumlahBeli;

  // Cari barang dalam daftar
  bool barangDitemukan = false;
  for (int i = 0; i < count; ++i) {
    if (daftarBarang[i].id == idBarang && daftarBarang[i].nama == namaBarang) {
      if (daftarBarang[i].stok >= jumlahBeli) {
        daftarBarang[i].stok -= jumlahBeli; // Kurangi stok
        barangDitemukan = true;
        cout << "Transaksi berhasil. ID Barang: " << idBarang << ", Nama Barang: " << namaBarang << ", Jumlah Beli: " << jumlahBeli << endl;
        } else {
        cout << "stok tidak mencukupi" << endl;
        }
      }
      else cout << "barang tidak ditemukan" << endl;
      break; // Keluar dari loop setelah barang ditemukan
    }
  }



int main(){
    Barang daftarBarang[MAX_SIZE]; // Array untuk menyimpan barang-barang
    unordered_map<int, Barang> mapBarang; // Map untuk pencarian barang berdasarkan ID dengan hash table
    int count = 0;

    while (true) {
        cout << "Selamat datang di toko lopidopii <3\n"
             << "Yuk pilih transaksi :D\n"
             << "1. Penjualan\n"
             << "2. Pembelian\n"
             << "3. Out\n"
             << "Pilihan: ";
        int transaksi;
        cin >> transaksi;

        switch (transaksi) {
            case 1:
                // Menu untuk transaksi penjualan
                cout << "Menu transaksi penjualan:\n"
                     << "1. Tambah Barang\n"
                     << "2. Update Stok\n"
                     << "3. Lihat Laporan\n"
                     << "4. Hapus barang\n"
                     << "5. Keluar ke menu utama\n"
                     << "Pilihan: ";
                int pilihanPenjualan;
                cin >> pilihanPenjualan;

                switch (pilihanPenjualan) {
                    case 1:
                        tambahBarang(daftarBarang, mapBarang, count);
                        break;
                    case 2:
                        updateStok(daftarBarang, mapBarang, count);
                        break;
                    case 3:
                        lihatLaporan(daftarBarang, count);
                        break;
                    case 4:
                        hapusBarang(mapBarang, daftarBarang, count); 
                        break;
                    case 5:
                        break;
                    default:
                        cout << "Pilihan tidak valid." << endl;
                }
                break;
            case 2:
                // Menu untuk transaksi pembelian
                cout << "Menu transaksi pembelian:\n"
                     << "1. Membeli barang\n"
                     << "2. Keluar ke menu utama\n"
                     << "Pilihan: ";
                int pilihanPembelian;
                cin >> pilihanPembelian;

                switch (pilihanPembelian) {
                    case 1:
                        beliBarang(daftarBarang, count);
                        break;
                    case 2:
                        break;
                    default:
                        cout << "Pilihan tidak valid." << endl;
                }
                break;
            case 3:
                cout << "Sampai jumpa lagi. Kami akan menantimu selalu." << endl;
                return 0;
            default:
                 cout << "Pilihan tidak valid." << endl;
        }
    }

    return 0;
}