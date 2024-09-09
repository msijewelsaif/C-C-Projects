#include <iostream>
#include <map>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    float balance;

public:
    BankAccount(int accNum, float bal) : accountNumber(accNum), balance(bal) {}

    void deposit(float amount) {
        balance += amount;
    }

    void withdraw(float amount) {
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
        } else {
            balance -= amount;
        }
    }

    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }
};

int main() {
    map<int, BankAccount> accounts;
    int choice, accNum;
    float amount;

    while (true) {
        cout << "\n1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter account number: ";
                cin >> accNum;
                accounts[accNum] = BankAccount(accNum, 0.0f);
                cout << "Account created." << endl;
                break;

            case 2:
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                if (accounts.find(accNum) != accounts.end()) {
                    accounts[accNum].deposit(amount);
                    cout << "Deposit successful." << endl;
                } else {
                    cout << "Account not found!" << endl;
                }
                break;

            case 3:
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                if (accounts.find(accNum) != accounts.end()) {
                    accounts[accNum].withdraw(amount);
                } else {
                    cout << "Account not found!" << endl;
                }
                break;

            case 4:
                cout << "Enter account number: ";
                cin >> accNum;
                if (accounts.find(accNum) != accounts.end()) {
                    accounts[accNum].display();
                } else {
                    cout << "Account not found!" << endl;
                }
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
