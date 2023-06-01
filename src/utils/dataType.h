#ifndef DATATYPE_H
#define DATATYPE_H

#include <string>

using namespace std;
struct UserData {
    string username;
    string password;
    string role;
};

struct LoginReturn {
    bool loggedIn;
    string role;
};

#endif
