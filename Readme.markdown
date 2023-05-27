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

```c++
#include <string>
#include <vector>
#include "QrCode.hpp"
using namespace qrcodegen;

// Simple operation
QrCode qr0 = QrCode::encodeText("Hello, world!", QrCode::Ecc::MEDIUM);
std::string svg = toSvgString(qr0, 4);  // See QrCodeGeneratorDemo

// Manual operation
std::vector<QrSegment> segs =
    QrSegment::makeSegments("3141592653589793238462643383");
QrCode qr1 = QrCode::encodeSegments(
    segs, QrCode::Ecc::HIGH, 5, 5, 2, false);
for (int y = 0; y < qr1.getSize(); y++) {
    for (int x = 0; x < qr1.getSize(); x++) {
        (... paint qr1.getModule(x, y) ...)
    }
}
```
