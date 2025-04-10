#include <iostream>
#include <string>
#include <limits> // Untuk numeric_limits

#define MAX_BARANG 100
#define KOLOM_BARANG 2 // Kolom untuk nama dan stok

using namespace std;

struct Barang {
    string data[KOLOM_BARANG];
};

// Fungsi untuk menampilkan tabel inventaris
int tampilkanInventaris(Barang barang[], int banyak) {
    if (banyak == 0) {
        cout << "Belum ada barang" << endl;
        return 0; // Mengembalikan 0 jika tidak ada barang
    }

    cout << "No. | Nama Barang           | Stok" << endl;
    cout << "-----------------------------------" << endl;

    for (int i = 0; i < banyak; i++) {
        cout << i + 1 << ".  | ";
        cout << barang[i].data[0];
        for (int j = barang[i].data[0].length(); j < 22; j++) {
            cout << " ";
        }
        cout << "| ";
        cout << barang[i].data[1] << endl;
    }
    return 1; // Mengembalikan 1 jika barang ditampilkan
}

int main() {
    // Informasi login
    string nama_terdaftar = "WidyaAyuAnggraini";
    string nim_terdaftar = "2409106011";

    cout << "Selamat Datang di Manajemen Inventaris Toko Bangunan" << endl;

    // Proses Login
    int percobaan_login = 0;
    bool login_berhasil = false;

    while (percobaan_login < 3 && !login_berhasil) {
        string nama_input, nim_input;

        cout << "\n===== Login =====" << endl;
        cout << "Masukkan Nama: ";
        cin >> nama_input;
        cout << "Masukkan NIM: ";
        cin >> nim_input;

        if (nama_input == nama_terdaftar && nim_input == nim_terdaftar) {
            login_berhasil = true;
            cout << "Login Berhasil! Selamat datang, " << nama_terdaftar << "!" << endl;
        } else {
            percobaan_login++;
            int sisa_percobaan = 3 - percobaan_login;
            cout << "Login Gagal! Sisa percobaan: " << sisa_percobaan << endl;

            if (percobaan_login == 3) {
                cout << "Anda telah melebihi batas percobaan login." << endl;
                return 0;
            }
        }
    }

    if (!login_berhasil) {
        cout << "Program berakhir karena gagal login." << endl;
        return 0;
    }

    int banyak = 0; // Jumlah elemen saat ini
    Barang barang[MAX_BARANG]; // Array 2 dimensi
    int pilihan, index;

    do {
        system("cls");
        cout << "Menu Manajemen Inventaris Toko Bangunan" << endl;
        cout << "1. Tampilkan Inventaris Barang" << endl;
        cout << "2. Tambah Barang" << endl;
        cout << "3. Update Barang" << endl;
        cout << "4. Hapus Barang" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";

        // Validasi input pilihan
        if (!(cin >> pilihan)) {
            cout << "Input tidak valid. Masukkan angka." << endl;
            cin.clear();
            cin.ignore(); // Bersihkan buffer input
            pilihan = 0; // Set pilihan ke nilai default
            continue; // Kembali ke awal loop
        }

        cin.ignore(); // Membersihkan newline

        switch (pilihan) {
            case 1:
                tampilkanInventaris(barang, banyak);
                break;

            case 2:
                if (banyak < MAX_BARANG) {
                    cout << "Masukkan nama barang: ";
                    getline(cin, barang[banyak].data[0]);
                    cout << "Masukkan stok barang: ";
                    getline(cin, barang[banyak].data[1]);
                    banyak++;
                    cout << "Barang berhasil ditambahkan" << endl;
                } else {
                    cout << "Kapasitas penuh! Tidak bisa menambah barang lagi." << endl;
                }
                break;

            case 3:
                if (banyak == 0) {
                    cout << "Belum ada barang untuk diubah." << endl;
                } else {
                    tampilkanInventaris(barang, banyak);
                    cout << "Masukkan nomor barang yang akan diubah: ";
                    cin >> index;
                    cin.ignore();

                    if (index > 0 && index <= banyak) {
                        cout << "Masukkan nama barang baru: ";
                        getline(cin, barang[index - 1].data[0]);
                        cout << "Masukkan stok barang baru: ";
                        getline(cin, barang[index - 1].data[1]);
                        cout << "Barang berhasil diubah" << endl;
                    } else {
                        cout << "Nomor barang tidak valid" << endl;
                    }
                }
                break;

            case 4:
                if (banyak == 0) {
                    cout << "Belum ada barang untuk dihapus." << endl;
                } else {
                    tampilkanInventaris(barang, banyak);
                    cout << "Masukkan nomor barang yang akan dihapus: ";
                    cin >> index;

                    if (index > 0 && index <= banyak) {
                        for (int i = index - 1; i < banyak - 1; i++) {
                            barang[i] = barang[i + 1];
                        }
                        banyak--;
                        cout << "Barang berhasil dihapus" << endl;
                    } else {
                        cout << "Nomor barang tidak valid" << endl;
                    }
                }
                break;

            case 5:
                cout << "Program selesai" << endl;
                break;

            default:
                cout << "Pilihan tidak valid" << endl;
                break;
        }
        cout << "\nTekan Enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
    } while (pilihan != 5);

    return 0;
}