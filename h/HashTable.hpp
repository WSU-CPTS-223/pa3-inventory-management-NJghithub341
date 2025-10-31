#pragma once 
#include "Product.hpp"
#include <list>
#include <string>


class HashTable {
private:
    static const int buckets = 100;
    std::list<std::pair<std::string, Product>> table[buckets];
    int hashFunction(const std::string& key) const;
public:
    bool isEmpty() const;
    void insertItem(const std::string& key, const Product& value);
    bool findItem(const std::string& key, Product& result) const;
    void removeItem(const std::string& key);
    void printTable() const;
};
