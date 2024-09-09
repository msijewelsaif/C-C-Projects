#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
using namespace std;

int main() {
    int number, guess, attempts = 0;

    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 0 and 10
    number = rand() % 11;  // Range from 0 to 10

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have picked a random number between 0 and 10." << endl;
    cout << "Can you guess it?" << endl;

    // Loop until the user guesses the correct number
    do {
        cout << "\nEnter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > number) {
            cout << "Too high! Try again." << endl;
        } else if (guess < number) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You've guessed the correct number." << endl;
            cout << "It took you " << attempts << " attempts." << endl;
        }

    } while (guess != number);

    return 0;
}
