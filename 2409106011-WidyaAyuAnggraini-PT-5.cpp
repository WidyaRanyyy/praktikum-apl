#include <iostream>
#include <string>

#define MAX_PENGGUNA 100
#define MAX_BARANG 100

using namespace std;

struct Akun {
    string nama;
    string nim;
};

struct Barang {
    string nama;
    int stok;
};

struct Pengguna {
    Akun akun;
    Barang inventaris[MAX_BARANG];
    int jumlahBarang;
};

// Fungsi tambahan pointer
void tampilkanTotalBarang(const Pengguna &pengguna) {
    cout << "Total barang yang dimiliki: " << pengguna.jumlahBarang << endl;
}

void tambahStok(Barang *barang, int tambahan) {
    barang->stok += tambahan;
}

void clearScreen() {
    system("cls");
}

void registrasi(Pengguna pengguna[], int &jumlahPengguna) {
    if (jumlahPengguna < MAX_PENGGUNA) {
        bool akun_sudah_ada = false;
        string nama_input, nim_input;
        do {
            cout << "Masukkan Nama Yang Belum Pernah Digunakan: ";
            getline(cin, nama_input);
            cout << "Masukkan NIM Yang Belum Pernah Digunakan: ";
            getline(cin, nim_input);

            akun_sudah_ada = false;
            for (int i = 0; i < jumlahPengguna; i++) {
                if (pengguna[i].akun.nama == nama_input && pengguna[i].akun.nim == nim_input) {
                    akun_sudah_ada = true;
                    cout << "Akun sudah ada. Masukkan nama dan NIM yang berbeda." << endl;
                    break;
                }
            }
        } while (akun_sudah_ada);

        pengguna[jumlahPengguna].akun.nama = nama_input;
        pengguna[jumlahPengguna].akun.nim = nim_input;
        pengguna[jumlahPengguna].jumlahBarang = 0;
        jumlahPengguna++;
        cout << "Akun berhasil didaftarkan." << endl;
    } else {
        cout << "Jumlah pengguna maksimum tercapai." << endl;
    }
    cout << "\nTekan Enter untuk melanjutkan..." << endl;
    cin.get();
    clearScreen();
}

int login(Pengguna pengguna[], int jumlahPengguna) {
    int percobaan_login = 0;
    bool login_berhasil = false;
    int index_pengguna = -1;
    string nama_input, nim_input;

    while (percobaan_login < 3 && !login_berhasil) {
        cout << "Masukkan Nama: ";
        getline(cin, nama_input);
        cout << "Masukkan NIM: ";
        getline(cin, nim_input);

        for (int i = 0; i < jumlahPengguna; i++) {
            if (pengguna[i].akun.nama == nama_input && pengguna[i].akun.nim == nim_input) {
                login_berhasil = true;
                index_pengguna = i;
                break;
            }
        }

        if (!login_berhasil) {
            percobaan_login++;
            cout << "Login Gagal! Akun tidak ditemukan." << endl;
            if (percobaan_login < 3) {
                cout << "Coba lagi. Sisa percobaan: " << 3 - percobaan_login << endl;
            } else {
                cout << "Login gagal 3 kali. Program keluar." << endl;
                return -2;
            }
        }
    }

    if (login_berhasil) {
        cout << "Login Berhasil! Selamat datang, " << pengguna[index_pengguna].akun.nama << "!" << endl;
    }
    cout << "\nTekan Enter untuk melanjutkan..." << endl;
    cin.get();
    clearScreen();
    return index_pengguna;
}

void tampilInventaris(Pengguna &pengguna) {
    if (pengguna.jumlahBarang == 0) {
        cout << "Belum ada barang dalam inventaris." << endl;
    } else {
        cout << "No. | Nama Barang           | Stok" << endl;
        cout << "----------------------------------" << endl;
        for (int i = 0; i < pengguna.jumlahBarang; i++) {
            cout << i + 1 << ".  | " << pengguna.inventaris[i].nama;
            for (int j = pengguna.inventaris[i].nama.length(); j < 22; j++) {
                cout << " ";
            }
            cout << "| " << pengguna.inventaris[i].stok << endl;
        }
    }
    cout << "\nTekan Enter untuk melanjutkan..." << endl;
    cin.get();
    clearScreen();
}

void tambahBarang(Pengguna &pengguna) {
    if (pengguna.jumlahBarang < MAX_BARANG) {
        cout << "Masukkan nama barang: ";
        getline(cin, pengguna.inventaris[pengguna.jumlahBarang].nama);
        cout << "Masukkan stok barang: ";
        cin >> pengguna.inventaris[pengguna.jumlahBarang].stok;
        while (cin.get() != '\n');

        // Tambahan: pakai pointer untuk menambah stok default 1
        tambahStok(&pengguna.inventaris[pengguna.jumlahBarang], 1); // contoh penggunaan dereference
        pengguna.jumlahBarang++;

        cout << "Barang berhasil ditambahkan." << endl;

        // Tambahan: tampilkan total barang
        tampilkanTotalBarang(pengguna); // contoh penggunaan reference
    } else {
        cout << "Inventaris penuh." << endl;
    }
    cout << "\nTekan Enter untuk melanjutkan..." << endl;
    cin.get();
    clearScreen();
}

