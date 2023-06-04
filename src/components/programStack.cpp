#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

// import file tambahan
#include "../modules/stack.cpp"
#include "../utils/utilityFunctions.h"

// program Penerima Pegawai sebagai program menerapkan stack
vector<string> programStack(vector<string> dataLamaran, vector<string> sisaLamaran) {
    // inisialisasi objek stack
    Stack programStack;

    // pembuatan variabel
    vector<string> _dataLamaran = dataLamaran; // Penampung data pelamar dari program queue
    vector<string> _sisaLamaran = sisaLamaran; // Penampung data pelamar dari program queue
    int pilihan; // penampung menu pilihan user
    string pelamar; // penampung nama pelamar jika ingin menambahkan

    /*
    cek data pelamar dari program queue
    jika tidak kosong maka semua data dimasukan ke objek stack
     */
    if (!_dataLamaran.empty()) {
        for (int i = 0; i < _dataLamaran.size(); i++) {
            programStack.push(_dataLamaran[i]);
            cout << _dataLamaran[i];
        }
    }

    if (!_sisaLamaran.empty()) {
        for (int i = 0; i < _sisaLamaran.size(); i++) {
            cout << _sisaLamaran[i];
            programStack.push(_sisaLamaran[i]);
        }
        // _sisaLamaran.clear();
    }
    
    // menu program utama
    do {
        clrscr(); // Persihkan layar setiap kali program stack dimulai
        cout << "\t\tProgram Penerimaan Pegawai" << endl
        << "\nPosisi anda sebagai penerima lamaran.\nSilahkan pilih menu dibawah ini" << endl << endl
        << "1. Terima Surat Lamaran" << endl
        << "2. Baca Surat Lamaran" << endl
        << "3. Buang Semua Surat Lamaran" << endl
        << "4. Logout" << endl
        << endl << "Pilih Menu >> "; cin >> pilihan;
        cin.ignore();

        if (pilihan < 4) {
            // menampilkan seluruh pelamar
            cout << endl << "\tTumpukan Surat Lamaran" << endl;
            programStack.show_stack();

        }
        
        switch (pilihan) {
        // kondisi user memilih untuk menerima surat lamaran baru
        case 1:
            // masukan nama pelamar
            cout << endl << "Nama pelamar : "; getline(cin, pelamar);

            // menambahkan pelamar baru ke objek stack
            programStack.push(pelamar);
            _sisaLamaran.push_back(pelamar);
            
            // pesan validasi bahwa pelamar baru telah ditambahkan
            cout << "Surat lamaran dari " << pelamar << " sudah disimpan ke tumpukan" << endl;
            break;
        
        case 2:
            // menampung data pelamar yang sudah dibaca
            pelamar = programStack.pop();

            if (_sisaLamaran.size() > 0) {
                _sisaLamaran.pop_back();
            }
            
            /*
            pengecekan apakah data pelamar kosong atau tidak
            jika tidak kosong menampilkan pesan validasi bahwa data sudah dibaca 
            jika kosong menampilkan pemberitahuan bahwa tidak ada surat lamaran untuk dibaca
            */
            if (pelamar != "") {
                cout << endl << "Surat lamaran dari " << pelamar << " sudah dibaca" << endl;
            } else {
                cout << endl << "Tidak ada surat lamaran untuk dibaca" << endl;
            }
            break;
        
        case 3:
            // konfirmasi bahwa data dalam stack akan dihapus
            cout << endl << "Data dalam tumpukan akan dihapus" << endl;;
            programStack.clear_stack();
            _sisaLamaran.clear();
            _dataLamaran.clear();
            break;

        case 4:
            // pemberitahuan bahwa berhasil logout
            cout << endl << "Logout berhasil." << endl;
            break;

        default:
            break;
        }

    cout << endl << "klik tombol apapun untuk melanjutkan...";
    getch();
    } while (pilihan != 4);
    return _sisaLamaran;
}