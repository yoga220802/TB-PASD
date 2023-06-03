#include <iostream>
#include <vector>
#include <conio.h>

// import file tambahan
#include "../modules/queue.cpp"
#include "../utils/utilityFunctions.h"

using namespace std;

    // program Pegawai sebagai program menerapkan queue
vector<string> programQueue(vector<string> dataLamaran) {
    // inisialsiasi objek queue
    Queue programQueue;

    // pembuatan variabel
    vector<string> lamaran = dataLamaran; // Penampung data lamaran yang dibawa saat lagin
    int pilihan = 4; // penampung menu pilihan user
    string pelamar; // penampung nama pelamar yang akan dimasukan ke antrian 

    /*
    cek data pelamar yang dibawa saat login
    jika tidak kosong maka semua data dimasukan ke objek queue
     */
    if (!lamaran.empty()) {
        for (int i = 0; i < lamaran.size(); i++) {
            programQueue.enqueue(lamaran[i]);
        }
    }

    // menu program utama
    do {
        clrscr(); // Bersihkan layar setiap kali program stack dimulai

        cout << "\t\tProgram Antrian Calon Pegawai" << endl
        << "\nPosisi anda sebagai pelamar pekerjaan.\nSilahkan pilih menu dibawah ini" << endl << endl
        << "1. Ambil antrian" << endl
        << "2. Berikan Surat Lamaran" << endl
        << "3. Logout" << endl;
        cout << endl << "Pilih Menu >> "; cin >> pilihan;

        switch (pilihan)
        {
        // kondisi user memilih untuk antrian lamaran
        case 1:
            // menampilkan seluruh pelamar
            cout << endl << "\tAntrian Pelamar" << endl;
            programQueue.show_queue();

            // masukan nama pelamar
            cout << endl << "Nama pelamar : "; cin >> pelamar;

            // menambahkan pelamar baru ke objek stack
            programQueue.enqueue(pelamar);
            
            // pesan validasi bahwa antrian pelamar baru telah ditambahkan
            cout << "Pelamar bernama " << pelamar << " sudah mengantri, silahkan menunggu." << endl;
            break;
        
        case 2:
            // menampilkan seluruh pelamar
            cout << endl << "\tAntrian Pelamar" << endl;
            programQueue.show_queue();

            // menampung data pelamar yang sudah memberikan surat lamaran
            pelamar = programQueue.dequeue();

            /*
            pengecekan apakah data pelamar kosong atau tidak
            jika tidak kosong menampilkan pesan validasi bahwa data sudah diberikan 
            jika kosong menampilkan pemberitahuan bahwa tidak ada surat lamaran untuk dibaca
            */
            if (pelamar != "") {
                cout << endl << "Surat lamaran dari " << pelamar << " sudah diambil" << endl;
            } else {
                cout << endl << "Tidak ada surat lamaran untuk diambil" << endl;
            }
            break;
        
        case 3:
            // menampilkan seluruh pelamar
            cout << endl << "\tAntrian Pelamar" << endl;
            programQueue.show_queue();

            // konfirmasi bahwa data dalam stack akan dihapus
            cout << endl << "Data dalam tumpukan akan dihapus" << endl;;
            programQueue.clear_queue();
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
    } while (pilihan != 3);

    return lamaran;
}
