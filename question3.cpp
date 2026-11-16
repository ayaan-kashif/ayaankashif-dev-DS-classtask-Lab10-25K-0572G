#include <iostream>
using namespace std;

const int SIZE = 11;

class HashTable {
    int table[SIZE];
    int occupied;

public:
    HashTable() {
        occupied = 0;

        for (int i = 0; i < SIZE; i++)
            table[i] = -1;
    }

    float loadFactor() {
        return (float)occupied / SIZE;
    }

    void insert(int seat) {
        if ((float)(occupied + 1) / SIZE > 0.5) {
            cout << "Rehash Needed! Booking not allowed." << endl;
            return;
        }

        int index = seat % SIZE;

        for (int j = 0; j < SIZE; j++) {
            int current = (index + j * j) % SIZE;

            if (table[current] == seat) {
                cout << "Seat already booked!" << endl;
                return;
            }

            if (table[current] == -1) {
                table[current] = seat;
                occupied++;

                cout << "Seat booked at index " << current << endl;
                return;
            }
        }

        cout << "No available slot!" << endl;
    }

    void search(int seat) {
        int index = seat % SIZE;

        for (int j = 0; j < SIZE; j++) {
            int current = (index + j * j) % SIZE;

            if (table[current] == -1)
                break;

            if (table[current] == seat) {
                cout << "Seat found at index " << current << endl;
                return;
            }
        }

        cout << "Seat not found!" << endl;
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << i << ": ";

            if (table[i] == -1)
                cout << "Empty";
            else
                cout << table[i];

            cout << endl;
        }

        cout << "Load Factor: " << loadFactor() << endl;
    }
};

int main() {
    HashTable h;

    h.insert(101);
    h.insert(112);
    h.insert(123);
    h.insert(134);
    h.insert(145);
    h.insert(156);

    h.search(123);

    h.display();

    return 0;
}