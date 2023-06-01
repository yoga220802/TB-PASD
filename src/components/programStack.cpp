#include <iostream>
using namespace std;

#include "..\modules\stack\stack.cpp"

// program yg menerapkan stack
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