#include <iostream>
using namespace std;

const int SIZE = 10;

class HashTable {
    int table[SIZE];
    int status[SIZE];

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            table[i] = -1;
            status[i] = 0;
        }
    }

    void insert(int id) {
        int index = id % SIZE;
        int probes = 0;

        for (int i = 0; i < SIZE; i++) {
            int current = (index + i) % SIZE;
            probes++;

            if (status[current] == 1 && table[current] == id) {
                cout << "Package already exists!" << endl;
                cout << "Probes: " << probes << endl;
                return;
            }

            if (status[current] == 0 || status[current] == 2) {
                table[current] = id;
                status[current] = 1;

                cout << "Package inserted at locker " << current << endl;
                cout << "Total Probes: " << probes << endl;
                return;
            }
        }

        cout << "Warehouse Full!" << endl;
    }

    void search(int id) {
        int index = id % SIZE;

        for (int i = 0; i < SIZE; i++) {
            int current = (index + i) % SIZE;

            if (status[current] == 0) {
                break;
            }

            if (status[current] == 1 && table[current] == id) {
                cout << "Package found at locker " << current << endl;
                return;
            }
        }

        cout << "Package not found!" << endl;
    }

    void remove(int id) {
        int index = id % SIZE;

        for (int i = 0; i < SIZE; i++) {
            int current = (index + i) % SIZE;

            if (status[current] == 0)
                break;

            if (status[current] == 1 && table[current] == id) {
                status[current] = 2;
                cout << "Package deleted!" << endl;
                return;
            }
        }

        cout << "Package not found!" << endl;
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << i << ": ";

            if (status[i] == 1)
                cout << table[i];
            else if (status[i] == 2)
                cout << "Deleted";
            else
                cout << "Empty";

            cout << endl;
        }
    }
};

int main() {
    HashTable h;

    h.insert(101);
    h.insert(111);
    h.insert(121);
    h.insert(131);

    h.search(121);

    h.remove(111);

    h.search(121);

    h.display();

    return 0;
}