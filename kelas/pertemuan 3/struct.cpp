#include <iostream>
#include <string>
#include <cstring>  // Untuk strcpy

using namespace std;


//nested struct
typedef struct {
    char nim[10];
    string nama;
} datamhs;

typedef struct {
    float nilai_uts;
    float nilai_uas;
} datanilai;

typedef struct {
    datamhs mhs;
    datanilai nil;
} nilai;

int main() {
    nilai nilaimhs;

    // Mengisi data mahasiswa
    strcpy(nilaimhs.mhs.nim, "6054");  // Gunakan strcpy untuk char array
    nilaimhs.mhs.nama = "Daffa";       // Bisa langsung diisi karena tipe string
    nilaimhs.nil.nilai_uts = 60;
    nilaimhs.nil.nilai_uas = 60;

    // Menampilkan data mahasiswa
    cout << "NIM : " << nilaimhs.mhs.nim << endl;
    cout << "Nama : " << nilaimhs.mhs.nama << endl;
    cout << "Nilai UTS : " << nilaimhs.nil.nilai_uts << endl;
    cout << "Nilai UAS : " << nilaimhs.nil.nilai_uas << endl;

    return 0;
}
