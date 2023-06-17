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
        cout << garis("=", 50) << endl
        << "\t\tProgram User Manager" << endl
        << garis("=", 50);
        
        display();                                      // Display Users

        cout << garis("-", 50) << endl;
        cout << "pilih [ 1";
        if (size > 1)
            cout << " - " << size;
        cout << " ] untuk Update user atau" << endl;

        // Menu lainnya
        cout << endl;
        cout << "   " << size + 1 << ") Tambah User" << endl        // size + 1 == add
             << "   " << size + 2 << ") Delete User" << endl        // size + 2 == del
             << "   " << size + 3 << ") Keluar"      << endl;       // size + 3 == exit        
        cout << garis("-", 50) << endl;
        index = getInput("\nPilih [1 - " + to_string(size + 3) + "] >> ");

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

            cout << endl << "Update User Telah berhasil !!!!";

            cin.clear();

        }

        // sebelum update / del cek terlebih dahulu apakah ada user di database
        else if (DB.empty()){
            cout << "Harap masukan terlebih dahulu user" << endl;
        }

        // Update user
        else if (index >=1 && index <= size){
            clrscr();
            UserData &user = DB[index - 1];

            cout << "\t\tUpdate User"   << endl             << endl
                << "Username : "       << user.username    << endl
                << "Password : "       << user.password    << endl
                << "Role     : "       << user.role        << endl
                << endl;
            
            update_user(user);
            store_user();

            cout << endl << "Update User Telah berhasil !!!!";
        }

        // Delete User
        else if (index == size + 2){
            int choice;
            choice = getInput("Pilih user [1 - " + to_string(size) + "] >> ");
            if (choice < 1 || choice > size){
                cout << endl << "Input tidak valid. Silakan coba lagi." << endl;
            } else {                
                UserData &user = DB[choice - 1];
        
                if (user.username == curr_user->username){
                    cout << endl << "Anda tidak dapat menghapus user saat ini " 
                        << endl << "gunakan admin lain untuk menghapus admin";
                } else {
                    DB.erase(DB.begin() + (choice - 1));
                    store_user();
                    cout << "Menghapus user berhasil" << endl;
                }
            }
        }
        else {
            cout << endl << "Input tidak valid. Silakan coba lagi." << endl;
        }

        cout << endl << "klik tombol apapun untuk melanjutkan...";
        getch();
        cin.clear();
    }
    cout << endl << "klik tombol apapun untuk melanjutkan...";
    getch();
    return 0;
}

