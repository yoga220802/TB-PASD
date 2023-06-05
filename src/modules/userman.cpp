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


void init();
bool find_user(string username, string password);
void update_user(UserData &user);
void store_user();
void display();

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

        // Menyimpan semua user ke vector
        DB.push_back(user_tmp);
    }
    DB_USERS.close();
}

bool find_user(string username, string password) {
    for (UserData& user : DB) {
        if (user.username == username && user.password == password) {
            curr_user = &user;
            return true;
        }
    }
    return false;
}

void update_user(UserData& user) {
    // TODO: WIP
    cout << "Username Baru  : ";
    cin >> user.username;
    cout << "Password Baru  : ";
    cin >> user.password;
    cout << "Role Baru      : ";
    cin >> user.role;
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
        cout << endl 
             << endl 
             << "Daftar User (" << DB.size() << ")" << endl
             << garis("-", 50) << endl 
             << "NO\t" << "Username\t" << "Password\t" << "ROle" << endl;
        for (int i=0; i < DB.size(); i++){
            UserData& user = DB[i];
            cout << i+1 << "\t" 
                 << user.username << "\t\t" 
                 << user.password << "\t\t" 
                 << user.role << endl;
        }
    }
}

LoginReturn login(string username, string password) {
    LoginReturn data;
    data.loggedIn = false;
    data.role = "";
    for (UserData& user : DB) {
        if (user.username == username && user.password == password) {
            curr_user = &user;
            data.loggedIn = true;
            data.role = curr_user->role;
            return data;
        }
    }
    return data;
}