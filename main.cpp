#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

#include "./src/components/programStack.cpp"
#include "./src/components/programQueue.cpp"

#include "./src/utils/dataType.h"
#include "./src/utils/login.cpp"

int main() {
    init();
    string username, password;
    LoginReturn auth;
    while (true) {

        cout << "Masukkan Username : ";
        cin >> username;
        cout << "Masukkan password : ";
        cin >> password;

        auth = login(username, password);
        if (!auth.loggedIn) {
            cout << "Tidak dapat ijin akses" << endl;
            continue;
        }

        if (auth.role == "admin") {
            // admin
            cout << "Selamat datang admin (" << username << ")" << endl;
            break;
        } else if (auth.role == "stack") {
            // stack user
            cout << "Selamat datang user Stack (" << username << ")" << endl << endl;
            cout << "Demo Program Stack" << endl;
            // programStack();
            break;
        } else if (auth.role == "queue") {
            // Queue User
            cout << "Selamat datang user queue (" << username << ")" << endl << endl;
            cout << "Demo Program Queue" << endl;
            programQueue();
            break;
        }
    }

    // TODO: DEBUG
    cout << endl << "Curr User: " << endl;
    cout << username << ":" << password << ":" << auth.role << endl << endl;

}