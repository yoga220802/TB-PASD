#include <iostream>
#include <vector>
#include <conio.h>

// import file tambahan
#include "../modules/queue.cpp"
#include "../utils/utilityFunctions.h"

using namespace std;

    // program Pegawai sebagai program menerapkan queue
vector<string> programQueue() {
    // inisialsiasi objek queue
    Queue programQueue;

    // pembuatan variabel
    vector<string> lamaran; // Penampung data lamaran yang dibawa saat lagin
    int pilihan; // penampung menu pilihan user
    string pelamar, confirmLogout = "y"; // penampung nama pelamar yang akan dimasukan ke antrian 

    /*
    cek data pelamar yang dibawa saat login
    jika tidak kosong maka semua data dimasukan ke objek queue
     */

    // menu program utama
    do {
        clrscr(); // Bersihkan layar setiap kali program queue dimulai

        cout << "\t\tProgram Antrian Calon Pegawai" << endl
        << "\nPosisi anda sebagai pelamar pekerjaan.\nSilahkan pilih menu dibawah ini" << endl << endl
        << "1. Berikan antrian" << endl
        << "2. Ambil Surat Lamaran" << endl
        << "3. Logout" << endl;
        cout << endl << "Pilih Menu >> "; cin >> pilihan;
        cin.ignore();
        switch (pilihan)
        {
        // kondisi user memilih untuk antrian lamaran
        case 1:
            // menampilkan seluruh pelamar
            cout << endl << "\tAntrian Pelamar" << endl;
            programQueue.show_queue();

            // masukan nama pelamar
            cout << endl << "Nama pelamar : "; getline(cin, pelamar);

            // menambahkan pelamar baru ke objek queue
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
                lamaran.push_back(pelamar);
            } else {
                cout << endl << "Tidak ada surat lamaran untuk diambil" << endl;
            }
            break;
        
        case 3:
            cout << endl << "Jika anda logout, antrian pelamar yang belum memberikan surat lamaran akan dihapus." << endl
            << "Apakah anda akan keluar? "; cin >> confirmLogout;
            if (confirmLogout == "Y" || confirmLogout == "y") {
            // pemberitahuan bahwa berhasil logout
            cout << endl << "Logout berhasil, dan semua antrian dihapus" << endl;
            programQueue.clear_queue();
            break;
            } else {
                cout << "Batal logout";
            }

        default:
            break;
        }

    cout << endl << "klik tombol apapun untuk melanjutkan...";
    getch();
    } while (pilihan != 3 && confirmLogout != "Y" ||confirmLogout != "y");

    return lamaran;
}

// int main() {
//     vector<string> dataLamaran = {};
//     programQueue(dataLamaran);
// }
