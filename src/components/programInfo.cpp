#include <iostream>
#include <conio.h>

#include "../utils/utilityFunctions.h"
using namespace std;

void info() {
    clrscr();
    cout << garis("=", 40) << endl
    << "\tProgram Penerimaan Pegawai" << endl
    << garis("-", 40) << endl;

    cout << endl << "dibuat oleh : " << endl
    << "1. Ahmad Nur Sahid (2206042)" << endl
    << "2. Yoga Agustiansyah (2206050)" << endl
    << garis("-", 40) << endl;

    cout << endl << "\tProgram Utama" << endl
    << garis("~", 40) << endl;

    cout << "1. Program Admin (User Manager)" << endl
    << "Program yang menjalankan peran sebagai admin," << endl
    << "yang memiliki hak akses untuk membuat user," << endl
    << "melihat data user, mengubah data user, dan menghapus user." << endl
    << garis("-", 40) << endl;

    cout << "2. Program Penerima Pegawai (Stack)" << endl
    << "Program yang menjalankan peran sebagai penerima pegawai," << endl
    << "memiliki hak akses untuk mengambil surat lamaran," << endl
    << "memproses surat lamaran, dan membuang surat lamaran." << endl
    << garis("-", 40) << endl;

    cout << "3. Program Pelamar Pekerjaan (Queue)" << endl
    << "Program yang menjalankan peran sebagai pengatur pelamar pekerjaan," << endl
    << "memiliki hak akses untuk memberikan nomor antrian," << endl
    << "dan mengambil surat lamaran." << endl
    << endl;
    
    cout << garis("=", 40) << endl;
    cout << endl << "Tekan tombol apapun untuk melanjutkan...";
    getch();
}