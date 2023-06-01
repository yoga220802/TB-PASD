#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include "./dataType.h"

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

        // Menyimpan semua user ke vector
        DB.push_back(user_tmp);
    }
    DB_USERS.close();
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