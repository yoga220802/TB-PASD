#include <iostream>

// #include "../src/modules/userman.cpp"
#include "../src/utils/login.cpp"

void test_login() {
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
            cout << "Selamat datang admin (" << curr_user->username << ")" << endl;
            break;
        } else if (auth.role == "stack") {
            // stack user
            cout << "Selamat datang user Stack (" << curr_user->username << ")" << endl;
            break;
        } else if (auth.role == "queue") {
            // Queue User
            cout << "Selamat datang user queue (" << curr_user->username << ")" << endl;
            break;
        }
    }
}

int main(){
    init();
    test_login();

    cout << endl << "Current User: " << endl;
    cout << curr_user->username << ":" << curr_user->password << ":" << curr_user->role << endl << endl;

    update_user(*curr_user);
    cout << endl;
    display_users();                        // Display semua user
    store_user();

    // Cek apakah ada perubahan di dalam file csv
    cout << "---------" << endl;
    cout << "Get all" << endl;

    init();                                 // Memuat ulang file
    display_users();                        // Displat ulang user
}