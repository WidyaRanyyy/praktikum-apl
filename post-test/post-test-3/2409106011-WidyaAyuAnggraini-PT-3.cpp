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

int tampilkanInventaris(const Barang inventaris[], int jumlahBarang) {
    if (jumlahBarang == 0) {
        cout << "Belum ada barang" << endl;
        return 0;
    }

    cout << "No. | Nama Barang           | Stok" << endl;
    cout << "----------------------------------" << endl;

    for (int i = 0; i < jumlahBarang; i++) {
        cout << i + 1 << ".  | ";
        cout << inventaris[i].nama;
        for (int j = inventaris[i].nama.length(); j < 22; j++) {
            cout << " ";
        }
        cout << "| " << inventaris[i].stok << endl;
    }
    return 1;
}

int main() {
    Pengguna pengguna[MAX_PENGGUNA];
    int jumlahPengguna = 0;
    int pilihan_menu, pilihan_login;
    string nama_input, nim_input;

    // Tambahkan akun default
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
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.get();
            system("cls");
            continue;
        }
        while (cin.get() != '\n');

        switch (pilihan_menu) {
            case 1: {
                if (jumlahPengguna < MAX_PENGGUNA) {
                    bool akun_sudah_ada = false;
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
                                cout << "\nTekan Enter untuk melanjutkan...";
                                cin.clear();
                                while (cin.get() != '\n');
                                cin.get();
                                system("cls");
                                break;
                            }
                        }
                    } while (akun_sudah_ada);

                    pengguna[jumlahPengguna].akun.nama = nama_input;
                    pengguna[jumlahPengguna].akun.nim = nim_input;
                    pengguna[jumlahPengguna].jumlahBarang = 0;
                    jumlahPengguna++;
                    cout << "Akun berhasil didaftarkan." << endl;
                    cout << "\nTekan Enter untuk melanjutkan...";
                    cin.clear();
                    while (cin.get() != '\n');
                    cin.get();
                    system("cls");
                } else {
                    cout << "Jumlah pengguna maksimum tercapai." << endl;
                }
                break;
            }
            case 2: {
                int percobaan_login = 0;
                bool login_berhasil = false;
                int index_pengguna = -1;

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
                            cout << "\nTekan Enter untuk melanjutkan...";
                            cin.clear();
                            while (cin.get() != '\n');
                            cin.get();
                            system("cls");
                        } else {
                            cout << "Login gagal 3 kali. Program keluar." << endl;
                            exit(0);
                        }
                    }
                }

                if (login_berhasil) {
                    cout << "Login Berhasil! Selamat datang, " << pengguna[index_pengguna].akun.nama << "!" << endl;
                    cout << "\nTekan Enter untuk melanjutkan...";
                    cin.clear();
                    while (cin.get() != '\n');
                    cin.get();
                    system("cls");

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
                            cout << "\nTekan Enter untuk melanjutkan...";
                            cin.clear();
                            while (cin.get() != '\n');
                            cin.get();
                            system("cls");
                            continue;
                        }
                        while (cin.get() != '\n');

                        switch (pilihan_login) {
                            case 1:
                                tampilkanInventaris(pengguna[index_pengguna].inventaris, pengguna[index_pengguna].jumlahBarang);
                                break;
                            case 2: {
                                if (pengguna[index_pengguna].jumlahBarang < MAX_BARANG) {
                                    cout << "Masukkan nama barang: ";
                                    getline(cin, pengguna[index_pengguna].inventaris[pengguna[index_pengguna].jumlahBarang].nama);
                                    cout << "Masukkan stok barang: ";
                                    cin >> pengguna[index_pengguna].inventaris[pengguna[index_pengguna].jumlahBarang].stok;
                                    while (cin.get() != '\n');
                                    pengguna[index_pengguna].jumlahBarang++;
                                    cout << "Barang berhasil ditambahkan." << endl;
                                } else {
                                    cout << "Inventaris penuh." << endl;
                                }
                                break;
                            }
                            case 3: {
                                if (pengguna[index_pengguna].jumlahBarang == 0) {
                                    cout << "Belum ada barang untuk diubah." << endl;
                                } else {
                                    tampilkanInventaris(pengguna[index_pengguna].inventaris, pengguna[index_pengguna].jumlahBarang);
                                    int index_barang;
                                    cout << "Masukkan nomor barang yang akan diubah: ";
                                    cin >> index_barang;
                                    while (cin.get() != '\n');

                                    if (index_barang > 0 && index_barang <= pengguna[index_pengguna].jumlahBarang) {
                                        cout << "Masukkan nama barang baru: ";
                                        getline(cin, pengguna[index_pengguna].inventaris[index_barang - 1].nama);
                                        cout << "Masukkan stok barang baru: ";
                                        cin >> pengguna[index_pengguna].inventaris[index_barang - 1].stok;
                                        while (cin.get() != '\n');
                                        cout << "Barang berhasil diubah." << endl;
                                    } else {
                                        cout << "Nomor barang tidak valid." << endl;
                                    }
                                }
                                break;
                            }
                            case 4: {
                                if (pengguna[index_pengguna].jumlahBarang == 0) {
                                    cout << "Belum ada barang untuk dihapus." << endl;
                                } else {
                                    tampilkanInventaris(pengguna[index_pengguna].inventaris, pengguna[index_pengguna].jumlahBarang);
                                    int index_barang;
                                    cout << "Masukkan nomor barang yang akan dihapus: ";
                                    cin >> index_barang;
                                    while (cin.get() != '\n');

                                    if (index_barang > 0 && index_barang <= pengguna[index_pengguna].jumlahBarang) {
                                        for (int i = index_barang - 1; i < pengguna[index_pengguna].jumlahBarang - 1; i++) {
                                            pengguna[index_pengguna].inventaris[i] = pengguna[index_pengguna].inventaris[i + 1];
                                        }
                                        pengguna[index_pengguna].jumlahBarang--;
                                        cout << "Barang berhasil dihapus." << endl;
                                    } else {
                                        cout << "Nomor barang tidak valid." << endl;
                                    }
                                }
                                break;
                            }
                            case 5:
                                cout << "Logout berhasil." << endl;
                                break;
                            default:
                                cout << "Pilihan tidak valid." << endl;
                                break;
                        }
                        cout << "\nTekan Enter untuk melanjutkan...";
                        cin.clear();
                        while (cin.get() != '\n');
                        cin.get();
                        system("cls");
                    } while (pilihan_login != 5);
                } else {
                    cout << "Login Gagal! Akun tidak ditemukan." << endl;
                    cout << "\nTekan Enter untuk melanjutkan...";
                    cin.clear();
                    while (cin.get() != '\n');
                    cin.get();
                    system("cls");
                }
                break;
            }
            case 3:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.clear();
                while (cin.get() != '\n');
                cin.get();
                system("cls");
                break;
        }
    } while (pilihan_menu != 3);

    return 0;
}