#include "../h/Product.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::list;

Product::Product(const string& id, const string& name, const list<string>& categories)
    : id(id), name(name), categories(categories) {}


std::string Product::getId() const {
    return id;
}

string Product::getName() const {
    return name;
}

list<string> Product::getCategories() const {
    return categories;
}

void Product::setId(const string& id) {
    this->id = id;
}

void Product::setName(const string& name) {
    this->name = name;
}

void Product::setCategories(const list<string>& categories) {
    this->categories = categories;
}

void Product::printDetails() const {
    cout << "Product ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Categories: ";

    if (categories.empty()) {
        cout << "NA";
    } else {
        bool first = true;
        for (const auto& cat : categories) {
            if (!first) cout << " | ";
            cout << cat;
            first = false;
        }
    }

    cout << endl << "------------------------" << endl;
}
