#include <iostream>
#include <string>
using namespace std;

struct User{
    string username;
    string nim;
};
struct AkunCOC{
    string namaPemain;
    int townHall;
    int trophy;
    string clan;
};
User user = {"Navtaly Juman","109"};
AkunCOC akun[50];
int jumlah = 0;
int main(){
    string username, password;
    int percobaan = 0;
    while(percobaan < 3){
        cout<<"===== LOGIN DULU ====="<<endl;
        cout<<"Username : ";
        getline(cin, username);
        cout<<"Password : ";
        getline(cin, password);
        if(username == user.username && password == user.nim){
            cout<<"Login Berhasil!\n"<<endl;
            break;
        }else{
            cout<<"Login gagal!\n"<<endl;
            percobaan++;
        }
        if(percobaan == 3){
            cout<<"Anda gagal login, coba ingat kembali username dan password anda!"<<endl;
            return 0;
        }
    }
    int menu;
    do{
        cout<<"\n========================================="<<endl;
        cout<<"SISTEM MANAJEMEN DATA AKUN CLASH OF CLANS"<<endl;
        cout<<"========================================="<<endl;
        cout<<"1. Lihat Data Akun"<<endl;
        cout<<"2. Tambah Data Akun"<<endl;
        cout<<"3. Ubah Data Akun"<<endl;
        cout<<"4. Hapus Data Akun"<<endl;
        cout<<"5. Keluar"<<endl;
        cout<<"Pilih menu : ";
        cin>>menu;
        cin.ignore();
        switch(menu){
        case 1: 
            cout<<"\n===== DAFTAR DATA AKUN ====="<<endl;
            if(jumlah == 0){
                cout<<"Belum ada data akun, tambah data dulu!\n";
            }else{
                for(int i=0;i<jumlah;i++){
                    cout<<"Data ke-"<<i+1<<endl;
                    cout<<"Nama Pemain : "<<akun[i].namaPemain<<endl;
                    cout<<"Town Hall   : "<<akun[i].townHall<<endl;
                    cout<<"Trophy      : "<<akun[i].trophy<<endl;
                    cout<<"Clan        : "<<akun[i].clan<<endl;
                    cout<<"-----------------------"<<endl;
                }
            }
            break;
        case 2:
            cout<<"\nTambah Data Akun"<<endl;
            cout<<"Nama Pemain : ";
            getline(cin, akun[jumlah].namaPemain);
            cout<<"Town Hall : ";
            cin>>akun[jumlah].townHall;
            cout<<"Trophy : ";
            cin>>akun[jumlah].trophy;
            cin.ignore();
            cout<<"Clan : ";
            getline(cin, akun[jumlah].clan);
            jumlah++;
            cout<<"Data berhasil ditambahkan!\n";
            break;
        case 3:{
            int ubah;
            cout<<"Masukkan nomor data yang ingin diubah: ";
            cin>>ubah;
            cin.ignore();
            if(ubah <= jumlah){
                cout<<"Nama Pemain : ";
                getline(cin, akun[ubah-1].namaPemain);
                cout<<"Town Hall : ";
                cin>>akun[ubah-1].townHall;
                cout<<"Trophy : ";
                cin>>akun[ubah-1].trophy;
                cin.ignore();
                cout<<"Clan : ";
                getline(cin, akun[ubah-1].clan);
                cout<<"Data berhasil diubah!\n";
            }else{
                cout<<"Data tidak ditemukan!\n";
            }
            }
            break;
        case 4:{
            int hapus;
            cout<<"Masukkan nomor data yang ingin dihapus: ";
            cin>>hapus;
            if(hapus <= jumlah){
                for(int i=hapus-1;i<jumlah-1;i++){
                    akun[i] = akun[i+1];
                }
                jumlah--;
                cout<<"Data berhasil dihapus!\n";
            }else{
                cout<<"Data tidak ditemukan!\n";
            }
            }
            break;
        case 5:
            cout<<"Program selesai, terima kasih!"<<endl;
            break;
        default:
            cout<<"Menu tidak tersedia"<<endl;
        }
    }while(menu != 5);
}