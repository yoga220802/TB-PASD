#include <iostream>
#include <vector>

using namespace std;

#include "./src/components/programStack.cpp"
#include "./src/components/programQueue.cpp"
#include "./src/components/programUserman.cpp"

#include "./src/utils/dataType.h"
#include "./src/utils/utilityFunctions.h"

int main() {
    init();

    string username, password;
    bool auth;

    vector<string> dataPelamar; // menampung hasil return dari program queue 
    vector<string> sisaPelamar;
    
    int index;

    while(true){
        clrscr();
        cout << endl << "Selamat Datang Di Program Lamaran" << endl
             << garis("-", 50) << endl
             << "Silahkan login terlebih dahulu untuk masuk ke program lamaran" << endl
             << "1) Login" << endl
             << "2) Keluar " << endl << endl
             << "Pilih [1-2] >> ";

        cin >> index;

        cin.clear();
        cin.ignore();

        if (index == 2) break;
        if (index != 1) continue;

        clrscr();

        cout << endl << "LOGIN" << endl << garis("-", 50) << endl;
        cout << "Username : "; getline(cin, username);
        cout << "Password : "; getline(cin, password);

        auth = login(username, password);
        if (!auth) {
            cout << "Tidak dapat ijin akses" << endl
                 << endl << "klik tombol apapun untuk melanjutkan...";
            getch();
            cin.clear();
            continue;
        }

        cout << endl << endl << "Login Berhasil" << endl << endl;

        if (curr_user->role == "admin") {
            // admin
            programUserman();            
        } else if (curr_user->role == "stack") {
            // stack user
            sisaPelamar = programStack(dataPelamar, sisaPelamar);
        } else if (curr_user->role == "queue") {
            // Queue User
            dataPelamar = programQueue();
        }
    }

    cout << endl << "Keluar dari program berhasil" << endl
        << endl << "klik tombol apapun untuk melanjutkan...";
    getch();
}
