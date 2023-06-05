#include <iostream>
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
        cout << "   " << size + 1 << ") Tambah User" << endl        // size + 1 == add
             << "   " << size + 2 << ") Delete User" << endl        // size + 2 == del
             << "   " << size + 3 << ") Keluar"      << endl        // size + 3 == exit
             << endl <<  "Pilih [1 - " << size + 3 << "] >> ";

        cin >> index;

        cin.clear();
        cin.ignore();

        // Keluar sebagai admin
        if (index == size + 3){
            return 0;
        }

        // Add User
        if (index == size + 1){

        }

        // sebelum update / del cek terlebih dahulu apakah ada user
        if (DB.empty()){

        }

        // Update
        if (index >=1 && index <= size){

        }

        // Delete User
        if (index == size + 2){

        }


        cin >> index;
        break;
    }
    return 0;
}

