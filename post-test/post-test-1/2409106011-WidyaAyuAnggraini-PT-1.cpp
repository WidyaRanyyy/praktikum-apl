#include <iostream>
#include <string>
using namespace std;

// Fungsi konversi dari Meter
void konversi_meter() {
    int pilihan;
    double meter;
    cout << "Konversi Meter ke:\n";
    cout << "1. Centimeter\n";
    cout << "2. Mile\n";
    cout << "3. Foot\n";
    cout << "Pilih pilihan (1/2/3): ";
    cin >> pilihan;

    cout << "Masukkan nilai dalam meter: ";
    cin >> meter;

    switch (pilihan) {
        case 1:
            cout << meter << " meter = " << meter * 100 << " centimeter\n";
            break;
        case 2:
            cout << meter << " meter = " << meter * 0.000621371 << " mile\n";
            break;
        case 3:
            cout << meter << " meter = " << meter * 3.28084 << " foot\n";
            break;
        default:
            cout << "Pilihan tidak valid\n";
    }
}

// Fungsi konversi dari Centimeter
void konversi_centimeter() {
    int pilihan;
    double centimeter;
    cout << "Konversi Centimeter ke:\n";
    cout << "1. Meter\n";
    cout << "2. Mile\n";
    cout << "3. Foot\n";
    cout << "Pilih pilihan (1/2/3): ";
    cin >> pilihan;

    cout << "Masukkan nilai dalam centimeter: ";
    cin >> centimeter;

    switch (pilihan) {
        case 1:
            cout << centimeter << " centimeter = " << centimeter / 100 << " meter\n";
            break;
        case 2:
            cout << centimeter << " centimeter = " << centimeter * 0.0000062137 << " mile\n";
            break;
        case 3:
            cout << centimeter << " centimeter = " << centimeter * 0.0328084 << " foot\n";
            break;
        default:
            cout << "Pilihan tidak valid\n";
    }
}

// Fungsi konversi dari Mile
void konversi_mile() {
    int pilihan;
    double mile;
    cout << "Konversi Mile ke:\n";
    cout << "1. Meter\n";
    cout << "2. Centimeter\n";
    cout << "3. Foot\n";
    cout << "Pilih pilihan (1/2/3): ";
    cin >> pilihan;

    cout << "Masukkan nilai dalam mile: ";
    cin >> mile;

    switch (pilihan) {
        case 1:
            cout << mile << " mile = " << mile * 1609.34 << " meter\n";
            break;
        case 2:
            cout << mile << " mile = " << mile * 160934 << " centimeter\n";
            break;
        case 3:
            cout << mile << " mile = " << mile * 5280 << " foot\n";
            break;
        default:
            cout << "Pilihan tidak valid\n";
    }
}

// Fungsi konversi dari Foot
void konversi_foot() {
    int pilihan;
    double foot;
    cout << "Konversi Foot ke:\n";
    cout << "1. Meter\n";
    cout << "2. Centimeter\n";
    cout << "3. Mile\n";
    cout << "Pilih pilihan (1/2/3): ";
    cin >> pilihan;

    cout << "Masukkan nilai dalam foot: ";
    cin >> foot;

    switch (pilihan) {
        case 1:
            cout << foot << " foot = " << foot * 0.3048 << " meter\n";
            break;
        case 2:
            cout << foot << " foot = " << foot * 30.48 << " centimeter\n";
            break;
        case 3:
            cout << foot << " foot = " << foot * 0.000189394 << " mile\n";
            break;
        default:
            cout << "Pilihan tidak valid\n";
    }
}

// Fungsi untuk login
bool login() {
    string username = "admin";
    string password = "12345";
    string nama, nim;
    int attempts = 0;

    while (attempts < 3) {
        cout << "Masukkan Nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;

        if (nama == username && nim == password) {
            cout << "Login berhasil!\n";
            return true;
        } else {
            attempts++;
            cout << "Login gagal. Anda memiliki " << (3 - attempts) << " percobaan tersisa.\n";
        }
    }
    cout << "Login gagal setelah 3 percobaan. Program berhenti.\n";
    return false;
}

int main() {
    // Memulai login
    if (!login()) {
        return 0;  // Jika login gagal, program akan berhenti
    }

    while (true) {
        int pilihan;
        cout << "\nMenu Konversi:\n";
        cout << "1. Konversi Meter ke (Centimeter, Mile, Foot)\n";
        cout << "2. Konversi Centimeter ke (Meter, Mile, Foot)\n";
        cout << "3. Konversi Mile ke (Meter, Centimeter, Foot)\n";
        cout << "4. Konversi Foot ke (Meter, Centimeter, Mile)\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1/2/3/4/5): ";
        cin >> pilihan;

        if (pilihan == 1) {
            konversi_meter();
        } else if (pilihan == 2) {
            konversi_centimeter();
        } else if (pilihan == 3) {
            konversi_mile();
        } else if (pilihan == 4) {
            konversi_foot();
        } else if (pilihan == 5) {
            cout << "Terima kasih telah menggunakan program ini!\n";
            break;
        } else {
            cout << "Pilihan tidak valid, silakan coba lagi.\n";
        }
    }

    return 0;
}
