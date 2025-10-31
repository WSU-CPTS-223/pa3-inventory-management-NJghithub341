#pragma once
#include <string>
#include <list>
#include <iostream>

using namespace std;

class Product {
private:
    string id;
    string name;
    list<string> categories;

public:
    Product() = default;
    Product(const string& id, const string& name, const list<string>& categories);

   
    Product(const std::string& id) : id(id) {}
     std::string getId() const;
    string getName() const;
    list<string> getCategories() const;

    void setId(const string& id);
    void setName(const string& name);
    void setCategories(const list<string>& categories);

    void printDetails() const;
};
