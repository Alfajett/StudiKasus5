#include <iostream>
using namespace std;

class hitung {
public:
    void inputData();
    void inputSKS();

private:
    string nama, nim;
    int jumlah_matkul;
    int totalSKS = 0;
    int total = 0;

    string nama_matkul[100];
    int sks[100];

    void inputSKS(int n);
    void hitungTotal(int n);
};

void hitung::inputData() {
   cout << "+========================================+" << endl;
	cout << "| \t PROGRAM HITUNG UKT MAHASISWA \t |" << endl;
	cout << "+========================================+" << endl;
	cout << "| Masukkan Nama \t\t\: "; cin >> nama;
	cout << "| Masukkan NIM \t\t\t: "; cin >> nim;
	cout << "| Masukkan jumlah matkul \t: "; cin >> jumlah_matkul;
	cout << "+========================================+" << endl << endl;

}

void hitung::inputSKS(int n) {
    if (n == jumlah_matkul) return;
    cout << "Masukkan nama mata kuliah ke-" << n + 1 << ": ";
    cin >> nama_matkul[n];
    cout << "Masukkan jumlah SKS mata kuliah ke-" << n + 1 << ": ";
    cin >> sks[n];
    inputSKS(n + 1);
}

void hitung::hitungTotal(int n) {
    if (n == jumlah_matkul) return;
    total += sks[n] * 125000;
    totalSKS += sks[n];
    hitungTotal(n + 1);
}

void hitung::inputSKS() {
    inputSKS(0);
    hitungTotal(0);

    total = total - (total * 0.15);
	cout << "\n===============================" << endl;
    cout << "Total SKS: " << totalSKS;
    cout << "\nTotal Pembayaran : Rp" << total << endl;
    cout << "\n===============================" << endl;
}

int main() {
    hitung ukt;
    ukt.inputData();
    ukt.inputSKS();
}

