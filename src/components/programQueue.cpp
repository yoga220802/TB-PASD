#include <iostream>
#include <vector>
#include <conio.h>

#include "../modules/queue.cpp"
#include "../utils/utilityFunctions.h"

using namespace std;

    // Contoh penggunaan
int programQueue() {
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
