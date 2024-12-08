#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct HashTable {
    struct Pair {
        string key;
        int value;
    };

    vector<list<Pair>> table;
    size_t tableSize;

    HashTable(size_t size) : tableSize(size), table(size) {}

    size_t hashFunction(const string& key) const {
        size_t hash = 0;
        for (char c : key) {
            hash = hash * 31 + c;
        }
        return hash % tableSize;
    }

    int* lookup(const string& key) {
        size_t index = hashFunction(key);
        for (auto& pair : table[index]) {
            if (pair.key == key) {
                return &pair.value;
            }
        }
        return nullptr;
    }

    void insert(const string& key, int value) {
        size_t index = hashFunction(key);
        for (auto& pair : table[index]) {
            if (pair.key == key) {
                pair.value = value;
                return;
            }
        }
        table[index].push_back({ key, value });
    }

    void erase(const string& key) {
        size_t index = hashFunction(key);
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->key == key) {
                bucket.erase(it);
                return;
            }
        }
    }

    void printTable() const {
        for (size_t i = 0; i < tableSize; ++i) {
            cout << "Ведро " << i << ": ";
            for (const auto& pair : table[i]) {
                cout << "(" << pair.key << ", " << pair.value << ") ";
            }
            cout << endl;
        }
    }
};

void testHashTable() {
    HashTable hashTable(10);

    hashTable.insert("Предмет1", 1);
    hashTable.insert("Предмет2", 2);
    hashTable.insert("Предмет3", 3);

    if (int* value = hashTable.lookup("Предмет1")) {
        cout << "Поиск 'Предмет1': " << *value << endl;
    }
    else {
        cout << "Поиск 'Предмет1': Не найден" << endl;
    }

    if (int* value = hashTable.lookup("Предмет2")) {
        cout << "Поиск 'Предмет2': " << *value << endl;
    }
    else {
        cout << "Поиск 'Предмет2': Не найден" << endl;
    }

    if (int* value = hashTable.lookup("Предмет4")) {
        cout << "Поиск 'Предмет4': " << *value << endl;
    }
    else {
        cout << "Поиск 'Предмет4': Не найден" << endl;
    }

    hashTable.erase("Предмет2");
    cout << "После удаления 'Предмет2':" << endl;
    hashTable.printTable();

    hashTable.insert("Предмет5", 4);
    cout << "После добавления 'Предмет5':" << endl;
    hashTable.printTable();
}

int main() {
    setlocale(LC_ALL, "ru");

    testHashTable();

    return 0;
}
