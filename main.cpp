#include <iostream>
#include <vector>
using namespace std;

#include "./src/components/programStack.cpp"
#include "./src/components/programQueue.cpp"

#include "./src/utils/dataType.h"
#include "./src/utils/login.cpp"
#include "./src/utils/utilityFunctions.h"

int main() {
    init();

    string username, password;
    LoginReturn auth;

    vector<string> dataPelamar = {};
    
    int index;

    while(true){
        // WIP
        clrscr();
        cout << endl << "\t\tSelamat datang di program lamaran" << endl << endl
             << "1. Login" << endl
             << "2. Keluar " << endl << endl
             << "Pilih Menu >> ";
        cin >> index;

        // langsung cek jika pilih menu 2
        if (index == 2){
            break;
        }
        cout << endl << endl;
        cout << "Masukkan Username : "; cin >> username;
        cout << "Masukkan password : "; cin >> password;
        auth = login(username, password);
        if (!auth.loggedIn) {
            cout << "Tidak dapat ijin akses" << endl;
            continue;
        }

        if (auth.role == "admin") {
            // admin
            cout << "Selamat datang admin (" << username << ")" << endl;
            break;
        } else if (auth.role == "stack") {
            // stack user
            programStack(dataPelamar);
        } else if (auth.role == "queue") {
            // Queue User
            cout << "Selamat datang user queue (" << username << ")" << endl << endl;
            cout << "Demo Program Queue" << endl;
            programQueue();
            break;
        }
    }
    cout << endl << "Keluar dari program berhasil" << endl
         << endl << "klik tombol apapun untuk melanjutkan...";
    getch();
}
