#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Car {
private:
    string model;
    bool available;

public:
    Car(string m, bool a) : model(m), available(a) {}

    void display() {
        cout << "Model: " << model << ", Available: " << (available ? "Yes" : "No") << endl;
    }

    void rent() {
        if (available) {
            available = false;
            cout << "Car rented." << endl;
        } else {
            cout << "Car is not available!" << endl;
        }
    }

    void returnCar() {
        if (!available) {
            available = true;
            cout << "Car returned." << endl;
        } else {
            cout << "Car was not rented!" << endl;
        }
    }

    bool isAvailable() {
        return available;
    }
};

int main() {
    vector<Car> fleet = {
        Car("Toyota Camry", true),
        Car("Honda Accord", true)
    };

    int choice;
    string model;

    while (true) {
        cout << "\n1. Rent Car\n2. Return Car\n3. List Cars\n4. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character

        switch (choice) {
            case 1:
                cout << "Enter car model to rent: ";
                getline(cin, model);
                for (auto& car : fleet) {
                    if (car.isAvailable() && car.getModel() == model) {
                        car.rent();
                        break;
                    }
                }
                break;

            case 2:
                cout << "Enter car model to return: ";
                getline(cin, model);
                for (auto& car : fleet) {
                    if (!car.isAvailable() && car.getModel() == model) {
                        car.returnCar();
                        break;
                    }
                }
                break;

            case 3:
                cout << "Cars in fleet:" << endl;
                for (auto& car : fleet) {
                    car.display();
                }
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
