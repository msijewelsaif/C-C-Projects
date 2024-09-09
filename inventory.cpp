#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product {
private:
    string name;
    int quantity;
    float price;

public:
    Product(string n, int q, float p) : name(n), quantity(q), price(p) {}

    void display() {
        cout << "Name: " << name << ", Quantity: " << quantity << ", Price: $" << price << endl;
    }
};

int main() {
    vector<Product> inventory;
    int choice, quantity;
    float price;
    string name;

    while (true) {
        cout << "\n1. Add Product\n2. List Products\n3. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character

        switch (choice) {
            case 1:
                cout << "Enter product name: ";
                getline(cin, name);
                cout << "Enter product quantity: ";
                cin >> quantity;
                cout << "Enter product price: ";
                cin >> price;
                cin.ignore();
                inventory.push_back(Product(name, quantity, price));
                cout << "Product added." << endl;
                break;

            case 2:
                cout << "Products in inventory:" << endl;
                for (auto& prod : inventory) {
                    prod.display();
                }
                break;

            case 3:
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
