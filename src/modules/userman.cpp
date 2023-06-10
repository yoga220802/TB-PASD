#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include "../utils/dataType.h"

#define DB_NAME "./src/DB/users.csv"

using namespace std;

fstream DB_USERS;
vector<UserData> DB;
UserData *curr_user = nullptr;

void init() {
    DB.clear();

    DB_USERS.open(DB_NAME);
    string line;

    // skip 1 baris
    getline(DB_USERS, line);

    while (getline(DB_USERS, line)) {
        stringstream ss(line);
        UserData user_tmp;

        getline(ss, user_tmp.username, ',');
        getline(ss, user_tmp.password, ',');
        getline(ss, user_tmp.role);

        DB.push_back(user_tmp);
    }
    DB_USERS.close();
}

bool find_user(string username) {
    for (UserData& user : DB) {
        if (user.username == username) {
            return 1;
        }
    }
    return 0;
}

int update_user(UserData& user) {
    string username, role;

    while (true) {
        cout << "Username Baru  : ";
        cin >> username;

        // mencari username yang sama
        if (!find_user(username)) {
            user.username = username;
            break;
        }

        cout << "Tidak dapat menggunakan username yang sama"
             << endl << "Coba Lagi !!!" << endl << endl;
    }

    // new password
    cout << "Password Baru  : ";
    cin >> user.password;
    
    // user saat ini tidak dapat ganti role jika user saat ini sebagai admin
    if (curr_user->username == user.username && user.role == "admin"){
        cout << "Gunakan admin lainya untuk mengubah role admin" << endl;
        return 0;
    }

    do {
        cout << endl << "pilih role (admin/stack/queue)" << endl
             << "Role Baru      : "; 
        cin >> role;

        // cek role
        if (role == "admin" || role == "stack" || role == "queue"){
            user.role = role;
            break;
        }

        cout << "Pastikan anda memilih salah satu role yang telah di sediakan" << endl;
    } while (true);
    return 1;
}

void store_user() {
    DB_USERS.open(DB_NAME, ios::out | ios::trunc);
    DB_USERS << "username,password,role" << endl;

    for (UserData& user : DB) {
        DB_USERS << user.username << ",";
        DB_USERS << user.password << ",";
        DB_USERS << user.role << endl;
    }
    DB_USERS.close();
}

void display() {
    if (DB.empty()){
        cout << endl << endl << "Tidak ada user " << endl;
    } else {
        cout << endl << endl 
             << "Daftar User (" << DB.size() << ")" << endl
             << garis("-", 50) << endl 
             << "NO\t" << "Username\t" << "Password\t" << "Role" << endl;
        for (int i=0; i < DB.size(); i++){
            UserData& user = DB[i];
            cout << i+1 << "\t" 
                 << user.username << "\t\t" 
                 << user.password << "\t\t" 
                 << user.role << endl;
        }
    }
}

bool login(string username, string password) {
    for (UserData& user : DB) {
        if (user.username == username && user.password == password) {
            curr_user = &user;
            return true;
        }
    }
    return false;
}

void add_user(){
    UserData new_user;
    update_user(new_user);
    DB.push_back(new_user);
}