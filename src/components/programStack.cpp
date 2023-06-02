#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

// import file tambahan
#include "../modules/stack.cpp"
#include "../utils/utilityFunctions.h"

// program Penerima Pegawai sebagai program menerapkan stack
void programStack(vector<string> data_lamaran) {
    // inisialisasi objek stack
    Stack programStack;

    // pembuatan variabel
    vector<string> lamaran = data_lamaran; // Penampung data pelamar dari program queue
    int pilihan; // penampung menu pilihan user
    string pelamar; // penampung nama pelamar jika ingin menambahkan

    /*
    cek data pelamar dari program queue
    jika tidak kosong maka semua data dimasukan ke objek stack
     */
    if (!lamaran.empty()) {
        for (int i = 0; i < lamaran.size(); i++) {
            programStack.push(lamaran[i]);
        }
        
    }

    // menu program utama
    do {
        clrscr(); // Persihkan layar setiap kali program stack dimulai

        cout << "\t\tProgram Penerimaan Pegawai" << endl;
        cout << "\nPosisi anda sebagai penerima lamaran.\nSilahkan pilih menu dibawah ini" << endl << endl;
        cout << "1. Terima Surat Lamaran" << endl;
        cout << "2. Baca Surat Lamaran" << endl;
        cout << "3. Buang Semua Surat Lamaran" << endl;
        cout << "4. Logout" << endl;
        cout << endl << "Pilih Menu >> "; cin >> pilihan;

        switch (pilihan)
        {
        // kondisi user memilih untuk menerima surat lamaran baru
        case 1:
            // menampilkan seluruh pelamar
            cout << endl << "\tTumpukan Surat Lamaran" << endl;
            programStack.show_stack();

            // masukan nama pelamar
            cout << endl << "Nama pelamar : "; cin >> pelamar;

            // menambahkan pelamar baru ke objek stack
            programStack.push(pelamar);
            
            // pesan validasi bahwa pelamar baru telah ditambahkan
            cout << "Surat lamaran dari " << pelamar << " sudah disimpan ke tumpukan" << endl;
            break;
        
        case 2:
            // menampilkan seluruh pelamar
            cout << endl << "\tTumpukan Surat Lamaran" << endl;
            programStack.show_stack();

            // menampung data pelamar yang sudah dibaca
            pelamar = programStack.pop();

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
            // menampilkan seluruh pelamar
            cout << endl << "\tTumpukan Surat Lamaran" << endl;
            programStack.show_stack();

            // konfirmasi bahwa data dalam stack akan dihapus
            cout << endl << "Data dalam tumpukan akan dihapus" << endl;;
            programStack.clear();
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
    
}