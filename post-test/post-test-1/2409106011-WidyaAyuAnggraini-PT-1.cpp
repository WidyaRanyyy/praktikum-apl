
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Informasi login
    string nama_terdaftar = "WidyaAyuAnggraini";
    string nim_terdaftar = "2409106011";
    
    cout << "Selamat Datang di Program Konversi Satuan Ukuran Panjang" << endl;
    
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
    
    // Program Utama - Konversi Satuan
    bool program_berjalan = true;
    
    while (program_berjalan) {
        string pilihan_menu;
        
        cout << "                                                 " << endl;
        cout << "           ============================          " << endl;
        cout << "    =========================================    " << endl;
        cout << "======= MENU KONVERSI SATUAN UKURAN PANJANG ========" << endl;
        cout << "|| 1. Konversi Meter ke (Centimeter, Mile, Foot)  ||" << endl;
        cout << "|| 2. Konversi Centimeter ke (Meter, Mile, Foot)  ||" << endl;
        cout << "|| 3. Konversi Mile ke (Meter, Centimeter, Foot)  ||" << endl;
        cout << "|| 4. Konversi Foot ke (Meter, Centimeter, Mile)  ||" << endl;
        cout << "|| 5. Keluar                                      ||" << endl;
        cout << "====================================================" << endl;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan_menu;
        
        if (pilihan_menu == "1") {
            // Konversi dari Meter
            cout << "\n>>>>> Konversi dari Meter <<<<<<" << endl;
            double nilai_meter;
            cout << "Masukkan nilai dalam Meter: ";
            
            cin >> nilai_meter;
            // Rumus konversi
            double nilai_centimeter = nilai_meter * 100;
            double nilai_mile = nilai_meter / 1609.34;
            double nilai_foot = nilai_meter * 3.28084;
            
            // Menampilkan hasil
            cout << "\nHasil Konversi:" << endl;
            cout << nilai_meter << " Meter = " << nilai_centimeter << " Centimeter" << endl;
            cout << nilai_meter << " Meter = " << nilai_mile << " Mile" << endl;
            cout << nilai_meter << " Meter = " << nilai_foot << " Foot" << endl;
            
        } else if (pilihan_menu == "2") {
            // Konversi dari Centimeter
            cout << "\n>>>>> Konversi dari Centimeter <<<<<" << endl;
            double nilai_centimeter;
            cout << "Masukkan nilai dalam Centimeter: ";
            
            cin >> nilai_centimeter;
            // Rumus konversi
            double nilai_meter = nilai_centimeter / 100;
            double nilai_mile = nilai_centimeter / 160934;
            double nilai_foot = nilai_centimeter / 30.48;
            
            // Menampilkan hasil
            cout << "\nHasil Konversi:" << endl;
            cout << nilai_centimeter << " Centimeter = " << nilai_meter << " Meter" << endl;
            cout << nilai_centimeter << " Centimeter = " << nilai_mile << " Mile" << endl;
            cout << nilai_centimeter << " Centimeter = " << nilai_foot << " Foot" << endl;
            
        } else if (pilihan_menu == "3") {
            // Konversi dari Mile
            cout << "\n>>>>> Konversi dari Mile <<<<<" << endl;
            double nilai_mile;
            cout << "Masukkan nilai dalam Mile: ";
            
            cin >> nilai_mile;
            // Rumus konversi
            double nilai_meter = nilai_mile * 1609.34;
            double nilai_centimeter = nilai_mile * 160934;
            double nilai_foot = nilai_mile * 5280;
            
            // Menampilkan hasil
            cout << "\nHasil Konversi:" << endl;
            cout << nilai_mile << " Mile = " << nilai_meter << " Meter" << endl;
            cout << nilai_mile << " Mile = " << nilai_centimeter << " Centimeter" << endl;
            cout << nilai_mile << " Mile = " << nilai_foot << " Foot" << endl;
            
        } else if (pilihan_menu == "4") {
            // Konversi dari Foot
            cout << "\n>>>>> Konversi dari Foot <<<<<" << endl;
            double nilai_foot;
            cout << "Masukkan nilai dalam Foot: ";
            
            cin >> nilai_foot;
            // Rumus konversi
            double nilai_meter = nilai_foot / 3.28084;
            double nilai_centimeter = nilai_foot * 30.48;
            double nilai_mile = nilai_foot / 5280;
            
            // Menampilkan hasil
            cout << "\nHasil Konversi:" << endl;
            cout << nilai_foot << " Foot = " << nilai_meter << " Meter" << endl;
            cout << nilai_foot << " Foot = " << nilai_centimeter << " Centimeter" << endl;
            cout << nilai_foot << " Foot = " << nilai_mile << " Mile" << endl;
            
        } else if (pilihan_menu == "5") {
            cout << "<<< Terima kasih telah menggunakan program ini! >>>" << endl;
            program_berjalan = false;
        } else {
            cout << "Pilihan tidak valid! Silakan pilih 1-5." << endl;
        }
    }
    
    return 0;
}
