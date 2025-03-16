#include <iostream>
#include <string>

using namespace std; // Agar bisa menggunakan cout tanpa std::

int main() {
    int matriks[2][2] = {
        {1, 2},
        {3, 4}
    };

    cout << matriks[0][0] << endl; // Menampilkan elemen pertama (1)
    
    return 0;
}
