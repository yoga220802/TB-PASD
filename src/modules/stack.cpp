#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
    vector<string> stack;

public:
    void push(string data) {
        stack.push_back(data);
    }

    string pop() {
        if (stack.empty()) {
            return "";
        } else {
        string top = stack.back();
        stack.pop_back();
        return top;
        } 
    }

    void clear_stack() {
        stack.clear();
    }

    void show_stack() {
        if (stack.empty()) {
            cout << "Tumpukan kosong" << endl;
        } else {
            for (int i = 0; i < stack.size(); ++i) {
                cout << i + 1 << ". " << stack[i] << endl;
            }
        }
    }
};