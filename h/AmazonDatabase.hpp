#pragma once
#include "Product.hpp"
#include "HashTable.hpp"
#include <string>

class AmazonDatabase {
private:
    HashTable idTable;  

public:
    void loadData(const std::string& filename);
    void findProduct(const std::string& id) const;
    void listInventory(const std::string& category) const;
};
