#include <iostream>
using namespace std;

class angka {
private:
    int *arr;
    int panjang;
public:
    angka(int); // Constructor
    ~angka();   // Destructor
    void cetakData();
    void isiData();
};

// Definisi member Function
angka::angka(int i) { // Constructor
    panjang = i;
    arr = new int[i];
    isiData();
}

angka::~angka() { // Destructor
    cout << endl;
    cetakData();
    delete[] arr;
    cout << "Alamat Array Sudah Dilepaskan" << endl;
}

void angka::cetakData() {
    for(int i = 1; i <= panjang; i++) {
        cout << "<" << arr[i] << endl;
    }
}

void angka::isiData() {
    for(int i = 1; i <= panjang; i++) {
        cout << " = ";
        cin >> arr[i];
    }
    cout << endl;
}

int main(){
 angka belajarCPP(3); // Constructor Dipanggil
    angka *ptrBelajarCPP = new angka(5); // Constructor Dipanggil
    delete ptrBelajarCPP; // Destructor Dipanggil

    return 0;
} // Destructor Dipanggil