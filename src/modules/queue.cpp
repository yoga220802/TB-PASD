#include <iostream>
#include <deque>

using namespace std;

class Queue {
private:
    deque<string> queue;

public:
    void enqueue(string data) {
        queue.push_back(data);
    }

    string dequeue() {
        if (queue.empty()) {
            return "";
        } else {
        string front = queue.front();
        queue.pop_front();
        return front;
        }   
    }

    void clear_queue() {
        queue.clear();
    }

    void show_queue() {
        if (queue.empty()) {
            cout << "Antrian kosong" << endl;
        } else {
            for (int i = 0; i < queue.size(); ++i) {
                cout << i + 1 << ". " << queue[i] << endl;
            }
        }
    }
};