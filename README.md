# Sistem Manajemen Stok Barang Menggunakan Struktur Data Map, Array, Hash-Table, dan Hashing

Pada masa era digital yang semakin berkembang saat ini, efisiensi operasional merupakan salah satu kunci utama kesuksesan bisnis. Aspek penting dalam operasional bisnis adalah manajemen stok barang yang akurat. Penelitian ini bertujuan untuk merancang dan mengimplementasikan sistem manajemen stok barang yang efisien menggunakan struktur data. Metode penelitian yang dilakukan adalah membuat program menggunakan bahasa pemrograman C++ dengan menerapkan struktur data array, sorting, unordered_map, hasing, dan hash table. Hasil penelitian ini adalah sebuah program yang mampu membantu pada permasalahan dalam manajemen stok barang dengan akurat dan efisien

## Metode
### Menu Penjualan
1. Pada opsi ‘Tambah Barang’ di fungsi ‘tambahBarang’, dapat dimasukkan nama barang, kategori, dan jumlah stok, lalu akan diberikan ID barang secara otomatis. Kompleksitas ruang pada fungsi ini adalah O(1) untuk variabel lokal, namun O(n) untuk penyimpanan dalam map dan array. Hal ini karena ruang yang digunakan variabel lokal seperti ‘barangBaru’ dan ‘kategoriPilihan’ adalah konstan. Namun, untuk penyimpanan dalam unordered map dan array meningkat linear dengan jumlah barang. Kompleksitas waktu pada fungsi ini adalah O(1) untuk penambahan ke map dan array. Hal ini karena ‘unordered_map’ menggunakan fungsi hash yang efektif dan beban tabel hash tetap rendah dan array memiliki cukup ruang sehingga elemen ditambahkan di akhir tanpa perlu memindahkan elemen.
2. Pada opsi ‘Update Stok’, di fungsi ‘updateStok’ dapat dimasukkan ID barang, nama barang, dan jumlah stok yang baru. Pada fungsi ini, kompleksitas ruangnya adalah O(1) karena fungsi ini tidak menggunakan ruang tambahan yang signifikan selain variabel lokal ‘id’ dan ‘stokBaru’, sedangkan kompleksitas waktunya adalah O(1) karena pencarian dan pembaharuan di ‘unordered_map’ memiliki kompleksitas konstan menggunakan hashing
3. Pada opsi ‘Lihat Laporan’ di fungsi ‘lihatLaporan’, dapat dipilih terlebih dahulu jenis sorting yang diinginkan, lalu akan keluar hasilnya yang menampilkan ID barang, nama barang, kategori, jumlah stok, dan status stok. Kompleksitas ruang pada fungsi ini adalah O(1) karena fungsi ini hanya menggunakan ruang untuk variabel lokal yang tetap, terlepas dari jumlah barang, sedangkan kompleksitas waktu pada fungsi ini adalah O(n) karena fungsi ini mencetak laporan untuk setiap barang dalam daftar, sehingga kompleksitasnya linear terhadap jumlah barang
4. Pada opsi ‘Hapus Barang’ di fungsi ‘hapusBarang’, dapat dimasukkan nama dan ID barang yang ingin dihapus. Kompleksitas ruang pada fungsi ini adalah O(1) karena tidak ada ruang tambahan yang digunakan relatif terhadap ukuran input, sedangkan kompleksitas waktu pada fungsi ini adalah O(n) di mana n adalah jumlah barang (‘count’) dalam inventaris sehingga membutuhkan pencarian untuk menemukan barang yang akan dihapus.
### Menu Pembelian
1. Pada opsi ‘Membeli Barang’ di fungsi ‘beliBarang’, kompleksitas ruang pada opsi “Membeli Barang” adalah O(1) karena fungsi ini tidak menggunakan ruang tambahan yang signifikan selain variabel lokal ‘id’ dan ‘jumlah’, sedangkan kompleksitas waktunya adalah O(1) karena pencarian dan pembaruan stok dalam ‘unordered_map’ memiliki kompleksitas konstan.

## Team
| Nama                       |
|----------------------------|
| Tiffany Anastasia Jocelyn |
| Noer Hanifah Suganda      |
| Aditiya Purwansyah        |
