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

Project Implementasi Sistem Self Service Payment Terhadap Coffee Shop dibuat untuk memenuhi tugas akhir mata kuliah praktikum algoritma dan pemrograman 2

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
     (  )   (   )  )
      ) (   )  (  (
      ( )  (    ) )
      _____________
     <_____________> ___
     |             |/ _ \
     |               | | |
     |               |_| |
  ___|             |\___/
 /    \___________/    \
 \___________________/   
 Selamat datang di Coffee Shop
_________________________________________________________
|           Menu               Tall    Grande     Venti  |
|________________________________________________________|
| 1. Brewed Coffe               48        51        54   |
| 2. Cafe Latte                 54        57        60   |    
| 3. Cappuccino                 55        58        61   |
| 4. Caramel Macchiato          56        59        62   |  
| 5. Caramel Mocha              49        52        55   |
| 6. Espresso                   50        53        56   |
| 7. Green Tea                  50        53        56   |
| 8. Java Chip Frappucino       50        53        56   |
| 9. Mocha                      65        68        71   |
| 10. Signature Chocolate       53        56        59   |
|________________________________________________________|
1. Pesan
2. Cari Kopi
Pilih (1/2): 
```
```
========== Struk Pembayaran ==============
Brewed Coffe            1 x Rp48,000
Cafe Latte              1 x Rp57,000
==========================================
Total Pembayaran:        Rp48,000
Pajak (5%):              Rp2,400


Total                    Rp50,400
==========================================
Metode Pembayaran: QRIS
Nama Pemesan: Miftah
Nomor Antrian: M03
Waktu Pemesanan: Mon May 29 12:40:05 2023
==========================================
