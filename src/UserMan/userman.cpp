#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#define DB_NAME "./src/users.csv"

using namespace std;

struct UserMan {
    string username;
    string password;
    string role;
};

// global variable untuk menampung data users
fstream DB_USERS;

void login();
UserMan find_user(string username, string password);

int main(){
    login();
}

void login(){
    string username, password;
    UserMan user;
    while (true){
        cout << "Masukkan Username : "; cin >> username;
        cout << "Masukkan password : "; cin >> password;

        user = find_user(username, password);

        if (user.role == "admin") {
            // admin
            cout << "Selamat datang admin";
            break;
        } else if (user.role == "stack"){
            // stack user
            cout << "Selamat datang user Stack";
            break;
        } else if (user.role == "queue") {
            // Queue User
            cout << "Selamat datang user queue";
            break;
        }
        // block user yang tidak dapat akses
        cout << "Tidak dapat ijin akses" << endl;
        continue;
    }
}


UserMan find_user(string username, string password){
    DB_USERS.open(DB_NAME);
    string line, usr, pwd, role;
    int pos;

    // skip satu baris
    getline(DB_USERS, line);

    while (getline(DB_USERS, line)){
        stringstream ss(line);
        UserMan user_temp;

        getline(ss, user_temp.username, ',');
        getline(ss, user_temp.password, ',');
        getline(ss, user_temp.role);
        if (user_temp.username == username && user_temp.password == password)
            return user_temp;
    }

    // return none user
    // login tidak valid
    UserMan none_user;
    return none_user;
};