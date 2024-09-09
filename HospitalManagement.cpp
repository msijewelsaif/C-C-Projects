#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Patient {
private:
    string name;
    int id;
    string diagnosis;

public:
    Patient(string n, int i, string d) : name(n), id(i), diagnosis(d) {}

    void display() {
        cout << "Name: " << name << ", ID: " << id << ", Diagnosis: " << diagnosis << endl;
    }
};

int main() {
    vector<Patient> patients;
    int choice, id;
    string name, diagnosis;

    while (true) {
        cout << "\n1. Add Patient\n2. List Patients\n3. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character

        switch (choice) {
            case 1:
                cout << "Enter patient name: ";
                getline(cin, name);
                cout << "Enter patient ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter diagnosis: ";
                getline(cin, diagnosis);
                patients.push_back(Patient(name, id, diagnosis));
                cout << "Patient added." << endl;
                break;

            case 2:
                cout << "Patients:" << endl;
                for (auto& patient : patients) {
                    patient.display();
                }
                break;

            case 3:
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