void updateBarang(Pengguna &pengguna) {
    if (pengguna.jumlahBarang == 0) {
        cout << "Belum ada barang untuk diubah." << endl;
    } else {
        tampilInventaris(pengguna);
        int nomor_barang;
        cout << "\nMasukkan nomor barang yang ingin diubah: ";
        if (!(cin >> nomor_barang) || nomor_barang < 1 || nomor_barang > pengguna.jumlahBarang) {
            cout << "Nomor barang tidak valid." << endl;
            cin.clear();
            while (cin.get() != '\n');
        } else {
            while (cin.get() != '\n');
            cout << "Masukkan nama baru barang: ";
            getline(cin, pengguna.inventaris[nomor_barang - 1].nama);
            cout << "Masukkan stok baru barang: ";
            cin >> pengguna.inventaris[nomor_barang - 1].stok;
            while (cin.get() != '\n');
            cout << "Barang berhasil diupdate." << endl;
        }
    }
    cout << "\nTekan Enter untuk melanjutkan..." << endl;
    cin.get();
    clearScreen();
}

void hapusBarang(Pengguna &pengguna) {
    if (pengguna.jumlahBarang == 0) {
        cout << "Belum ada barang untuk dihapus." << endl;
    } else {
        tampilInventaris(pengguna);
        int nomor_barang;
        cout << "\nMasukkan nomor barang yang ingin dihapus: ";
        if (!(cin >> nomor_barang) || nomor_barang < 1 || nomor_barang > pengguna.jumlahBarang) {
            cout << "Nomor barang tidak valid." << endl;
            cin.clear();
            while (cin.get() != '\n');
        } else {
            for (int i = nomor_barang - 1; i < pengguna.jumlahBarang - 1; i++) {
                pengguna.inventaris[i] = pengguna.inventaris[i + 1];
            }
            pengguna.jumlahBarang--;
            cout << "Barang berhasil dihapus." << endl;
            while (cin.get() != '\n');
        }
    }
    cout << "\nTekan Enter untuk melanjutkan..." << endl;
    cin.get();
    clearScreen();
}

void logout() {
    cout << "Logout berhasil." << endl;
    cout << "\nTekan Enter untuk melanjutkan..." << endl;
    cin.get();
    clearScreen();
}

void keluarProgram() {
    cout << "Terima kasih telah menggunakan program ini." << endl;
    cout << "\nTekan Enter untuk melanjutkan..." << endl;
    cin.get();
    clearScreen();
}

int main() {
    Pengguna pengguna[MAX_PENGGUNA];
    int jumlahPengguna = 0;
    int pilihan_menu;

    pengguna[jumlahPengguna].akun.nama = "WidyaAyuAnggraini";
    pengguna[jumlahPengguna].akun.nim = "2409106011";
    pengguna[jumlahPengguna].jumlahBarang = 0;
    jumlahPengguna++;

    do {
        cout << "Menu Utama" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan: ";

        if (!(cin >> pilihan_menu)) {
            cout << "Input tidak valid. Masukkan angka." << endl;
            cin.clear();
            while (cin.get() != '\n');
            cout << "\nTekan Enter untuk melanjutkan..." << endl;
            cin.get();
            clearScreen();
            continue;
        }
        while (cin.get() != '\n');

        switch (pilihan_menu) {
            case 1:
                registrasi(pengguna, jumlahPengguna);
                break;
            case 2: {
                int index_pengguna = login(pengguna, jumlahPengguna);
                if (index_pengguna == -2) {
                    return 0;
                }
                if (index_pengguna != -1) {
                    int pilihan_login;
                    do {
                        cout << "\nMenu Manajemen Inventaris" << endl;
                        cout << "1. Tampilkan Inventaris" << endl;
                        cout << "2. Tambah Barang" << endl;
                        cout << "3. Update Barang" << endl;
                        cout << "4. Hapus Barang" << endl;
                        cout << "5. Logout" << endl;
                        cout << "Pilihan: ";

                        if (!(cin >> pilihan_login)) {
                            cout << "Input tidak valid. Masukkan angka." << endl;
                            cin.clear();
                            while (cin.get() != '\n');
                            cout << "\nTekan Enter untuk melanjutkan..." << endl;
                            cin.get();
                            clearScreen();
                            continue;
                        }
                        while (cin.get() != '\n');

                        switch (pilihan_login) {
                            case 1: tampilInventaris(pengguna[index_pengguna]); break;
                            case 2: tambahBarang(pengguna[index_pengguna]); break;
                            case 3: updateBarang(pengguna[index_pengguna]); break;
                            case 4: hapusBarang(pengguna[index_pengguna]); break;
                            case 5: logout(); break;
                            default:
                                cout << "Pilihan tidak valid." << endl;
                                cout << "\nTekan Enter untuk melanjutkan..." << endl;
                                cin.get();
                                clearScreen();
                        }
                    } while (pilihan_login != 5);
                }
                break;
            }
            case 3:
                keluarProgram();
                return 0;
            default:
                cout << "Pilihan tidak valid." << endl;
                cout << "\nTekan Enter untuk melanjutkan..." << endl;
                cin.get();
                clearScreen();
        }
    } while (pilihan_menu != 3);

    return 0;
}

