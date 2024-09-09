#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product {
private:
    string name;
    float price;

public:
    Product(string n, float p) : name(n), price(p) {}

    void display() {
        cout << "Name: " << name << ", Price: $" << price << endl;
    }

    float getPrice() {
        return price;
    }
};

class ShoppingCart {
private:
    vector<Product> cart;

public:
    void addProduct(Product p) {
        cart.push_back(p);
    }

    void displayCart() {
        float total = 0;
        cout << "Shopping Cart:" << endl;
        for (auto& prod : cart) {
            prod.display();
            total += prod.getPrice();
        }
        cout << "Total: $" << total << endl;
    }
};

int main() {
    ShoppingCart cart;
    int choice;
    string name;
    float price;

    while (true) {
        cout << "\n1. Add Product to Cart\n2. View Cart\n3. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character

        switch (choice) {
            case 1:
                cout << "Enter product name: ";
                getline(cin, name);
                cout << "Enter product price: ";
                cin >> price;
                cin.ignore();
                cart.addProduct(Product(name, price));
                cout << "Product added to cart." << endl;
                break;

            case 2:
                cart.displayCart();
                break;

            case 3:
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
