#include <iostream>
using namespace std;

/*
 * Task 4: Display hash table with linear probing.
 *
 * Stores integer keys in a fixed size hash table and resolves
 * collisions using LINEAR PROBING: if the computed slot is already
 * taken, we keep moving to the next slot (wrapping around) until
 * an empty one is found.
 */

const int SIZE = 10;
const int EMPTY_MARKER = -999999; // sentinel value meaning "empty slot"

class HashTableLinearProbing {
private:
    int table[SIZE];

public:
    HashTableLinearProbing() {
        for (int i = 0; i < SIZE; i++) {
            table[i] = EMPTY_MARKER;
        }
    }

    int hashFunction(int key) {
        return key % SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);
        int probes = 0;

        while (table[index] != EMPTY_MARKER) {
            cout << "Collision at index " << index << " for key " << key << ", probing next slot..." << endl;
            index = (index + 1) % SIZE;
            probes++;
            if (probes == SIZE) {
                cout << "Hash table is full! Cannot insert " << key << endl;
                return;
            }
        }

        table[index] = key;
        cout << "Inserted " << key << " at index " << index << endl;
    }

    // returns index if found, else -1
    int search(int key) {
        int index = hashFunction(key);
        int probes = 0;

        while (table[index] != EMPTY_MARKER) {
            if (table[index] == key) {
                return index;
            }
            index = (index + 1) % SIZE;
            probes++;
            if (probes == SIZE) break;
        }
        return -1;
    }

    void display() {
        cout << "\n---- Hash Table (Linear Probing) ----" << endl;
        for (int i = 0; i < SIZE; i++) {
            if (table[i] != EMPTY_MARKER) {
                cout << "Index " << i << " -> " << table[i] << endl;
            } else {
                cout << "Index " << i << " -> empty" << endl;
            }
        }
    }
};

int main() {
    HashTableLinearProbing ht;
    int n;

    cout << "=== Hash Table with Linear Probing ===" << endl;
    cout << "How many keys do you want to insert? ";
    cin >> n;

    cout << "Enter " << n << " integer keys:" << endl;
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        ht.insert(key);
    }

    ht.display();

    int key;
    cout << "\nEnter a key to search: ";
    cin >> key;
    int foundIndex = ht.search(key);

    if (foundIndex != -1) {
        cout << key << " found at index " << foundIndex << endl;
    } else {
        cout << key << " not found in the hash table." << endl;
    }

    return 0;
}
