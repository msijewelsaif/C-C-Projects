#include <iostream>
#include <iomanip>
using namespace std;

// Function to determine if a year is a leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to get the number of days in a month
int getDaysInMonth(int month, int year) {
    switch (month) {
        case 1: return 31;  // January
        case 2: return isLeapYear(year) ? 29 : 28;  // February
        case 3: return 31;  // March
        case 4: return 30;  // April
        case 5: return 31;  // May
        case 6: return 30;  // June
        case 7: return 31;  // July
        case 8: return 31;  // August
        case 9: return 30;  // September
        case 10: return 31;  // October
        case 11: return 30;  // November
        case 12: return 31;  // December
        default: return 30;  // Fallback
    }
}

// Function to calculate the starting day of the month (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
int getStartDay(int month, int year) {
    int day = 1;  // We want to calculate the first day of the month
    int y = year - (14 - month) / 12;
    int m = month + 12 * ((14 - month) / 12) - 2;
    return (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
}

// Function to display the calendar for a specific month and year
void printCalendar(int month, int year) {
    // Array of month names
    const string months[] = {"January", "February", "March", "April", "May", "June",
                             "July", "August", "September", "October", "November", "December"};

    // Display the month and year
    cout << "\n  " << months[month - 1] << " " << year << endl;
    cout << "  -----------------------------" << endl;
    cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;

    // Calculate the starting day of the month
    int startDay = getStartDay(month, year);

    // Get the number of days in the month
    int daysInMonth = getDaysInMonth(month, year);

    // Print spaces for days before the start of the month
    int day;
    for (day = 0; day < startDay; ++day) {
        cout << "     ";
    }

    // Print the days of the month
    for (int dayNum = 1; dayNum <= daysInMonth; ++dayNum) {
        cout << setw(5) << dayNum;  // Print each day in a 5-character wide field
        if (++day % 7 == 0) {
            cout << endl;  // New line after Saturday
        }
    }

    if (day % 7 != 0) {
        cout << endl;
    }

    cout << "  -----------------------------\n";
}

int main() {
    int month, year;

    // Input month and year from the user
    cout << "Enter month (1-12): ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;

    // Validate month input
    if (month < 1 || month > 12) {
        cout << "Invalid month! Please enter a value between 1 and 12." << endl;
        return 1;
    }

    // Display the calendar
    printCalendar(month, year);

    return 0;
}
