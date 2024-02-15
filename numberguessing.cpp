#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

void guessTheNumber() {
    srand(static_cast<unsigned int>(time(0)));
    int secretNumber = rand() % 100 + 1;

    cout << "Welcome to the Guess the Number game!" << endl;
    cout << "I have selected a number between 1 and 100. Can you guess it?" << endl;


    int attempts = 0;
    int guessedNumber = 0;

    while (guessedNumber != secretNumber) {
        
        cout << "Enter your guess: ";
        if (!(cin >> guessedNumber)) {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        attempts++;

    
        if (guessedNumber < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guessedNumber > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number " << secretNumber
                << " in " << attempts << " attempts." << endl;
        }
    }
}

int main() {
    guessTheNumber();
    return 0;
}
