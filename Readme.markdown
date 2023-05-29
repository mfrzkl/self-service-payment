Coffee Shop Self Service Payment
================================
1. Miftah Rizky Aulia               (2210511022)
2. Muhammad Dihya Al Qalby          (2210511030)
3. Sufyan Al Afi
4. Nada Nabila
5. Firda Fahria
6. Samuel Alexande Mozes Tambunan

Introduction
------------

Project Coffee Shop Self Service Payment dibuat untuk memenuhi tugas akhir mata kuliah praktikum algoritma dan pemrograman 2

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
 \___________________/   Selamat datang di Coffee Shop
 
1. Brewed Coffe - Rp48000.00
2. Cafe Latte - Rp60000.00
3. Cappuccino - Rp55000.00
4. Caramel Macchiato - Rp59000.00
5. Caramel Mocha - Rp49000.00
6. Espresso - Rp50000.00
7. Green Tea - Rp50000.00
8. Java Chip Frappucino - Rp58000.00
9. Mocha - Rp65000.00
10. Signature Chocolate - Rp53000.00

1. Pesan
2. Cari Kopi
Pilih (1/2): 
```
