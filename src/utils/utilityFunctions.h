#ifndef UTILITYFUNCTIONS_H
#define UTILITYFUNCTIONS_H

#include <iostream>
#include <limits>

using namespace std;

string garis(string type, int jml) {
    string _garis = "";

    for (int i = 0; i < jml; i++) {
        _garis += type;
    }
    return _garis;
}

void clrscr() {
    cout << "\033c";
}

int getInput(string message) {
    int choice;
    cout << message;
    if (!(cin >> choice)) {
        cin.clear();
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}


#endif