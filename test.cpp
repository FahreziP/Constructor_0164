#include <iostream>
#include <string>
using namespace std;

// Forward declaration
class Petugas;
class Peminjam;

class Buku {
private:
    string judul;
    string penulis;
    bool dipinjam; // status peminjaman (private)

public:
    Buku(string judul, string penulis) : judul(judul), penulis(penulis), dipinjam(false) {}

    // Setter dengan chain function
    Buku& setJudul(string judul) {
        this->judul = judul;
        return *this;
    }

    Buku& setPenulis(string penulis) {
        this->penulis = penulis;
        return *this;
    }

    // Getter
    string getJudul() const {
        return judul;
    }

    string getPenulis() const {
        return penulis;
    }

    bool isDipinjam() const {
        return dipinjam;
    }

    // Deklarasi friend class
    friend class Petugas;
};

class Peminjam {
private:
    string nama;

public:
    Peminjam(string nama) : nama(nama) {}

    string getNama() const {
        return nama;
    }
};

class Petugas {
public:
    void prosesPinjam(Buku* b, Peminjam* p) {
        if (!b->dipinjam) {
            b->dipinjam = true;
            cout << "Buku \"" << b->getJudul() << "\" berhasil dipinjam oleh " << p->getNama() << endl;
        } else {
            cout << "Buku \"" << b->getJudul() << "\" sudah dipinjam" << endl;
        }
    }

    void prosesKembali(Buku* b) {
        if (b->dipinjam) {
            b->dipinjam = false;
            cout << "Buku \"" << b->getJudul() << "\" berhasil dikembalikan" << endl;
        } else {
            cout << "Buku \"" << b->getJudul() << "\" tidak sedang dipinjam" << endl;
        }
    }
};

int main() {
    Buku buku1("Matematika", "John Doe");
    Peminjam peminjam1("Alice");
    Petugas petugas;

    // Status awal
    cout << "Status awal buku:" << endl;
    cout << "Judul: " << buku1.getJudul() << ", Dipinjam: " << (buku1.isDipinjam() ? "Ya" : "Tidak") << endl;

    // Proses peminjaman
    petugas.prosesPinjam(&buku1, &peminjam1);
    cout << "Status setelah dipinjam: " << (buku1.isDipinjam() ? "Ya" : "Tidak") << endl;

    // Coba pinjam lagi
    petugas.prosesPinjam(&buku1, &peminjam1);

    // Proses pengembalian
    petugas.prosesKembali(&buku1);
    cout << "Status setelah dikembalikan: " << (buku1.isDipinjam() ? "Ya" : "Tidak") << endl;

    // Coba kembalikan lagi
    petugas.prosesKembali(&buku1);

    return 0;
}