#include "../h/AmazonDatabase.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <list>

using namespace std;
using std::ifstream;
using std::stringstream;


void AmazonDatabase::loadData(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: could not open file " << filename << endl;
        return;
    }

    string line;
    getline(file, line); 

    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, categoryField;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, categoryField, ',');

        list<string> categories;
        if (categoryField.empty()) categories.push_back("NA");
        else {
            stringstream catStream(categoryField);
            string token;
            while (getline(catStream, token, '|'))
                categories.push_back(token);
        }

        Product p(id, name, categories);
        idTable.insertItem(id, p);
    }

    file.close();
    cout << "Data loaded successfully!" << endl;
}

void AmazonDatabase::findProduct(const string& id) const {
    Product result;
    if (idTable.findItem(id, result))
        result.printDetails();
    else
        cout << "Inventory/Product not found." << endl;
}

void AmazonDatabase::listInventory(const string& category) const {
    cout << "Listing inventory for category: " << category << endl;
    cout << "(Category-based search not yet implemented )" << endl;
}
