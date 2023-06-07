Self Service Payment on Coffee Shop
===================================
1. Miftah Rizky Aulia               (2210511022)
2. Muhammad Dihya Al Qalby          (2210511035)
3. Sufyan Al Afi                    (2210511005)
4. Nada Nabila                      (2210511020)
5. Firda Fahria                     (2210511013)
6. Samuel Alexander Mozes Tambunan  (2210511032)

Introduction
------------

Project Implementasi Sistem Self Service Payment Terhadap Pemesanan Kopi dibuat untuk memenuhi tugas ujian akhir mata kuliah praktikum algoritma dan pemrograman 2

Commands
------------

Untuk Mengcompile Program:
```
g++ main.cpp qrcodegen.cpp -o main
```
Jalankan program:
```
./main
```

Features
--------

1. ``Menampilkan Menu Kopi``: Kamu bisa melihat daftar menu kopi beserta harganya.
2. ``Mencari Kopi``: Jika kamu tidak tahu nama kopi yang ingin dipesan, kamu bisa mencarinya di sini.
3. ``Memesan Kopi``: Kamu bisa memesan kopi dengan memilih menu yang diinginkan. Program akan meminta kamu memasukkan ukuran gelas dan topping yang diinginkan.
4. ``Menghitung Total Pembayaran``: Setelah memesan, program akan menghitung total pembayaran sebelum pajak berdasarkan pesanan yang kamu pilih.
5. ``Memilih Metode Pembayaran``: Kamu bisa memilih metode pembayaran antara tunai atau debit.
6. ``Pembayaran dengan QRIS``: Jika kamu memilih metode pembayaran QRIS, program akan menghasilkan kode pembayaran dan menampilkan QR code yang dapat dipindai.
7. ``Mencetak Struk Pembayaran``: Program akan mencetak struk pembayaran yang berisi daftar pesanan, total pembayaran, pajak, total pembayaran setelah pajak, metode pembayaran, nama pemesan, nomor antrian, dan waktu pemesanan.
8. ``Antrian Pemesanan``: Program akan menampilkan antrian pemesanan yang berisi nama pemesan, nomor antrian, dan waktu pemesanan.

Examples
--------

```
Self Service System on Coffee Shop

|               Menu                     Tall(1)        Grande(2)        Venti(3)
----------------------------------------------------------------------------------
| 1. Brewed Coffee                      Rp48000         Rp51000         Rp54000
| 2. Cafe Latte                         Rp60000         Rp63000         Rp66000
| 3. Cappuccino                         Rp55000         Rp58000         Rp61000
| 4. Caramel Macchiato                  Rp59000         Rp62000         Rp65000
| 5. Caramel Mocha                      Rp49000         Rp52000         Rp55000
| 6. Espresso                           Rp50000         Rp53000         Rp56000
| 7. Green Tea                          Rp50000         Rp53000         Rp56000
| 8. Java Chip Frappuccino              Rp58000         Rp61000         Rp64000
| 9. Mocha                              Rp65000         Rp68000         Rp71000
| 10. Signature Chocolate               Rp53000         Rp56000         Rp59000


1. Pesan
2. Cari Kopi
Pilihan (1/2)           :
```
```
Menu Toping yang tersedia:
No   Topping                 Harga
----------------------------------------
1    Hazelnut               Rp1000
2    Chocolate              Rp2000
```
```
Pesanan Anda:
No                               Jumlah     Total Harga
-----------------------------------------------------------
Java Chip Frappuccino               1        Rp64000,-
(Venti)
Cafe Latte                          1        Rp60000,-
(Tall)
-----------------------------------------------------------
                              Total Harga       : Rp126000,-
                              Pajak (5%)        : Rp6300,-
                       Total Harga + Pajak      : Rp132300,-

Metode Pembayaran:
1. QRIS
Pilih metode pembayaran:
```
```
============= Struk Pembayaran ==============
Java Chip Frappuccino(Venti)              1 x Rp64000
  -toping
Cafe Latte(Tall)              1 x Rp60000
  -toping
=============================================
Total Pembayaran                  Rp126000,-
Pajak (5%)                        Rp6300,-


Total                             Rp132300,-
=============================================
Metode Pembayaran       : QRIS
Nama Pemesan            : miftah
Nomor Antrian           : EM42
Waktu Pemesanan         : Wed Jun 07 17:56:04 2023
==============  Terima Kasih  ===============

Struk berhasil diprint! Terima kasih!
```
