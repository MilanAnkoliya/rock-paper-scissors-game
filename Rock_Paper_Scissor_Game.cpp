#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    
#include <algorithm>  // For transform

using namespace std;

// Function to get the computer's choice
string getComputerChoice() {
    int randomNumber = rand() % 3;  // set an range between 0 and 2
    switch (randomNumber) {
        case 0: return "rock";
        case 1: return "paper";
        case 2: return "scissors";
        default: return "";
    }
}

// Function to determine the winner
string who_is_winner(string userChoice, string computerChoice) {
    if (userChoice == computerChoice) {
        return "It's a tie!";
    } else if ((userChoice == "rock" && computerChoice == "scissors") ||
               (userChoice == "scissors" && computerChoice == "paper") ||
               (userChoice == "paper" && computerChoice == "rock")) {
        return "You win!";
    } else {
        return "Computer wins!";
    }
}

int main() {
    srand(time(0));  // the random number generator
    string userChoice;
     
    //while loop for the run program multiple time.
    while (true) {
        cout << "Enter Rock, Paper, or Scissors (or type 'stop' to end the game): ";
        cin >> userChoice;

        // Convert the user input to lowercase 
        transform(userChoice.begin(), userChoice.end(), userChoice.begin(), ::tolower);

        // Exit the game if the user types "stop"
        if (userChoice == "stop") {
            cout << "Game over. Thanks for playing!" << endl;
            break;
        }

        // Check for valid input
        if (userChoice != "rock" && userChoice != "paper" && userChoice != "scissors") {
            cout << "Invalid input. Please enter Rock, Paper, or Scissors." << endl;
            continue;
        }

        // Get the computer's choice and determine the winner
        string computerChoice = getComputerChoice();
        cout << "Computer chose: " << computerChoice << endl;
        string result = who_is_winner(userChoice, computerChoice);
        cout << result << endl << endl;
    }

    return 0;
}
