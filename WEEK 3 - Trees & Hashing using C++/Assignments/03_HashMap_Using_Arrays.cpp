#include <iostream>
#include <string>
using namespace std;

/*
 * Task 3: Implement a HashMap using arrays.
 *
 * A simple key-value HashMap built using two parallel arrays
 * (one for keys, one for values). Linear probing is used only
 * to resolve accidental collisions here; the dedicated collision
 * handling demo is in HashTableLinearProbing.cpp
 */

const int SIZE = 10;

class HashMapUsingArrays {
private:
    string keys[SIZE];
    string values[SIZE];
    bool isFilled[SIZE];

    int hashFunction(const string& key) {
        int sum = 0;
        for (char c : key) {
            sum += (int)c;
        }
        return sum % SIZE;
    }

public:
    HashMapUsingArrays() {
        for (int i = 0; i < SIZE; i++) {
            isFilled[i] = false;
        }
    }

    void put(const string& key, const string& value) {
        int index = hashFunction(key);
        int startIndex = index;

        while (isFilled[index] && keys[index] != key) {
            index = (index + 1) % SIZE;
            if (index == startIndex) {
                cout << "HashMap is full! Cannot insert " << key << endl;
                return;
            }
        }

        keys[index] = key;
        values[index] = value;
        isFilled[index] = true;
    }

    string get(const string& key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (isFilled[index]) {
            if (keys[index] == key) {
                return values[index];
            }
            index = (index + 1) % SIZE;
            if (index == startIndex) break;
        }
        return "";
    }

    void display() {
        cout << "---- HashMap Contents ----" << endl;
        for (int i = 0; i < SIZE; i++) {
            if (isFilled[i]) {
                cout << "Index " << i << " -> Key: " << keys[i] << ", Value: " << values[i] << endl;
            } else {
                cout << "Index " << i << " -> empty" << endl;
            }
        }
    }
};

int main() {
    HashMapUsingArrays map;
    int n;

    cout << "=== HashMap Using Arrays ===" << endl;
    cout << "How many key-value pairs do you want to insert? ";
    cin >> n;
    cin.ignore(); // consume newline

    for (int i = 0; i < n; i++) {
        string key, value;
        cout << "Enter key: ";
        getline(cin, key);
        cout << "Enter value: ";
        getline(cin, value);
        map.put(key, value);
    }

    map.display();

    string searchKey;
    cout << "\nEnter a key to look up its value: ";
    getline(cin, searchKey);
    string result = map.get(searchKey);

    if (!result.empty()) {
        cout << "Value for '" << searchKey << "' is: " << result << endl;
    } else {
        cout << "Key '" << searchKey << "' not found." << endl;
    }

    return 0;
}
