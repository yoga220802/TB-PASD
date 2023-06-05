#include <iostream>
#include "../modules/userman.cpp"
#include "../utils/utilityFunctions.h"

int programUserman(){
    int size = DB.size();
    int index;

    if (curr_user->role != "admin"){
        return 0;
    }

    while (true){
        clrscr();
        cout << "Program User Manager" << endl;
        cin >> index;
        break;
    }
    return 0;
}

