#include <iostream>
#include <conio.h>
#include "../modules/userman.cpp"
#include "../utils/utilityFunctions.h"

int programUserman(){
    int index;

    if (curr_user->role != "admin"){
        return 0;
    }

    while (true){
        int size = DB.size();

        clrscr();
        cout << endl << "\t\tProgram User Manager" << endl;
        
        display();                                      // Display Users

        cout << "pilih 1";
        if (size > 1)
            cout << " - " << size;
        cout << " untuk Update user atau" << endl;

        // Menu lainnya
        cout << endl;
        cout << "   " << size + 1 << ") Tambah User" << endl        // size + 1 == add
             << "   " << size + 2 << ") Delete User" << endl        // size + 2 == del
             << "   " << size + 3 << ") Keluar"      << endl        // size + 3 == exit
             << endl <<  "Pilih [1 - " << size + 3 << "] >> ";

        cin >> index;

        cin.clear();
        cin.ignore();

        // Keluar sebagai admin
        if (index == size + 3){
            break;
        }

        // Add User
        if (index == size + 1){
            clrscr();
            cout << "\t\tAdd User" << endl;

            add_user();
            store_user();
            init();

            cout << endl << "Update User Telah berhasil !!!!"
                 << endl << "klik tombol apapun untuk melanjutkan...";

            getch();
            cin.clear();

        }

        // sebelum update / del cek terlebih dahulu apakah ada user
        if (DB.empty()){

        }

        // Update user
        if (index >=1 && index <= size){
            clrscr();
            UserData &user = DB[index - 1];

            cout << "\t\tUpdate User"   << endl             << endl
                 << "Username : "       << user.username    << endl
                 << "Password : "       << user.password    << endl
                 << "Role     : "       << user.role        << endl
                 << endl;
            
            update_user(user);
            store_user();
            init();

            cout << endl << "Update User Telah berhasil !!!!"
                 << endl << "klik tombol apapun untuk melanjutkan...";

            getch();
            cin.clear();
        }

        // Delete User
        if (index == size + 2){

        }
    }
    cout << endl << "klik tombol apapun untuk melanjutkan...";
    getch();
    return 0;
}

