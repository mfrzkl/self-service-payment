#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <fstream>
#include <conio.h>
#include "qrcodegen.hpp"
using namespace std;

struct Item {
    string nama;
    double harga[3];
    string toping[3];
    string ukuranGelas[3];
};

struct db {
    string db_nama;
    double db_harga[3];
    string db_toping[3];
    string db_ukuranGelas[3];
};

struct Order {
    string nama;
    int nomorAntrian;
    time_t waktuPemesanan;
};

string generatePaymentCode() {
    stringstream ss;
    int randomNum = rand() % 900000 + 100000;
    ss << setw(6) << setfill('0') << randomNum;
    return ss.str();
}

void simpanStrukKeFile(const string& namaFile, const string& struk) {
    ofstream file(namaFile);
    if (file.is_open()) {
        file << struk;
        file.close();
        cout << "\nStruk berhasil diprint! Terima kasih!\n";
    } else {
        cout << "\nPembayaran Gagal\n" << endl;
    }
}

void createQRCode(const std::string& text, const std::string& filename) {
    const qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(text.c_str(), qrcodegen::QrCode::Ecc::MEDIUM);

    const int size = qr.getSize();
    const int scale = 4;  // Scale factor for the QR Code image

    std::string qrSvg;
    qrSvg += "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n";
    qrSvg += "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"" + std::to_string(size * scale) + "\" height=\"" + std::to_string(size * scale) + "\" viewBox=\"0 0 " + std::to_string(size) + " " + std::to_string(size) + "\">\n";
    qrSvg += "<rect width=\"" + std::to_string(size) + "\" height=\"" + std::to_string(size) + "\" style=\"fill:#ffffff\"/>\n";

    // Generate the QR Code SVG
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            const bool module = qr.getModule(x, y);
            qrSvg += "<rect x=\"" + std::to_string(x) + "\" y=\"" + std::to_string(y) + "\" width=\"1\" height=\"1\" style=\"fill:" + (module ? "#000000" : "#ffffff") + "\"/>\n";
        }
    }

    qrSvg += "</svg>\n";

    std::ofstream qrFile(filename);
    qrFile << qrSvg;
    qrFile.close();

    std::cout << "QR Code created and saved as " << filename << std::endl;
}

// void saveToPDF(const std::string& filename, const std::string& struk, const std::string& qrFilename) {
//     PDFGen pdf;

//     // Add the struk content to the PDF
//     pdf.addText(struk, 10, 10, 10, PDFGen::Color::BLACK);

//     // Add the QR Code image to the PDF
//     pdf.addImage(qrFilename, 10, 100, 100, 100);

//     // Save the PDF file
//     pdf.saveToFile(filename);

//     std::cout << "PDF file created and saved as " << filename << std::endl;
// }

