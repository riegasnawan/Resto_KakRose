#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Pesanan {
public:
    string nama;
    int jumlahAyam;
    int jumlahNasi;
    int jumlahTeh;

    Pesanan(string n, int ayam = 0, int nasi = 0, int teh = 0) {
        nama = n;
        jumlahAyam = ayam;
        jumlahNasi = nasi;
        jumlahTeh = teh;
    }

    float hitungTotalHarga() {
        return (jumlahAyam * 15000) + (jumlahNasi * 5000) + (jumlahTeh * 3000);
    }

    void tampilkanPesanan() {
        cout << "Nama: " << nama << endl;
        if (jumlahAyam > 0)
            cout << "Ayam: " << jumlahAyam << " x 15000 = " << jumlahAyam * 15000 << endl;
        if (jumlahNasi > 0)
            cout << "Nasi: " << jumlahNasi << " x 5000 = " << jumlahNasi * 5000 << endl;
        if (jumlahTeh > 0)
            cout << "Teh: " << jumlahTeh << " x 3000 = " << jumlahTeh * 3000 << endl;
        cout << "Total Harga: " << hitungTotalHarga() << endl;
    }
};

vector<Pesanan> daftarPesanan;

void tampilkanMenu() {
    cout << "Menu:\n";
    cout << "1. Ayam: 15000\n";
    cout << "2. Nasi: 5000\n";
    cout << "3. Teh: 3000\n";
    cout << "4. Selesai\n";
    cout << endl;
}

void tambahPesanan() {
    string nama;
    int ayam = 0, nasi = 0, teh = 0;
    int pilihan;

    cout << "Masukkan nama: ";
    cin >> nama;

    do {
        tampilkanMenu();
        cout << "Pilih menu yang ingin dipesan (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Masukkan jumlah ayam: ";
            cin >> ayam;
            break;
        case 2:
            cout << "Masukkan jumlah nasi: ";
            cin >> nasi;
            break;
        case 3:
            cout << "Masukkan jumlah teh: ";
            cin >> teh;
            break;
        case 4:
            cout << "Selesai memesan.\n";
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 4);

    Pesanan pesananBaru(nama, ayam, nasi, teh);
    daftarPesanan.push_back(pesananBaru);

    cout << "Pesanan telah ditambahkan!\n";
}

void tampilkanPesananBerdasarkanNama() {
    string nama;
    cout << "Masukkan nama yang ingin dicari: ";
    cin >> nama;

    bool ditemukan = false;
    for (int i = 0; i < daftarPesanan.size(); ++i) {
        if (daftarPesanan[i].nama == nama) {
            daftarPesanan[i].tampilkanPesanan();
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Pesanan dengan nama " << nama << " tidak ditemukan.\n";
    }
}

int main() {
    int pilihan;

    do {
        cout << "\nMenu Utama:\n";
        cout << "1. Tambah Pesanan\n";
        cout << "2. Tampilkan Pesanan Berdasarkan Nama\n";
        cout << "3. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            tambahPesanan();
            break;
        case 2:
            tampilkanPesananBerdasarkanNama();
            break;
        case 3:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 3);

    return 0;
}

