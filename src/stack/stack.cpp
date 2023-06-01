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


// percobaan
// import file ti stack.cpp
int main() {
    Stack programStack;
    cout << "Coba Push\n";
    programStack.push("asd");
    programStack.push("qwe");
    programStack.push("zxc");

    programStack.show_stack();

    cout << "\nCoba pop\n";
    programStack.pop();
    programStack.show_stack();
    cout << "\nCoba pop2\n";
    programStack.pop();
    programStack.show_stack();

    cout << "\nCoba clear\n";
    programStack.clear();
    programStack.show_stack();
    // program stack
}