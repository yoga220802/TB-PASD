#ifndef DATATYPE_H
#define DATATYPE_H

#include <string>
#include <vector>

using namespace std;

struct UserData {
    string username;
    string password;
    string role;
};

struct LamaranData {
    vector<string> dataBaru;
    vector<string> dataSisa;
};

#endif
