#include <iostream>
using namespace std;

int main(){
    int cari;
    int data[5] = {8, 5, 2, 7, 3};
    cout << "Masukkan nilai yang ingin dicari : ";
    cin >> cari;
    for(int i = 0; i < 5; i++){
        if(data[i] == cari){
            cout << "Data ditemukan pada indeks ke-" << i << endl;
            return 0;
        }
    }
    cout << "Data tidak ditemukan" << endl;
    return 0;
}