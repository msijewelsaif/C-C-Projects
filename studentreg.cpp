#include <iostream>
#include <string>
using namespace std;

// Class to represent a student
class Student {
private:
    string name;
    int id;
    string course;

public:
    // Method to register a student
    void registerStudent() {
        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter Student ID: ";
        cin >> id;
        cin.ignore();  // To ignore the newline character after ID input

        cout << "Enter Course: ";
        getline(cin, course);
    }

    // Method to display student details
    void displayStudent() {
        cout << "\n--- Student Details ---" << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Course: " << course << endl;
    }
};

int main() {
    Student student;  // Create a student object

    cout << "Welcome to the Student Registration System!" << endl;
    student.registerStudent();  // Register student details

    cout << "\nStudent Registered Successfully!" << endl;
    student.displayStudent();   // Display student details

    return 0;
}
