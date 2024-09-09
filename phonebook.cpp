#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Contact {
private:
    string name;
    string phoneNumber;

public:
    Contact(string n, string p) : name(n), phoneNumber(p) {}

    void display() {
        cout << "Name: " << name << ", Phone Number: " << phoneNumber << endl;
    }

    string getName() {
        return name;
    }
};

int main() {
    vector<Contact> phonebook;
    int choice;
    string name, phoneNumber;

    while (true) {
        cout << "\n1. Add Contact\n2. List Contacts\n3. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character

        switch (choice) {
            case 1:
                cout << "Enter contact name: ";
                getline(cin, name);
                cout << "Enter phone number: ";
                getline(cin, phoneNumber);
                phonebook.push_back(Contact(name, phoneNumber));
                cout << "Contact added." << endl;
                break;

            case 2:
                cout << "Contacts:" << endl;
                for (auto& contact : phonebook) {
                    contact.display();
                }
                break;

            case 3:
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
