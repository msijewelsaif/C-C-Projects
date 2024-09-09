#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int id;
    float salary;

public:
    Employee(string n, int i, float s) : name(n), id(i), salary(s) {}

    void display() {
        cout << "Name: " << name << ", ID: " << id << ", Salary: $" << salary << endl;
    }
};

int main() {
    vector<Employee> employees;
    int choice, id;
    string name;
    float salary;

    while (true) {
        cout << "\n1. Add Employee\n2. List Employees\n3. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character

        switch (choice) {
            case 1:
                cout << "Enter employee name: ";
                getline(cin, name);
                cout << "Enter employee ID: ";
                cin >> id;
                cout << "Enter employee salary: ";
                cin >> salary;
                cin.ignore();
                employees.push_back(Employee(name, id, salary));
                cout << "Employee added." << endl;
                break;

            case 2:
                cout << "Employees:" << endl;
                for (auto& emp : employees) {
                    emp.display();
                }
                break;

            case 3:
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
