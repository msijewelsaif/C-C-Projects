#include <iostream>
#include <string>
using namespace std;

class HotelRoom {
public:
    int roomNumber; 
    bool isBooked;
    string customerName;
    int numOfDays;
    double roomCharge;

    // Constructor to initialize room details
    HotelRoom(int num) {
        roomNumber = num;
        isBooked = false;
        customerName = "";
        numOfDays = 0;
        roomCharge = 0.0;
    }

    // Function to book the room
    void bookRoom(string customer, int days) {
        if (!isBooked) {
            isBooked = true;
            customerName = customer;
            numOfDays = days;
            roomCharge = calculateCharge(days);
            cout << "Room " << roomNumber << " has been booked by " << customerName << " for " << numOfDays << " days." << endl;
        } else {
            cout << "Room " << roomNumber << " is already booked." << endl;
        }
    }

    // Function to calculate room charges
    double calculateCharge(int days) {
        const double ratePerDay = 100.0;  // Assuming $100 per day
        return days * ratePerDay;
    }

    // Function to display customer details
    void displayDetails() {
        if (isBooked) {
            cout << "Room " << roomNumber << " is booked by " << customerName << " for " << numOfDays << " days. Total charge: $" << roomCharge << endl;
        } else {
            cout << "Room " << roomNumber << " is available." << endl;
        }
    }

    // Function to checkout and free the room
    void checkout() {
        if (isBooked) {
            cout << "Room " << roomNumber << " is now free. " << customerName << " has checked out." << endl;
            isBooked = false;
            customerName = "";
            numOfDays = 0;
            roomCharge = 0.0;
        } else {
            cout << "Room " << roomNumber << " is already available." << endl;
        }
    }
};

int main() {
    const int totalRooms = 5;
    HotelRoom rooms[totalRooms] = {101, 102, 103, 104, 105};

    int choice, roomNum, days;
    string name;

    do {
        cout << "\nHotel Management System" << endl;
        cout << "1. Book a room" << endl;
        cout << "2. Display room details" << endl;
        cout << "3. Checkout from a room" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter room number to book (101-105): ";
                cin >> roomNum;
                cout << "Enter customer name: ";
                cin >> name;
                cout << "Enter number of days to stay: ";
                cin >> days;

                if (roomNum >= 101 && roomNum <= 105) {
                    rooms[roomNum - 101].bookRoom(name, days);
                } else {
                    cout << "Invalid room number!" << endl;
                }
                break;

            case 2:
                cout << "Enter room number to display details (101-105): ";
                cin >> roomNum;

                if (roomNum >= 101 && roomNum <= 105) {
                    rooms[roomNum - 101].displayDetails();
                } else {
                    cout << "Invalid room number!" << endl;
                }
                break;

            case 3:
                cout << "Enter room number to checkout (101-105): ";
                cin >> roomNum;

                if (roomNum >= 101 && roomNum <= 105) {
                    rooms[roomNum - 101].checkout();
                } else {
                    cout << "Invalid room number!" << endl;
                }
                break;
                
            case 4:
                cout << "Exiting the system. Thank you!" << endl;
                break;

            default:
                cout << "Invalid choice. Try again!" << endl;
        }

    } while (choice != 4);

    return 0;
}
