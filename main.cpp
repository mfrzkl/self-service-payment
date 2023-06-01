#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <fstream>
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

int sequentialSearch(const db arr[], int n, string key) {
    for (int i = 0; i < n; i++) {
        if (arr[i].db_nama == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    cout << "Self Service System on Coffee Shop\n\n";

    const int db_coffee = 10;
    db dbmenu[db_coffee] = {
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
    
    const int MAX_MENU = 10;
    Item menu[MAX_MENU] = {
        {"Caramel Mocha\t\t\t\t", {49000.0, 52000.0, 55000.0}, {"Caramel", "Vanilla"}, {"Tall", "Grande", "Venti"}},
        {"Green Tea\t\t\t\t\t", {50000.0, 53000.0, 56000.0}, {"Vanilla", "Cream"}, {"Tall", "Grande", "Venti"}},
        {"Brewed Coffee\t\t\t\t", {48000.0, 51000.0, 54000.0}, {"Vanilla", "Caramel"}, {"Tall", "Grande", "Venti"}},
        {"Caramel Macchiato\t\t\t", {59000.0, 62000.0, 65000.0}, {"Caramel", "Chocolate"}, {"Tall", "Grande", "Venti"}},
        {"Java Chip Frappuccino\t\t", {58000.0, 61000.0, 64000.0}, {"Hazelnut", "Chocolate"}, {"Tall", "Grande", "Venti"}},
        {"Signature Chocolate\t\t", {53000.0, 56000.0, 59000.0}, {"Caramel", "Chocolate"}, {"Tall", "Grande", "Venti"}},
        {"Espresso\t\t\t\t\t", {50000.0, 53000.0, 56000.0}, {"Caramel", "Vanilla"}, {"Tall", "Grande", "Venti"}},
        {"Cappuccino\t\t\t\t\t", {55000.0, 58000.0, 61000.0}, {"Chocolate", "Hazelnut"}, {"Tall", "Grande", "Venti"}},
        {"Cafe Latte\t\t\t\t\t", {60000.0, 63000.0, 66000.0}, {"Caramel", "Vanilla"}, {"Tall", "Grande", "Venti"}},
        {"Mocha\t\t\t\t\t\t", {65000.0, 68000.0, 71000.0}, {"Chocolate", "Caramel"}, {"Tall", "Grande", "Venti"}}
        // Add other coffee menus here
    };

    for (int i = 0; i < MAX_MENU - 1; i++) {
        for (int j = 0; j < MAX_MENU - i - 1; j++) {
            if (menu[j].nama > menu[j + 1].nama) {
                swap(menu[j], menu[j + 1]);
            }
        }
    }
    cout << "|\t\tMenu\t\t\t\t\t Tall\t\tGrande\t\t Venti\t\t\n";
    cout << "--------------------------------------------------------------------\n";
    for (int i = 0; i < MAX_MENU; i++) {
        cout << "| " << i + 1 << ". " << menu[i].nama;
        for (int j = 0; j < 3; j++) {
            cout << "Rp" << menu[i].harga[j] << "\t\t";
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
        char lanjutkan = 'y';

        do {
            int pilihanMenu;
            int jumlahPesananMenu;

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
                cout << i + 1 << "    " << menu[index].toping[i] << "\t\t\t\tRp" << (i + 1) * 1000.0 << endl;
            }
            cout << "Pilih Topping\t\t\t: ";
            cin >> jumlahPesananMenu;

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
        cout << "No\t\t\t\t\t\t\t\t Jumlah     Total Harga\n";
        cout << "-----------------------------------------------------------\n";
        double totalHarga = 0.0;
        for (int i = 0; i < jumlahPesanan; i++) {
            int nomorMenu = pilihan[i];
            int jumlahPesananMenu = jumlah[i];

            cout << i + 1 << "    " << menu[nomorMenu].nama << "    " << jumlahPesananMenu << "        Rp" << menu[nomorMenu].harga[0] * jumlahPesananMenu << ",-" << endl;

            totalHarga += menu[nomorMenu].harga[0] * jumlahPesananMenu;
        }
        cout << "-----------------------------------------------------------\n";
        cout << "                              Total Harga\t: Rp" << totalHarga << ",-" << endl;

        double pajak = totalHarga * 0.05;
        double totalHargaPajak = totalHarga + pajak;
        cout << "                              Pajak (5%)\t: Rp" << pajak << ",-" << endl;
        cout << "                       Total Harga + Pajak\t: Rp" << totalHargaPajak << ",-" << endl;
        
        char metodePembayaran;
        cout << "\nMetode Pembayaran:\n";
        cout << "1. Tunai\n";
        cout << "2. Debit\n";
        cout << "3. QRIS\n";
        cout << "Pilih metode pembayaran (1/2/3): ";
        cin >> metodePembayaran;

        while (metodePembayaran != '1' && metodePembayaran != '2' && metodePembayaran!= '3') {
            cout << "Pilihan tidak valid. Pilih metode pembayaran (1/2): ";
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

            cout << menu[nomorMenu].nama << jumlahPesananMenu << " x Rp" << menu[nomorMenu].harga[0] << endl;
        }
        cout << "=============================================\n";
        cout << "Total Pembayaran\t\t\t: Rp" << totalHarga << ",-" <<endl;
        cout << "Pajak (5%)\t\t\t\t\t: Rp" << pajak << ",-" << endl;
        cout << "\nTotal\t\t\t\t\t\t: Rp" << totalHargaPajak << ",-" << endl;
        cout << "=============================================\n";
        cout << "Metode Pembayaran\t: " << (metodePembayaran == '1' ? "Tunai" : (metodePembayaran == '2' ? "Debit" : "QRIS")) << endl;
        cout << "Nama Pemesan\t\t: " << order.nama << endl;
        cout << "Nomor Antrian\t\t: EM" << order.nomorAntrian << endl;
        cout << "Waktu Pemesanan\t\t: " << ctime(&order.waktuPemesanan);
        cout << "=============================================\n";
        
    } else if (fiturAwal == 2) {
        string namaKopi;
        cout << "Masukkan nama kopi yang ingin Anda cari: ";
        cin.ignore();
        getline(cin, namaKopi);

        // Mencari menu berdasarkan nama menggunakan sequential search
        int searchIndex = sequentialSearch(dbmenu, db_coffee, namaKopi);
        if (searchIndex != -1) {
            cout << "\nMenu " << namaKopi << " ditemukan pada indeks ke-" << searchIndex + 1 << endl;
            cout << "Harga (Tall): " << dbmenu[searchIndex].db_harga[0] << endl;
            cout << "Harga (Grande): " << dbmenu[searchIndex].db_harga[1] << endl;
            cout << "Harga (Venti): " << dbmenu[searchIndex].db_harga[2] << endl;
            cout << "Toping: " << dbmenu[searchIndex].db_toping[0] << ", " << dbmenu[searchIndex].db_toping[1] << endl;
            cout << "Ukuran Gelas: " << dbmenu[searchIndex].db_ukuranGelas[0] << ", " << dbmenu[searchIndex].db_ukuranGelas[1] << ", " << dbmenu[searchIndex].db_ukuranGelas[2] << endl;
        } else {
            cout << "\nKopi " << namaKopi << " tidak ditemukan" << endl;
        }
    }

    return 0;
}
