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

    void pop() {
        if (stack.empty()) {
            cout << "Stack kosong" << endl;
        } else {
            stack.pop_back();
        }
    }

    void clear() {
        stack.clear();
    }

    void show_stack() {
        if (stack.empty()) {
            cout << "Stack kosong" << endl;
        } else {
            for (int i = 0; i < stack.size(); ++i) {
                cout << i + 1 << ". " << stack[i] << endl;
            }
        }
    }
};