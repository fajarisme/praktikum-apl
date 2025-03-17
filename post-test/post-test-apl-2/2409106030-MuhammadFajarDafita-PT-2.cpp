#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_TRANSPORT 100
string username = "Muhammad Fajar Dafita";
string nim = "2409106030";
int percobaan = 0;

string namaTransportasi[MAX_TRANSPORT];
string jenisTransportasi[MAX_TRANSPORT];
string statusTransportasi[MAX_TRANSPORT];
int jumlahTransportasi = 0;

int main() {
    string nama, input_nim;
    while (percobaan < 3) {
        cout << "Masukkan Nama: ";
        getline(cin, nama);
        cout << "Masukkan NIM: ";
        getline(cin, input_nim);
        if (nama == username && input_nim == nim) {
            cout << "Login Berhasil!\n";
            break;
        } else {
            cout << "Nama atau NIM salah! Coba lagi.\n";
            percobaan++;
        }
    }
    if (percobaan == 3) {
        cout << "Percobaan login habis. Program berhenti.\n";
        return 0;
    }
    int pilihan;
    do {
        cout << "\n===== Manajemen Transportasi Wisata =====\n";
        cout << "1. Tambah Transportasi\n";
        cout << "2. Lihat Daftar Transportasi\n";
        cout << "3. Ubah Status Transportasi\n";
        cout << "4. Hapus Transportasi\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();
        
        switch (pilihan) {
            case 1: {
                if (jumlahTransportasi >= MAX_TRANSPORT) {
                    cout << "Data penuh! Tidak bisa menambah transportasi lagi.\n";
                    break;
                }
                cout << "Masukkan nama transportasi: ";
                getline(cin, namaTransportasi[jumlahTransportasi]);
                cout << "Masukkan jenis transportasi: ";
                getline(cin, jenisTransportasi[jumlahTransportasi]);
                statusTransportasi[jumlahTransportasi] = "Tersedia";
                jumlahTransportasi++;
                cout << "Transportasi berhasil ditambahkan!\n";
                break;
            }
            case 2: {
                if (jumlahTransportasi == 0) {
                    cout << "Tidak ada data transportasi.\n";
                    break;
                }
                cout << "\n================================================================\n";
                cout << "| No  | Nama Transportasi    | Jenis              | Status        |\n";
                cout << "================================================================\n";
                for (int i = 0; i < jumlahTransportasi; i++) {
                    cout << "| " << setw(3) << i + 1 << "  | "
                        << setw(20) << left << namaTransportasi[i] << " | "
                        << setw(18) << jenisTransportasi[i] << " | "
                        << setw(12) << statusTransportasi[i] << " |\n";
                }
                cout << "================================================================\n";
                break;
            }
            case 3: {
                if (jumlahTransportasi == 0) {
                    cout << "Tidak ada transportasi untuk diupdate.\n";
                    break;
                }
                int index;
                cout << "Pilih nomor transportasi yang ingin diupdate: ";
                cin >> index;
                cin.ignore();
                if (index < 1 || index > jumlahTransportasi) {
                    cout << "Nomor tidak valid!\n";
                    break;
                }
                cout << "Masukkan status baru (Tersedia/Tidak Tersedia): ";
                getline(cin, statusTransportasi[index - 1]);
                cout << "Status transportasi berhasil diperbarui!\n";
                break;
            }
            case 4: {
                if (jumlahTransportasi == 0) {
                    cout << "Tidak ada transportasi untuk dihapus.\n";
                    break;
                }
                int index;
                cout << "Pilih nomor transportasi yang ingin dihapus: ";
                cin >> index;
                if (index < 1 || index > jumlahTransportasi) {
                    cout << "Nomor tidak valid!\n";
                    break;
                }
                for (int i = index - 1; i < jumlahTransportasi - 1; i++) {
                    namaTransportasi[i] = namaTransportasi[i + 1];
                    jenisTransportasi[i] = jenisTransportasi[i + 1];
                    statusTransportasi[i] = statusTransportasi[i + 1];
                }
                jumlahTransportasi--;
                cout << "Transportasi berhasil dihapus!\n";
                break;
            }
            case 5:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid! Coba lagi.\n";
        }
    } while (pilihan != 5);
    
    return 0;
}