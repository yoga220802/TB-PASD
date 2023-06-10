#include <iostream>
#include <vector>
#include <conio.h>
#include <string>

using namespace std;

// import file tambahan
#include "../modules/stack.cpp"
#include "../utils/utilityFunctions.h"
#include "../utils/dataType.h"

// program Penerima Pegawai sebagai program menerapkan stack
LamaranData programStack(vector<string> lamaranBaru, vector<string> lamaranSisa) {
    // inisialisasi objek stack
    Stack programStack;

    // pembuatan variabel
    LamaranData dataLamaran;
    dataLamaran.dataBaru = lamaranBaru; // Penampung data pelamar dari program queue
    dataLamaran.dataSisa = lamaranSisa; // Penampung sisa pelamar sebelumnya
    int pilihan; // penampung menu pilihan user
    string pelamar, confirmClear; // penampung nama pelamar jika ingin menambahkan

    /*
    cek data pelamar dari program queue
    jika tidak kosong maka semua data dimasukan ke objek stack
     */

    if (!dataLamaran.dataSisa.empty()) {
        for (int i = 0; i < dataLamaran.dataSisa.size(); i++) {
            programStack.push(dataLamaran.dataSisa[i]);
        }
    }
    
    if (!dataLamaran.dataBaru.empty()) {
        for (int i = 0; i < dataLamaran.dataBaru.size(); i++) {
            programStack.push(dataLamaran.dataBaru[i]);
            dataLamaran.dataSisa.push_back(dataLamaran.dataBaru[i]);
        }
        dataLamaran.dataBaru.clear();
    }
    // menu program utama
    do {
        clrscr(); // Persihkan layar setiap kali program stack dimulai
        cout << garis("=", 50) << endl
        <<"\tProgram Penerimaan Pegawai" << endl
        << garis("=", 50) << endl;

        cout << "\nPosisi anda sebagai penerima lamaran.\nSilahkan pilih menu dibawah ini" << endl << endl;

        cout << "Menu Utama :" << endl
        << "  1. Terima Surat Lamaran" << endl
        << "  2. Baca Surat Lamaran" << endl
        << "  3. Buang Semua Surat Lamaran" << endl
        << "  4. Logout" << endl;

        // menampilkan seluruh pelamar
        cout << endl << garis("-", 50) << endl << endl
        << "Surat lamaran yang ada : " << endl;
        programStack.show_stack();

        cout << endl << endl<< garis("-", 50) << endl;

        pilihan = getInput("Pilihan menu >> ");
            
        switch (pilihan) {
        // kondisi user memilih untuk menerima surat lamaran baru
        case 1:
            // masukan nama pelamar
            cout << endl << "Nama pelamar : "; getline(cin, pelamar);

            // menambahkan pelamar baru ke objek stack
            programStack.push(pelamar);
            dataLamaran.dataSisa.push_back(pelamar);
            
            // pesan validasi bahwa pelamar baru telah ditambahkan
            cout << "Surat lamaran dari " << pelamar << " sudah disimpan ke tumpukan" << endl;
            break;
        
        case 2:
            // menampung data pelamar yang sudah dibaca
            pelamar = programStack.pop();
            
            /*
            pengecekan apakah data pelamar kosong atau tidak
            jika tidak kosong menampilkan pesan validasi bahwa data sudah dibaca 
            jika kosong menampilkan pemberitahuan bahwa tidak ada surat lamaran untuk dibaca
            */
            if (pelamar != "") {
                cout << endl << "Surat lamaran dari " << pelamar << " sudah dibaca" << endl;
                dataLamaran.dataSisa.pop_back();
            } else {
                cout << endl << "Tidak ada surat lamaran untuk dibaca" << endl;
            }
            break;
        
        case 3:
            // konfirmasi bahwa data dalam stack akan dihapus
            cout << endl << "Data dalam tumpukan akan dihapus, apakah anda yakin? "; cin >> confirmClear;
            if (confirmClear == "Y" || confirmClear == "y") {
            programStack.clear_stack();
            dataLamaran.dataSisa.clear();
            cout << endl << "Tumpukan lamaran berhasil dihapus" << endl;
            } else {
                cout << endl << "Menghapus tumpukan lamaran dibatalkan" << endl;
            }
            break;

        case 4:
            // pemberitahuan bahwa berhasil logout
            cout << endl << "Logout berhasil." << endl;
            break;

        default:
            cout << endl << "Input tidak valid. Silakan coba lagi." << endl;
            break;
        }

    cout << endl << "klik tombol apapun untuk melanjutkan...";
    getch();
    } while (pilihan != 4);
    return dataLamaran;
}