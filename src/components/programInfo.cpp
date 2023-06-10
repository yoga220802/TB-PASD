#include <iostream>
#include <conio.h>

#include "../utils/utilityFunctions.h"
using namespace std;

void info() {
    clrscr();
    cout << garis("=", 50) << endl
    << "\tProgram Penerimaan Pegawai" << endl
    << garis("=", 50) << endl;

    cout << endl << "dibuat oleh : " << endl
    << "1. Ahmad Nur Sahid (2206042)" << endl
    << "2. Yoga Agustiansyah (2206050)" << endl
    << garis("-", 50) << endl;

    cout << endl << "Program Utama" << endl
    << garis("~", 50) << endl;

    cout << "1. Program Admin (User Manager)" << endl
    << "   Menjalankan peran sebagai admin," << endl
    << "   yang memiliki hak akses CRUD, yaitu untuk: " << endl
    << "     - membuat user (Create)" << endl
    << "     - melihat data user (Read)" << endl
    << "     - mengubah data user (Update)" << endl 
    << "     - menghapus user (Delete)" << endl
    << garis("- ", 25) << endl << endl;

    cout << "2. Program Penerima Pegawai (Stack)" << endl
    << "   Menjalankan peran sebagai penerima pegawai," << endl
    << "   memiliki hak akses untuk : " << endl
    << "     - mengambil surat lamaran (Push)" << endl
    << "     - memproses surat lamaran (Pop)" <<endl 
    << "     - membuang surat lamaran (Clear)" << endl
    << garis("- ", 25) << endl << endl;

    cout << "3. Program Pelamar Pekerjaan (Queue)" << endl
    << "   Menjalankan peran sebagai pengatur pelamar pekerjaan," << endl
    << "   memiliki hak akses untuk : " << endl 
    << "     - memberikan nomor antrian (Enqueue)" << endl
    << "     - mengambil surat lamaran (Dequeue)" << endl << endl;

    cout << garis("=", 50) << endl;
    cout << endl << "Tekan tombol apapun untuk melanjutkan...";
    getch();
}