int sequentialSearch(const Item arr[], int n, string key) {
    for (int i = 0; i < n; i++) {
        if (arr[i].nama == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    cout << "Self Service System on Coffee Shop\n\n";

    // const int db_coffee = 10;
    const int MAX_MENU = 10;
    // db dbmenu[db_coffee] 
    Item menu[MAX_MENU] = {
        {"Caramel Mocha", {49000.0, 52000.0, 55000.0}, {"Caramel", "Vanilla"}, {"Tall", "Grande", "Venti"}},
        {"Green Tea", {50000.0, 53000.0, 56000.0}, {"Vanilla", "Cream"}, {"Tall", "Grande", "Venti"}},
        {"Brewed Coffee", {48000.0, 51000.0, 54000.0}, {"Vanilla", "Caramel"}, {"Tall", "Grande", "Venti"}},
        {"Caramel Macchiato", {59000.0, 62000.0, 65000.0}, {"Caramel", "Chocolate"}, {"Tall", "Grande", "Venti"}},
        {"Java Chip Frappuccino", {58000.0, 61000.0, 64000.0}, {"Hazelnut", "Chocolate"}, {"Tall", "Grande", "Venti"}},
        {"Signature Chocolate", {53000.0, 56000.0, 59000.0}, {"Caramel", "Chocolate"}, {"Tall", "Grande", "Venti"}},
        {"Espresso", {50000.0, 53000.0, 56000.0}, {"Caramel", "Vanilla"}, {"Tall", "Grande", "Venti"}},
        {"Cappuccino", {55000.0, 58000.0, 61000.0}, {"Chocolate", "Hazelnut"}, {"Tall", "Grande", "Venti"}},
        {"Cafe Latte", {60000.0, 63000.0, 66000.0}, {"Caramel", "Vanilla", "Hazelnut"}, {"Tall", "Grande", "Venti"}},
        {"Mocha", {65000.0, 68000.0, 71000.0}, {"Chocolate", "Caramel"}, {"Tall", "Grande", "Venti"}}
        // Add other coffee menus here
    };
    
    const int db_coffee = 10;
    // const int MAX_MENU = 10;
    // Item menu[MAX_MENU] 
    db dbmenu[db_coffee] = {
        {"Caramel Mocha\t\t\t", {49000.0, 52000.0, 55000.0}, {"Caramel", "Vanilla"}, {"Tall", "Grande", "Venti"}},
        {"Green Tea\t\t\t\t", {50000.0, 53000.0, 56000.0}, {"Vanilla", "Cream"}, {"Tall", "Grande", "Venti"}},
        {"Brewed Coffee\t\t\t", {48000.0, 51000.0, 54000.0}, {"Vanilla", "Caramel"}, {"Tall", "Grande", "Venti"}},
        {"Caramel Macchiato\t\t\t", {59000.0, 62000.0, 65000.0}, {"Caramel", "Chocolate"}, {"Tall", "Grande", "Venti"}},
        {"Java Chip Frappuccino\t\t", {58000.0, 61000.0, 64000.0}, {"Hazelnut", "Chocolate"}, {"Tall", "Grande", "Venti"}},
        {"Signature Chocolate\t\t", {53000.0, 56000.0, 59000.0}, {"Caramel", "Chocolate"}, {"Tall", "Grande", "Venti"}},
        {"Espresso\t\t\t\t", {50000.0, 53000.0, 56000.0}, {"Caramel", "Vanilla"}, {"Tall", "Grande", "Venti"}},
        {"Cappuccino\t\t\t\t", {55000.0, 58000.0, 61000.0}, {"Chocolate", "Hazelnut"}, {"Tall", "Grande", "Venti"}},
        {"Cafe Latte\t\t\t\t", {60000.0, 63000.0, 66000.0}, {"Caramel", "Vanilla"}, {"Tall", "Grande", "Venti"}},
        {"Mocha\t\t\t\t", {65000.0, 68000.0, 71000.0}, {"Chocolate", "Caramel"}, {"Tall", "Grande", "Venti"}}
        // Add other coffee menus here
    };

    for (int i = 0; i < db_coffee - 1; i++) {
        for (int j = 0; j < db_coffee - i - 1; j++) {
            if (dbmenu[j].db_nama > dbmenu[j + 1].db_nama) {
                swap(dbmenu[j], dbmenu[j + 1]);
            }
        }
    }
    cout << "|\t\tMenu\t\t\t Tall(1)\tGrande(2)\t Venti(3)\t\n";
    cout << "----------------------------------------------------------------------------------\n";
    for (int i = 0; i < MAX_MENU; i++) {
        cout << "| " << i + 1 << ". " << dbmenu[i].db_nama;
        for (int j = 0; j < 3; j++) {
            cout << "Rp" << dbmenu[i].db_harga[j] << "\t\t";
        }
        cout << "\n";
    }
    cout << "\n";

    int fiturAwal;
    cout << "\n";
    cout << "1. Pesan\n";
    cout << "2. Cari Kopi\n";
    cout << "Pilihan (1/2)\t\t: ";
    cin >> fiturAwal;

    while (fiturAwal != 1 && fiturAwal != 2) {
        cout << "Pilihan tidak valid. Pilih (1/2): ";
        cin >> fiturAwal;
    }

    if (fiturAwal == 1) {
        const int MAX_PESANAN = 10;
        int pilihan[MAX_PESANAN];
        int jumlah[MAX_PESANAN];
        int jumlahPesanan = 0;
        double totalHargaToping = 0.0;
        char lanjutkan = 'y';

        do {
            int pilihanMenu;
            int jumlahPesananMenu;
            int pilihanToping = 0;

            cout << "\nPilih Kopi(1-10)\t: ";
            cin >> pilihanMenu;

            // Validasi nomor menu
            while (pilihanMenu < 1 || pilihanMenu > MAX_MENU) {
                cout << "Nomor menu tidak valid. Masukkan nomor menu yang ingin Anda pesan: ";
                cin >> pilihanMenu;
            }

            int index = pilihanMenu - 1;

            cout << "Ukuran gelas (1-3)\t: ";
            cin >> jumlahPesananMenu;

            // Menampilkan menu toping untuk menu kopi yang dipilih
            cout << "\nMenu Toping untuk " << menu[index].nama << "\n";
            cout << "No   Topping                 Harga\n";
            cout << "----------------------------------------\n";
            for (int i = 0; i < 2; i++) {
                cout << i + 1 << "    " << menu[index].toping[i] << "\t\tRp" << (i + 1) * 1000.0 << endl;
            }

            double toping1 = 1000.0, toping2 = 2000.0; 
            cout << "Pilih Topping\t\t: ";
            cin >> pilihanToping;

            while (pilihanToping < 1 || pilihanToping > 2) {
                cout << "Nomor topping tidak valid. Masukkan nomor topping yang ingin Anda pesan: ";
                cin >> pilihanToping;
            }

            if (pilihanToping == 1) {
                totalHargaToping = toping1 * jumlahPesananMenu;
            } else if (pilihanToping == 2) {
                totalHargaToping = toping2 * jumlahPesananMenu;
            }

            cout << "Masukkan jumlah pesanan\t: ";
            cin >> jumlahPesananMenu;

            // Validasi jumlah pesanan
            while (jumlahPesananMenu <= 0) {
                cout << "Jumlah pesanan tidak valid. Masukkan jumlah pesanan: ";
                cin >> jumlahPesananMenu;
            }

            // Simpan nomor menu dan jumlah pesanan ke dalam array
            pilihan[jumlahPesanan] = pilihanMenu - 1;
            jumlah[jumlahPesanan] = jumlahPesananMenu;

            jumlahPesanan++;

            cout << "Apakah Anda ingin menambah pesanan? (Y/n): ";
            cin >> lanjutkan;
            } while (lanjutkan == 'y' || lanjutkan == 'Y');

            cout << "\nPesanan Anda:\n";
            cout << "No\t\t\t\t Jumlah     Total Harga\n";
            cout << "-----------------------------------------------------------\n";
            double totalHarga = 0.0;
            int nomorMenu, jumlahPesananMenu;
            for (int i = 0; i < jumlahPesanan; i++) {
                nomorMenu = pilihan[i];
                jumlahPesananMenu = jumlah[i];

                cout << menu[nomorMenu].nama << setw(25) << jumlahPesananMenu << setw(10) <<"Rp" << menu[nomorMenu].harga[0] * jumlahPesananMenu << ",-" << endl;

                totalHarga += totalHargaToping + menu[nomorMenu].harga[0] * jumlahPesananMenu;
                cout << "(" << menu[nomorMenu].ukuranGelas[jumlahPesananMenu - 1] << ")" << "\n";
                // totalHarga += (menu[nomorMenu].harga[jumlahPesananMenu - 1] + totalHargaToping) * jumlahPesananMenu;
            }
            cout << "-----------------------------------------------------------\n";
            cout << "                              Total Harga\t: Rp" << totalHarga << ",-" << endl;

            double pajak = totalHarga * 0.05;
            double totalHargaPajak = totalHarga + pajak;
            cout << "                              Pajak (5%)\t: Rp" << pajak << ",-" << endl;
            cout << "                       Total Harga + Pajak\t: Rp" << totalHargaPajak << ",-" << endl;
            
            char metodePembayaran;
            cout << "\nMetode Pembayaran:\n";
            cout << "1. QRIS\n";
            cout << "Pilih metode pembayaran: ";
            cin >> metodePembayaran;

            while (metodePembayaran != '1') {
                cout << "Pilihan tidak valid. Pilih metode pembayaran: ";
                cin >> metodePembayaran;
            }

            Order order;
            cout << "\nMasukkan nama Anda: ";
            cin.ignore();
            getline(cin, order.nama);

            order.nomorAntrian = rand() % 100 + 1;

            time(&order.waktuPemesanan);

            cout << "Terima kasih, " << order.nama << ". Pesanan Anda sedang diproses.\n";
            cout << "Nomor Antrian Anda: " << order.nomorAntrian << endl;
            cout << "Waktu Pemesanan: " << ctime(&order.waktuPemesanan);

            string kodePembayaran = generatePaymentCode();
            cout << "Kode Pembayaran: " << kodePembayaran << endl;

            cout << "\n============= Struk Pembayaran ==============\n";
            for (int i = 0; i < jumlahPesanan; i++) {
                int nomorMenu = pilihan[i];
                int jumlahPesananMenu = jumlah[i];

                cout << menu[nomorMenu].nama << "(" << menu[nomorMenu].ukuranGelas[jumlahPesananMenu - 1] << ")" << setw(15)
                    << jumlahPesananMenu << " x Rp" << menu[nomorMenu].harga[0] << "\n";
                cout << "  -toping\n";
            }
            cout << "=============================================\n";
            cout << "Total Pembayaran" << setw(20) << "Rp" << totalHarga << ",-\n";
            cout << "Pajak (5%)" << setw(26) << "Rp" << pajak << ",-\n\n";
            cout << "\nTotal" << setw(31) << "Rp" << totalHargaPajak << ",-\n";
            cout << "=============================================\n";
            cout << "Metode Pembayaran\t: " << (metodePembayaran == '1' ? "Tunai" : (metodePembayaran == '2' ? "Debit" : "QRIS")) << "\n";
            cout << "Nama Pemesan\t\t: " << order.nama << "\n";
            cout << "Nomor Antrian\t\t: EM" << order.nomorAntrian << "\n";
            cout << "Waktu Pemesanan\t\t: " << ctime(&order.waktuPemesanan);
            cout << "==============  Terima Kasih  ==============\n";

            string struk;
            struk += "\n============= Struk Pembayaran ==============\n";
            for (int i = 0; i < jumlahPesanan; i++) {
                int nomorMenu = pilihan[i];
                int jumlahPesananMenu = jumlah[i];

                struk += menu[nomorMenu].nama + "(" + menu[nomorMenu].ukuranGelas[jumlahPesananMenu - 1] + ")" + "\t\t\t"
                    + to_string(static_cast<int>(jumlahPesananMenu)) + " x Rp" + to_string(static_cast<int>(menu[nomorMenu].harga[0])) + "\n";
                struk += "  -toping\n";
            }
            struk += "=============================================\n";
            struk += "Total Pembayaran          Rp" + to_string(static_cast<int>(totalHarga)) + ",-\n";
            struk += "Pajak (5%)                Rp" + to_string(static_cast<int>(pajak)) + ",-\n\n";
            struk += "\nTotal                   Rp" + to_string(static_cast<int>(totalHargaPajak)) + ",-\n";
            struk += "=============================================\n";
            struk += "Metode Pembayaran\t: " + string(metodePembayaran == '1' ? "Tunai" : (metodePembayaran == '2' ? "Debit" : "QRIS")) + "\n";
            struk += "Nama Pemesan\t\t: " + order.nama + "\n";
            struk += "Nomor Antrian\t\t: EM" + to_string(order.nomorAntrian) + "\n";
            struk += "Waktu Pemesanan\t\t: " + string(ctime(&order.waktuPemesanan));
            struk += "==============  Terima Kasih  ==============\n";

            string namaFile = "PAYMENT_SUCCESS_" + kodePembayaran + ".txt";
            string qrFilename = "QR_CODE_" + kodePembayaran + ".svg";
            simpanStrukKeFile(namaFile, struk);
            createQRCode(struk, qrFilename);

            
        } else if (fiturAwal == 2) {
        string namaKopi;
        cout << "Masukkan nama kopi yang ingin Anda cari: ";
        cin.ignore();
        getline(cin, namaKopi);

        // Mencari menu berdasarkan nama menggunakan sequential search
        int searchIndex = sequentialSearch(menu, MAX_MENU, namaKopi);
        if (searchIndex != -1) {
            cout << "\nMenu " << namaKopi << " ditemukan pada indeks ke-" << searchIndex + 1 << endl;
            cout << "Harga (Tall): " << menu[searchIndex].harga[0] << endl;
            cout << "Harga (Grande): " << menu[searchIndex].harga[1] << endl;
            cout << "Harga (Venti): " << menu[searchIndex].harga[2] << endl;
            cout << "Toping: " << menu[searchIndex].toping[0] << ", " << menu[searchIndex].toping[1] << endl;
            cout << "Ukuran Gelas: " << menu[searchIndex].ukuranGelas[0] << ", " << menu[searchIndex].ukuranGelas[1] << ", " << menu[searchIndex].ukuranGelas[2] << endl;
        } else {
            cout << "\nKopi " << namaKopi << " tidak ditemukan" << endl;
        }
    }
    cout << "Tekan apa saja untuk keluar";
    getch();
    return 0;
}
