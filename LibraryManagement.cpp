#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;

public:
    Book(string t, string a) : title(t), author(a) {}

    void display() {
        cout << "Title: " << title << ", Author: " << author << endl;
    }
};

int main() {
    vector<Book> library;
    int choice;
    string title, author;

    while (true) {
        cout << "\n1. Add Book\n2. List Books\n3. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character

        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                library.push_back(Book(title, author));
                cout << "Book added." << endl;
                break;

            case 2:
                cout << "Books in library:" << endl;
                for (auto& book : library) {
                    book.display();
                }
                break;

            case 3:
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
