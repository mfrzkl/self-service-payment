#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
#include "qrcodegen.hpp"
using namespace std;

struct Item {
    string nama;
    double harga;
    vector<string> toping;
    vector<string> ukuranGelas;
};

struct Order {
    string nama;
    int nomorAntrian;
    time_t waktuPemesanan;
};

struct Node {
    Order data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void insert(Order data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << "Nama Pemesan: " << current->data.nama << endl;
            cout << "Nomor Antrian: " << current->data.nomorAntrian << endl;
            cout << "Waktu Pemesanan: " << asctime(localtime(&current->data.waktuPemesanan)) << endl;
            cout << "-------------------------" << endl;
            current = current->next;
        }
    }
};

string generatePaymentCode() {
    stringstream ss;
    // Generate a random 6-digit number
    int randomNum = rand() % 900000 + 1000000;
    // Convert the number to string and format it with leading zeros
    ss << setw(6) << setfill('0') << randomNum;
    return ss.str();
}

int binarySearch(const Item arr[], int left, int right, string key) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid].nama == key) {
            return mid;
        }

        if (arr[mid].nama > key) {
            return binarySearch(arr, left, mid - 1, key);
        }

        return binarySearch(arr, mid + 1, right, key);
    }

    return -1;
}

int main() {
    // Menampilkan pesan selamat datang
    cout << "Selamat datang di Coffee Shop\n";

    // Menginisialisasi menu
    const int MAX_MENU = 10;  // Jumlah maksimum menu kopi
    Item menu[MAX_MENU] = {
        {"Caramel Mocha", 49000.0, {"Caramel", "Vanilla"}, {"Tall", "Grande", "Venti"}},
        {"Green Tea", 50000.0, {"Vanilla", "Cream"}, {"Tall", "Grande", "Venti"}},
        {"Brewed Coffe", 48000.0, {"Vanilla", "Caramel"}, {"Tall", "Grande", "Venti"}},
        {"Caramel Macchiato", 59000.0, {"Caramel", "Chocolate"}, {"Tall", "Grande", "Venti"}},
        {"Java Chip Frappucino", 58000.0, {"Hazelnut", "Chocolate"}, {"Tall", "Grande", "Venti"}},
        {"Signature Chocolate", 53000.0, {"Caramel", "Chocolate"}, {"Tall", "Grande", "Venti"}},
        {"Espresso", 50000.0, {"Caramel", "Vanilla",}, {"Tall", "Grande", "Venti"}},
        {"Cappuccino", 55000.0, {"Chocolate", "Hazelnut"}, {"Tall", "Grande", "Venti"}},
        {"Cafe Latte", 60000.0, {"Caramel", "Vanilla", "Hazelnut"}, {"Tall", "Grande", "Venti"}},
        {"Mocha", 65000.0, {"Chocolate", "Caramel"}, {"Tall", "Grande", "Venti"}}
        // Tambahkan menu kopi lainnya di sini
    };

    // Sorting menu menggunakan Bubble Sort
    for (int i = 0; i < MAX_MENU - 1; i++) {
        for (int j = 0; j < MAX_MENU - i - 1; j++) {
            if (menu[j].nama > menu[j + 1].nama) {
                swap(menu[j], menu[j + 1]);
            }
        }
    }

    // Menampilkan menu
    cout << "Menu:\n";
    for (int i = 0; i < MAX_MENU; i++) {
        cout << i + 1 << ". " << menu[i].nama << " - Rp" << fixed << setprecision(2) << menu[i].harga << endl;
    }

    // Memilih fitur awal (Menu / Cari Kopi)
    int fiturAwal;
    cout << "\nFitur Awal:\n";
    cout << "1. Menu\n";
    cout << "2. Cari Kopi\n";
    cout << "Pilihan (1/2): ";
    cin >> fiturAwal;

    while (fiturAwal != 1 && fiturAwal != 2) {
        cout << "Pilihan tidak valid. Pilih (1/2): ";
        cin >> fiturAwal;
    }

    if (fiturAwal == 1) {
        // Menginisialisasi pilihan dan jumlah pesanan
        const int MAX_PESANAN = 10;  // Jumlah maksimum pesanan
        int pilihan[MAX_PESANAN];
        int jumlah[MAX_PESANAN];

        // Meminta pengguna memasukkan pesanan
        char lanjutkan;
        int jumlahPesanan = 0;
        do {
            int pilihanMenu;

            cout << "Masukkan nomor menu yang dipilih: ";
            cin >> pilihanMenu;

            while (pilihanMenu <= 0 || pilihanMenu > MAX_MENU) {
                cout << "Pilihan tidak valid. Masukkan nomor menu yang dipilih: ";
                cin >> pilihanMenu;
            }

           // Menampilkan menu untuk memilih ukuran gelas
             int index = pilihanMenu - 1;
            cout << "\nPilih Ukuran Gelas Untuk " << menu[index].nama << ":\n";
            for (int i = 0; i < menu[index].ukuranGelas.size(); i++) {
                cout << i + 1 << ". " << menu[index].ukuranGelas[i] << "- Rp" << fixed << setprecision(2) << (i + 1) * 1000.0 << endl;
            }

            cout << "Masukkan Ukuran Gelas yang Anda Pilih: ";
            cin >> jumlah[jumlahPesanan];

            // Menampilkan menu toping untuk menu kopi yang dipilih
            cout << "\nMenu Toping untuk " << menu[index].nama << ":\n";
            for (int i = 0; i < menu[index].toping.size(); i++) {
                cout << i + 1 << ". " << menu[index].toping[i] << " - Rp" << fixed << setprecision(2) << (i + 1) * 1000.0 << endl;
            }
            cout << "Masukkan Topping yang Anda Inginkan: ";
            cin >> jumlah[jumlahPesanan];

            pilihan[jumlahPesanan] = pilihanMenu;
            jumlahPesanan++;

            cout << "Apakah Anda ingin menambah pesanan lain? (Y/N): ";
            cin >> lanjutkan;
        } while ((lanjutkan == 'Y' || lanjutkan == 'y') && jumlahPesanan < MAX_PESANAN);

        // Menghitung total pembayaran sebelum pajak
        double totalPembayaran = 0.0;
        for (int i = 0; i < jumlahPesanan; i++) {
            int index = pilihan[i] - 1;
            totalPembayaran += menu[index].harga * jumlah[i];
        }

        // Menghitung pajak
        double pajak = totalPembayaran * 0.05;

        // Menghitung total pembayaran setelah pajak
        double totalPembayaranSetelahPajak = totalPembayaran + pajak;

        // Memilih metode pembayaran (tunai atau debit)
        char metodePembayaran;
        cout << "\nMetode Pembayaran:\n";
        cout << "1. Tunai\n";
        cout << "2. Debit\n";
        cout << "Pilih metode pembayaran (1/2): ";
        cin >> metodePembayaran;

        while (metodePembayaran != '1' && metodePembayaran != '2' && metodePembayaran != '3') {
            cout << "Pilihan tidak valid. Pilih metode pembayaran (1/2): ";
            cin >> metodePembayaran;
        }
        
        if (metodePembayaran == '3') {
        // Generate payment code
        string paymentCode = generatePaymentCode();
        cout << "Kode Pemesanan: " << paymentCode << endl;

        // Generate QR code from payment code
        string qrText = "QRIS:" + paymentCode;

        // Menampilkan QR code
        cout << "\nQR Code Pembayaran:\n";
        displayQRCode(qrText);
    	}

        // Menginput nama pemesan
        string namaPemesan;
        cout << "Masukkan nama pemesan: ";
        cin.ignore();
        getline(cin, namaPemesan);

        // Membuat nomor antrian dengan menggunakan queue
        queue<Order> antrian;
        time_t now = time(0);
        for (int i = 1; i <= jumlahPesanan; i++) {
            Order pesanan;
            pesanan.nama = namaPemesan;
            pesanan.nomorAntrian = i;
            pesanan.waktuPemesanan = now;
            antrian.push(pesanan);
        }

        // Menampilkan struk pembayaran
        cout << "\n===== Struk Pembayaran =====\n";
        for (int i = 0; i < jumlahPesanan; i++) {
            int index = pilihan[i] - 1;
            cout << setw(15) << left << menu[index].nama << setw(10) << right << jumlah[i] << " x Rp" << fixed << setprecision(2) << menu[index].harga << endl;
        }
        cout << "============================\n";
        cout << setw(15) << left << "Total Pembayaran:" << setw(10) << right << "Rp" << fixed << setprecision(2) << totalPembayaran << endl;
        cout << setw(15) << left << "Pajak (5%):" << setw(10) << right << "Rp" << fixed << setprecision(2) << pajak << endl;
        cout << setw(15) << left << "Total Pembayaran Setelah Pajak:" << setw(10) << right << "Rp" << fixed << setprecision(2) << totalPembayaranSetelahPajak << endl;
        cout << "============================\n";
        cout << "Metode Pembayaran: " << (metodePembayaran == '1' ? "Tunai" : "Debit") << endl;
        cout << "Nama Pemesan: " << namaPemesan << endl;
        cout << "Nomor Antrian: " << antrian.front().nomorAntrian << endl;
        cout << "Waktu Pemesanan: " << asctime(localtime(&antrian.front().waktuPemesanan)) << endl;
        
        // Generate payment code
        string paymentCode = generatePaymentCode();
        cout << "kode pemesanan: " << paymentCode << endl;
        
        // Menampilkan antrian pemesanan
        LinkedList list;
        while (!antrian.empty()) {
            list.insert(antrian.front());
            antrian.pop();
        }
        cout << "\nAntrian Pemesanan:\n";
        list.display();
    } else if (fiturAwal == 2) {
        // Mencari kopi berdasarkan nama
        string cariKopi;
        cout << "Masukkan nama kopi yang ingin dicari: ";
        cin.ignore();
        getline(cin, cariKopi);

        int index = binarySearch(menu, 0, MAX_MENU - 1, cariKopi);
        if (index != -1) {
            cout << "Kopi ditemukan!\n";
            cout << "Nama: " << menu[index].nama << endl;
            cout << "Harga: Rp" << fixed << setprecision(2) << menu[index].harga << endl;
            cout << "Toping:\n";
            for (int i = 0; i < menu[index].toping.size(); i++) {
                cout << i + 1 << ". " << menu[index].toping[i] << endl;
            }
        } else {
            cout << "Kopi tidak ditemukan.\n";
        }
    }

    return 0;
}

