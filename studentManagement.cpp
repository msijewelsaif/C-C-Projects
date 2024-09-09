#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    string course;

public:
    Student(string n, int r, string c) : name(n), rollNo(r), course(c) {}

    void display() {
        cout << "Name: " << name << ", Roll No: " << rollNo << ", Course: " << course << endl;
    }
};

int main() {
    vector<Student> students;
    int choice, rollNo;
    string name, course;

    while (true) {
        cout << "\n1. Add Student\n2. List Students\n3. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character

        switch (choice) {
            case 1:
                cout << "Enter student name: ";
                getline(cin, name);
                cout << "Enter roll number: ";
                cin >> rollNo;
                cin.ignore();
                cout << "Enter course: ";
                getline(cin, course);
                students.push_back(Student(name, rollNo, course));
                cout << "Student added." << endl;
                break;

            case 2:
                cout << "Students:" << endl;
                for (auto& student : students) {
                    student.display();
                }
                break;

            case 3:
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
