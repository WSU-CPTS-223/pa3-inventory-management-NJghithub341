#include "../h/HashTable.hpp"
#include <iostream>
using namespace std;

bool HashTable::isEmpty() const {
    int total = 0;
    for (int i = 0; i < buckets; i++)
        total += table[i].size();
    return total == 0;
}

int HashTable::hashFunction(const string& key) const {
    hash<string> hasher;
    return hasher(key) % buckets;
}

void HashTable::insertItem(const string& key, const Product& value) {
    int index = hashFunction(key);
    auto& cell = table[index];
    for (auto& kv : cell)
        if (kv.first == key) { kv.second = value; return; }
    cell.emplace_back(key, value);
}

bool HashTable::findItem(const string& key, Product& result) const {
    int index = hashFunction(key);
    for (auto& kv : table[index])
        if (kv.first == key) { result = kv.second; return true; }
    return false;
}

void HashTable::removeItem(const string& key) {
    int index = hashFunction(key);
    auto& cell = table[index];
    for (auto it = cell.begin(); it != cell.end(); ++it)
        if (it->first == key) { cell.erase(it); return; }
}

void HashTable::printTable() const {
    for (int i = 0; i < buckets; i++) {
        if (table[i].empty()) continue;
        for (auto& kv : table[i]) {
            cout << kv.first << " → ";
            kv.second.printDetails();
        }
    }
}
