#include <iostream>
#include <string>
using namespace std;

int main() {
    string nama = "Navtaly Juman";
    string password = "109";
    string namaInput;
    string passwordInput;
    int jumlahCobaLogin = 0;
    bool statusLogin = false;

    while (jumlahCobaLogin < 3) {
        cout << "== LOGIN DULU BANG ==" << endl;
        cout << "Nama     : ";
        getline(cin, namaInput);
        cout << "Password : ";
        getline(cin, passwordInput);
        if (namaInput == nama && passwordInput == password) {
            statusLogin = true;
            cout << "Login berhasil!" << endl;
            break;
        } else {
            jumlahCobaLogin++;
            cout << "Login salah! Percobaan ke-" << jumlahCobaLogin << endl;
        }
    }

    if (!statusLogin) {
        cout << "Anda sudah mencoba login 3 kali. Coba ingat kembali username dan password Anda." << endl;
        return 0;
    }

    int pilihanMenu;
    do {
        cout << "\n== MENU KONVERSI WAKTU ==" << endl;
        cout << "1. Jam ke Menit & Detik" << endl;
        cout << "2. Menit ke Jam & Detik" << endl;
        cout << "3. Detik ke Jam & Menit" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihanMenu;

        switch (pilihanMenu) {
            case 1: {
                int jumlahJam;
                cout << "Masukkan jam: ";
                cin >> jumlahJam;
                int hasilMenit = jumlahJam * 60;
                int hasilDetik = jumlahJam * 3600;
                cout << "Hasil: " << hasilMenit << " menit dan "
                     << hasilDetik << " detik" << endl;
                break;
            }

            case 2: {
                int jumlahMenit;
                cout << "Masukkan menit: ";
                cin >> jumlahMenit;
                int hasilJam = jumlahMenit / 60;
                int hasilDetik = jumlahMenit * 60;
                cout << "Hasil: " << hasilJam << " jam dan "
                     << hasilDetik << " detik" << endl;
                break;
            }

            case 3: {
                int jumlahDetik;
                cout << "Masukkan detik: ";
                cin >> jumlahDetik;
                int hasilJam = jumlahDetik / 3600;
                int hasilMenit = jumlahDetik / 60;
                cout << "Hasil: " << hasilJam << " jam dan "
                     << hasilMenit << " menit" << endl;
                break;
            }

            case 4:
                cout << "selesai." << endl;
                break;
            default:
                cout << "Menu tidak valid!" << endl;
        }
    } while (pilihanMenu != 4);
    return 0;
}