#ifndef UTILITYFUNCTIONS_H
#define UTILITYFUNCTIONS_H

#include <iostream>

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

#endif