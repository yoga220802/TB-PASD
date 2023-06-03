#include <iostream>

#include "./dataType.h"
#include "../modules/userman.cpp"

#define DB_NAME "./src/DB/users.csv"

using namespace std;


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