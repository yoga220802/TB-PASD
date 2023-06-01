#include <iostream>
#include "../modules/queue.cpp"

using namespace std;

    // Contoh penggunaan
int main() {
    Queue queue;

    cout << "Coba enque\n";
    queue.enqueue("5");
    queue.enqueue("10");
    queue.enqueue("15");
    queue.show_queue();

    cout << "\ncoba dequeue\n";
    queue.dequeue();
    queue.show_queue();

    cout << "\ncoba clear\n";
    queue.clear_queue();
    queue.show_queue();

    cout << "\ncoba dequeue kosong\n";
    queue.dequeue();
    queue.show_queue();


    return 0;
}
