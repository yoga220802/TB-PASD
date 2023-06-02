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
void display_users();


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

bool find_user(string username, string password) {
    for (UserData &user : DB) {
        if (user.username == username && user.password == password) {
            curr_user = &user;
            return true;
        }
    }
    return false;
}

void update_user(UserData &user) {
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

    for (UserData &user : DB) {
        DB_USERS << user.username << ",";
        DB_USERS << user.password << ",";
        DB_USERS << user.role << endl;
    }
    DB_USERS.close();
}

void display_users() {
    // TODO: WIP
    cout << "----------" << endl;
    cout << "USERS (" << DB.size() << ")" << endl;
    for (UserData &user : DB){
        cout << user.username << ":" << user.password << ":" << user.role << endl;
    }
}
