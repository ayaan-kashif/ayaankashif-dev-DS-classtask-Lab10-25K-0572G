#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

struct Node {
    string tag;
    int count;
    Node* next;

    Node(string t) {
        tag = t;
        count = 1;
        next = NULL;
    }
};

class HashTable {
    Node* table[SIZE];

    int hashFunction(string tag) {
        int key = 0;

        for (int i = 0; i < tag.length(); i++) {
            key = (key * 31 + tag[i]) % SIZE;
        }

        return key;
    }

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i] = NULL;
    }

    void insert(string tag) {
        int index = hashFunction(tag);
        Node* temp = table[index];

        while (temp != NULL) {
            if (temp->tag == tag) {
                temp->count++;
                return;
            }
            temp = temp->next;
        }

        Node* newNode = new Node(tag);
        newNode->next = table[index];
        table[index] = newNode;

        int length = 0;
        temp = table[index];

        while (temp != NULL) {
            length++;
            temp = temp->next;
        }

        if (length > 5)
            cout << "System Overload Warning!" << endl;
    }

    void search(string tag) {
        int index = hashFunction(tag);
        Node* temp = table[index];

        while (temp != NULL) {
            if (temp->tag == tag) {
                cout << "Hashtag: " << tag << endl;
                cout << "Count: " << temp->count << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Hashtag not found!" << endl;
    }

    void remove(string tag) {
        int index = hashFunction(tag);
        Node* temp = table[index];
        Node* prev = NULL;

        while (temp != NULL) {
            if (temp->tag == tag) {
                if (prev == NULL)
                    table[index] = temp->next;
                else
                    prev->next = temp->next;

                delete temp;
                cout << "Hashtag removed!" << endl;
                return;
            }

            prev = temp;
            temp = temp->next;
        }

        cout << "Hashtag not found!" << endl;
    }

    int longestChain() {
        int longest = 0;

        for (int i = 0; i < SIZE; i++) {
            int count = 0;
            Node* temp = table[i];

            while (temp != NULL) {
                count++;
                temp = temp->next;
            }

            if (count > longest)
                longest = count;
        }

        return longest;
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << i << ": ";
            Node* temp = table[i];

            while (temp != NULL) {
                cout << temp->tag << "(" << temp->count << ") -> ";
                temp = temp->next;
            }

            cout << "NULL" << endl;
        }

        cout << "Longest Chain: " << longestChain() << endl;
    }
};

int main() {
    HashTable h;

    h.insert("#AI");
    h.insert("#Coding");
    h.insert("#AI");
    h.insert("#Technology");
    h.insert("#Programming");

    h.search("#AI");

    h.remove("#Coding");

    h.display();

    return 0;
}