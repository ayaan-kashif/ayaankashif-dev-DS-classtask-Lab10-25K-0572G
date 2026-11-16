#include <iostream>
using namespace std;

const int SIZE = 11;
const int PRIME = 7;

class HashTable {
    int table[SIZE];

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i] = -1;
    }

    int hash1(int key) {
        return key % SIZE;
    }

    int hash2(int key) {
        return PRIME - (key % PRIME);
    }

    void insert(int key) {
        int index = hash1(key);
        int step = hash2(key);

        for (int j = 0; j < SIZE; j++) {
            int current = (index + j * step) % SIZE;

            if (table[current] == key) {
                cout << "Key already exists!" << endl;
                return;
            }

            if (table[current] == -1) {
                table[current] = key;
                cout << "Vault assigned at index " << current << endl;
                return;
            }
        }

        cout << "Vault Full! Cannot insert key." << endl;
    }

    void search(int key) {
        int index = hash1(key);
        int step = hash2(key);

        for (int j = 0; j < SIZE; j++) {
            int current = (index + j * step) % SIZE;

            if (table[current] == -1)
                break;

            if (table[current] == key) {
                cout << "Key found at index " << current << endl;
                return;
            }
        }

        cout << "Key not found!" << endl;
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
    }
};

int main() {
    HashTable h;

    h.insert(25);
    h.insert(36);
    h.insert(47);
    h.insert(58);
    h.insert(69);

    h.search(47);

    h.display();

    return 0;
}