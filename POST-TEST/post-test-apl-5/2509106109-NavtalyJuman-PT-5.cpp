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

bool login(User *userLogin){

    string username, password;
    int percobaan = 0;

    while(percobaan < 3){
        cout<<"===== LOGIN DULU ====="<<endl;

        cout<<"Username : ";
        getline(cin, username);

        cout<<"Password : ";
        getline(cin, password);

        if(username == userLogin->username && password == userLogin->nim){
            cout<<"Login Berhasil!\n"<<endl;
            return true;
        }else{
            cout<<"Login salah!\n"<<endl;
            percobaan++;
        }

        if(percobaan == 3){
            cout<<"Anda gagal login!\n";
            return false;
        }
    }
    return false;
}

void tampilJudul(){
    cout<<"\n===== DAFTAR DATA AKUN ====="<<endl;
}

void tampilJudul(string teks){
    cout<<"\n===== "<<teks<<" ====="<<endl;
}

void tampilRekursif(AkunCOC *akun, int index, int jumlahData){

    if(index == jumlahData){
        return;
    }

    cout<<"Data ke-"<<index+1<<endl;
    cout<<"Nama Pemain : "<<akun[index].namaPemain<<endl;
    cout<<"Town Hall   : "<<akun[index].townHall<<endl;
    cout<<"Trophy      : "<<akun[index].trophy<<endl;
    cout<<"Clan        : "<<akun[index].clan<<endl;
    cout<<"----------------------------"<<endl;

    tampilRekursif(akun, index+1, jumlahData);
}

void lihatData(AkunCOC *akun, int jumlahData){

    tampilJudul("DAFTAR DATA AKUN");

    if(jumlahData == 0){
        cout<<"Belum ada data akun!\n";
    }else{
        tampilRekursif(akun, 0, jumlahData);
    }
}

void tambahData(AkunCOC *akun, int *jumlahData){

    cout<<"\nTambah Data Akun"<<endl;

    cout<<"Nama Pemain : ";
    getline(cin, akun[*jumlahData].namaPemain);

    cout<<"Town Hall : ";
    cin>>akun[*jumlahData].townHall;

    cout<<"Trophy : ";
    cin>>akun[*jumlahData].trophy;
    cin.ignore();

    cout<<"Clan : ";
    getline(cin, akun[*jumlahData].clan);

    (*jumlahData)++;

    cout<<"Data berhasil ditambahkan!\n";
}

void ubahData(AkunCOC *akun, int jumlahData){

    int nomorUbah;

    cout<<"Masukkan nomor data yang ingin diubah: ";
    cin>>nomorUbah;
    cin.ignore();

    if(nomorUbah <= jumlahData){

        cout<<"Nama Pemain : ";
        getline(cin, akun[nomorUbah-1].namaPemain);

        cout<<"Town Hall : ";
        cin>>akun[nomorUbah-1].townHall;

        cout<<"Trophy : ";
        cin>>akun[nomorUbah-1].trophy;
        cin.ignore();

        cout<<"Clan : ";
        getline(cin, akun[nomorUbah-1].clan);

        cout<<"Data berhasil diubah!\n";
    }else{
        cout<<"Data tidak ditemukan!\n";
    }
}

void hapusData(AkunCOC *akun, int *jumlahData){

    int nomorHapus;

    cout<<"Masukkan nomor data yang ingin dihapus: ";
    cin>>nomorHapus;

    if(nomorHapus <= *jumlahData){

        for(int i=nomorHapus-1;i<(*jumlahData)-1;i++){
            akun[i] = akun[i+1];
        }

        (*jumlahData)--;

        cout<<"Data berhasil dihapus!\n";
    }else{
        cout<<"Data tidak ditemukan!\n";
    }
}

void sortNamaAscending(AkunCOC *akun, int jumlahData){
    for(int i=0;i<jumlahData-1;i++){
        for(int j=0;j<jumlahData-i-1;j++){
            if(akun[j].namaPemain > akun[j+1].namaPemain){
                swap(akun[j], akun[j+1]);
            }
        }
    }
    cout<<"Data diurutkan berdasarkan Nama (A-Z)\n";
}

void sortTrophyDescending(AkunCOC *akun, int jumlahData){
    for(int i=0;i<jumlahData-1;i++){
        int maxIndex = i;
        for(int j=i+1;j<jumlahData;j++){
            if(akun[j].trophy > akun[maxIndex].trophy){
                maxIndex = j;
            }
        }
        swap(akun[i], akun[maxIndex]);
    }
    cout<<"Data diurutkan berdasarkan Trophy (besar ke kecil)\n";
}

void sortTownHall(AkunCOC *akun, int jumlahData){
    for(int i=1;i<jumlahData;i++){
        AkunCOC temp = akun[i];
        int j = i-1;

        while(j>=0 && akun[j].townHall > temp.townHall){
            akun[j+1] = akun[j];
            j--;
        }

        akun[j+1] = temp;
    }
    cout<<"Data diurutkan berdasarkan Town Hall\n";
}

int main(){

    if(login(&user) == false){
        return 0;
    }

    int menu;

    do{
        cout<<"\n========================================="<<endl;
        cout<<"SISTEM MANAJEMEN DATA AKUN CLASH OF CLANS"<<endl;
        cout<<"========================================="<<endl;

        cout<<"1. Lihat Data"<<endl;
        cout<<"2. Tambah Data"<<endl;
        cout<<"3. Ubah Data"<<endl;
        cout<<"4. Hapus Data"<<endl;
        cout<<"5. Sorting Nama (A-Z)"<<endl;
        cout<<"6. Sorting Trophy (Desc)"<<endl;
        cout<<"7. Sorting Town Hall"<<endl;
        cout<<"8. Keluar"<<endl;

        cout<<"Pilih menu : ";
        cin>>menu;
        cin.ignore();

        switch(menu){

            case 1:
                lihatData(akun, jumlah);
                break;

            case 2:
                tambahData(akun, &jumlah);
                break;

            case 3:
                ubahData(akun, jumlah);
                break;

            case 4:
                hapusData(akun, &jumlah);
                break;

            case 5:
                sortNamaAscending(akun, jumlah);
                break;

            case 6:
                sortTrophyDescending(akun, jumlah);
                break;

            case 7:
                sortTownHall(akun, jumlah);
                break;

            case 8:
                cout<<"Program selesai, terima kasih!\n";
                break;

            default:
                cout<<"Menu tidak tersedia\n";
        }
    }while(menu != 8);
}