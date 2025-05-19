#include <iostream>
using namespace std;

class Mahasiswa{
    private:
        static int jumlahMhs;

    public:
        string status;
        string nama;
        int nim;
        Mahasiswa(string pNama, int pNim){
            status = "Mahasiswa Baru";
            nama = pNama;
            nim = pNim;
            cout << "Mahasiswa dibuat" << nama << endl;
            cout << "Status = " << status << endl;
            ++jumlahMhs;
        };

        ~Mahasiswa(){
            cout << "Mahasiswa dengan Nama " << nama << " dihancurkan" << endl;
            --jumlahMhs;
        };

        static int getTotalMhs(){

            return jumlahMhs;
        };
};

int Mahasiswa::jumlahMhs = 0;

int main(){
    cout << "Jumlah Mahasiswa = " << Mahasiswa::getTotalMhs() << endl;
    Mahasiswa mhs1("Arka", 28);
    Mahasiswa mhs2("Yayan", 34);
    mhs2.status = "Mahasiswa uzur";
    cout << mhs2.status << endl;
    Mahasiswa mhs3("Joko", 24);
    cout << "Jumlah Mahasiswa = " << Mahasiswa::getTotalMhs() << endl;
    {
        Mahasiswa mhs4("Randy", 39);
        cout << "Jumlah Mahasiswa dalam bracket = " << Mahasiswa::getTotalMhs() << endl;
    }
    cout << "Jumlah Mahasiswa = " << Mahasiswa::getTotalMhs() << endl;
    return 0;
}