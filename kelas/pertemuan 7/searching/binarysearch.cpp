#include <iostream>
using namespace std;

int main(){
    int cari, mid;
    int data[8] = {2, 5, 8, 12, 19, 22, 26, 29};
    int low = 0;
    int high = 7;
    bool found = false;
    cout << "Masukkan nilai yang ingin dicari : ";
    cin >> cari;
    while(low <= high){
        mid = (low + high) / 2;
        if(data[mid] == cari){
            found = true;
            break;
        }else if(data[mid] < cari){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    if(found){
        cout << "Data ditemukan pada indeks ke-" << mid << endl;
    }else{
        cout << "Data tidak ditemukan" << endl;
    }
    return 0;
    }