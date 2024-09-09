#include <iostream>
#include <string>
using namespace std;

class VotingSystem {
private:
    string candidates[3] = {"Sakib", "Mushfiq", "Safanur"};  // List of candidates
    int votes[3] = {0, 0, 0};  // Array to store votes for each candidate
    int totalVotes = 0;

public:
    // Display the list of candidates
    void displayCandidates() {
        cout << "Candidates in the election: " << endl;
        for (int i = 0; i < 3; i++) {
            cout << (i + 1) << ". " << candidates[i] << endl;
        }
    }

    // Function to cast a vote
    void castVote() {
        int choice;
        cout << "Enter the number of the candidate you want to vote for (1-3): ";
        cin >> choice;

        if (choice >= 1 && choice <= 3) {
            votes[choice - 1]++;  // Increment vote for the chosen candidate
            totalVotes++;
            cout << "You have successfully voted for " << candidates[choice - 1] << "." << endl;
        } else {
            cout << "Invalid choice! Please vote again." << endl;
        }
    }

    // Display the voting results
    void displayResults() {
        cout << "\nVoting Results:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << candidates[i] << " received " << votes[i] << " votes." << endl;
        }

        // Find and announce the winner
        int maxVotes = 0;
        string winner;
        bool tie = false;

        for (int i = 0; i < 3; i++) {
            if (votes[i] > maxVotes) {
                maxVotes = votes[i];
                winner = candidates[i];
                tie = false;
            } else if (votes[i] == maxVotes) {
                tie = true;
            }
        }

        if (tie) {
            cout << "The election is a tie!" << endl;
        } else {
            cout << "The winner is: " << winner << " with " << maxVotes << " votes." << endl;
        }
    }

    // Function to display the total number of votes cast
    void displayTotalVotes() {
        cout << "Total votes cast: " << totalVotes << endl;
    }
};

int main() {
    VotingSystem voting;
    int choice;

    do {
        cout << "\nVoting System Menu:" << endl;
        cout << "1. Display candidates" << endl;
        cout << "2. Cast a vote" << endl;
        cout << "3. Display voting results" << endl;
        cout << "4. Display total votes" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                voting.displayCandidates();
                break;
            case 2:
                voting.castVote();
                break;
            case 3:
                voting.displayResults();
                break;
            case 4:
                voting.displayTotalVotes();
                break;
            case 5:
                cout << "Exiting the system. Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
