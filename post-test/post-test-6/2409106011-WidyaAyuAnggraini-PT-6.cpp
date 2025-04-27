#include <iostream>
#include <string>

#define MAX_PENGGUNA 100
#define MAX_BARANG 100

using namespace std;

// Struktur untuk menyimpan data akun
struct Akun {
    string nama;
    string nim;
};

// Struktur untuk menyimpan data barang
struct Barang {
    string nama;
    int stok;
};

// Struktur untuk menyimpan data pengguna
struct Pengguna {
    Akun akun;
    Barang inventaris[MAX_BARANG];
    int jumlahBarang;
};

// Fungsi tambahan untuk menampilkan total barang menggunakan reference
void tampilkanTotalBarang(const Pengguna &pengguna) {
    cout << "Total barang yang dimiliki: " << pengguna.jumlahBarang << endl;
}

// Fungsi untuk menambah stok barang menggunakan pointer
void tambahStok(Barang *barang, int tambahan) {
    barang->stok += tambahan;
}

// Fungsi untuk membersihkan layar
void clearScreen() {
    system("cls");
}

// Fungsi Bubble Sort untuk mengurutkan nama barang secara ascending (A-Z)
void bubbleSortNamaAscending(Pengguna &pengguna) {
    for (int i = 0; i < pengguna.jumlahBarang - 1; i++) {
        for (int j = 0; j < pengguna.jumlahBarang - i - 1; j++) {
            if (pengguna.inventaris[j].nama > pengguna.inventaris[j + 1].nama) {
                // Tukar elemen
                Barang temp = pengguna.inventaris[j];
                pengguna.inventaris[j] = pengguna.inventaris[j + 1];
                pengguna.inventaris[j + 1] = temp;
            }
        }
    }
}

// Fungsi Selection Sort untuk mengurutkan stok barang secara descending (besar ke kecil)
void selectionSortStokDescending(Pengguna &pengguna) {
    for (int i = 0; i < pengguna.jumlahBarang - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < pengguna.jumlahBarang; j++) {
            if (pengguna.inventaris[j].stok > pengguna.inventaris[maxIdx].stok) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            // Tukar elemen
            Barang temp = pengguna.inventaris[i];
            pengguna.inventaris[i] = pengguna.inventaris[maxIdx];
            pengguna.inventaris[maxIdx] = temp;
        }
    }
}

// Fungsi Insertion Sort untuk mengurutkan nama barang secara descending (Z-A)
void insertionSortNamaDescending(Pengguna &pengguna) {
    for (int i = 1; i < pengguna.jumlahBarang; i++) {
        Barang key = pengguna.inventaris[i];
        int j = i - 1;
        while (j >= 0 && pengguna.inventaris[j].nama < key.nama) {
            pengguna.inventaris[j + 1] = pengguna.inventaris[j];
            j--;
        }
        pengguna.inventaris[j + 1] = key;
    }
}

// Fungsi untuk registrasi pengguna baru
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

// Fungsi untuk login pengguna
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

// Fungsi untuk menampilkan inventaris dengan opsi sorting
void tampilInventaris(Pengguna &pengguna) {
    if (pengguna.jumlahBarang == 0) {
        cout << "Belum ada barang dalam inventaris." << endl;
    } else {
        int sortChoice;
        cout << "Pilih metode pengurutan:" << endl;
        cout << "1. Nama Barang (Ascending - Bubble Sort)" << endl;
        cout << "2. Stok Barang (Descending - Selection Sort)" << endl;
        cout << "3. Nama Barang (Descending - Insertion Sort)" << endl;
        cout << "4. Tanpa Pengurutan" << endl;
        cout << "Pilihan: ";
        cin >> sortChoice;
        while (cin.get() != '\n');

        switch (sortChoice) {
            case 1:
                bubbleSortNamaAscending(pengguna);
                break;
            case 2:
                selectionSortStokDescending(pengguna);
                break;
            case 3:
                insertionSortNamaDescending(pengguna);
                break;
            case 4:
                // Tidak ada pengurutan
                break;
            default:
                cout << "Pilihan tidak valid. Menampilkan tanpa pengurutan." << endl;
        }

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

// Fungsi untuk menambah barang ke inventaris
void tambahBarang(Pengguna &pengguna) {
    if (pengguna.jumlahBarang < MAX_BARANG) {
        cout << "Masukkan nama barang: ";
        getline(cin, pengguna.inventaris[pengguna.jumlahBarang].nama);
        cout << "Masukkan stok barang: ";
        cin >> pengguna.inventaris[pengguna.jumlahBarang].stok;
        while (cin.get() != '\n');

        // Tambah stok default 1 menggunakan pointer
        tambahStok(&pengguna.inventaris[pengguna.jumlahBarang], 1);
        pengguna.jumlahBarang++;

        cout << "Barang berhasil ditambahkan." << endl;
        tampilkanTotalBarang(pengguna);
    } else {
        cout << "Inventaris penuh." << endl;
    }
    cout << "\nTekan Enter untuk melanjutkan..." << endl;
    cin.get();
    clearScreen();
}

// Fungsi untuk mengupdate barang di inventaris
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

// Fungsi untuk menghapus barang dari inventaris
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

// Fungsi untuk logout
void logout() {
    cout << "Logout berhasil." << endl;
    cout << "\nTekan Enter untuk melanjutkan..." << endl;
    cin.get();
    clearScreen();
}

// Fungsi untuk keluar dari program
void keluarProgram() {
    cout << "Terima kasih telah menggunakan program ini." << endl;
    cout << "\nTekan Enter untuk melanjutkan..." << endl;
    cin.get();
    clearScreen();
}

// Fungsi utama
int main() {
    Pengguna pengguna[MAX_PENGGUNA];
    int jumlahPengguna = 0;
    int pilihan_menu;

    // Akun default
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