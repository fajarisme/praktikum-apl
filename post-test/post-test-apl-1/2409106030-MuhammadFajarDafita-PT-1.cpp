#include <iostream>
using namespace std;

string nama = "Muhammad Fajar Dafita";
string NIM = "030";
int percobaan = 0;

bool login() {
    string inputuser, inputpw;
    while (percobaan < 3) {
        cout << "Masukkan Nama: ";
        getline(cin, inputuser);
        cout << "Masukkan NIM: ";
        cin >> inputpw;
        if (inputuser == nama && inputpw == NIM) {
            cout << "Login Berhasil" << endl;
            return true;
        } else {
            percobaan++;
            cout << "Login Gagal."  << endl;
        }
    }
    cout << "Login Gagal Karena Mencapai Batas Percobaan" << endl;
    return false;
}
void convertSuhu() {
    double suhu, celsius, fahrenheit, kelvin, reamur;
    char satuan;
    while (true) {
        cout << "Masukkan satuan (C/R/F/K): ";
        cin >> satuan;
        if (satuan == 'C' || satuan == 'c' || satuan == 'R' || satuan == 'r' || 
            satuan == 'F' || satuan == 'f' || satuan == 'K' || satuan == 'k') {
            break;
        } else {
            cout << "Satuan tidak valid! Masukkan hanya C, R, F, atau K.\n";
        }
    }
    while (true) {
        cout << "Masukkan nilai suhu: ";
        cin >> suhu;
        if (suhu >= 0) {
            break;
        } else {
            cout << "Nilai suhu tidak valid! Masukkan hanya angka.\n";
        }
    }

    switch(satuan) {
        case 'C': case 'c':
            celsius = suhu;
            fahrenheit = (celsius * 1.8) + 32;
            kelvin = celsius + 273.15;
            reamur = celsius * 0.8;
            break;
        case 'R': case 'r':
            reamur = suhu;
            celsius = 1.25 * reamur;
            fahrenheit = 2.25 * reamur;
            kelvin = (1.25 * reamur) + 273;
            break;
        case 'F': case 'f':
            fahrenheit = suhu;
            celsius = (fahrenheit - 32 ) / 1.8;
            reamur = (fahrenheit - 32) * 0.444;
            kelvin = (fahrenheit - 32) / 1.8 + 273;
            break;
        case 'K': case 'k':
            kelvin = suhu;
            celsius = kelvin - 273;
            reamur = 0.8 * (kelvin - 273);
            fahrenheit = 1.8 * (kelvin - 273) + 32;
            break;
        default: 
            cout << "Input tidak valid" << endl;
            return;
            }
cout << "Hasil konversi suhu :\n";
cout << "Celsius: " << celsius << "C" << endl;
cout << "Reamur: " << reamur << "R" << endl;
cout << "Fahrenheit: " << fahrenheit << "F" << endl;
cout << "Kelvin: " << kelvin << "K" << endl;
}

int main(){
    if (login()){
        convertSuhu();
        while (true){
            char pilihan;
            cout << "Ingin mengulang? (y/n) = ";
            cin >> pilihan;
            if (pilihan == 'n' || pilihan == 'N'){
                cout << "Anda memilih mengakhiri program." << endl;
                break;
            } else if (pilihan == 'y' || pilihan == 'Y'){
                convertSuhu();
            } else {
                cout << "Input tidak valid, masukkan y/n." << endl;
            }
    }
    }else {
        cout << "Login Gagal" << endl;
    }
    return 0;
}