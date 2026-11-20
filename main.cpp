// Number Guesser - guess the secret number between 1 and 100.
// Simple, single-file C++ console game.

#include <iostream>
#include <string>
#include <random>
#include <limits>
#include <cstdlib>

const int MIN_NUMBER = 1;
const int MAX_NUMBER = 100;

// Returns a random number in [MIN_NUMBER, MAX_NUMBER].
int secretNumber() {
    static std::random_device seed;
    static std::mt19937 engine(seed());
    std::uniform_int_distribution<int> spread(MIN_NUMBER, MAX_NUMBER);
    return spread(engine);
}

// Reads one integer from the user, re-asking until the input is valid.
int askForGuess(int attempt) {
    int guess = 0;
    while (true) {
        std::cout << "Guess #" << attempt << " (" << MIN_NUMBER << "-" << MAX_NUMBER << "): ";
        if (std::cin >> guess) {
            if (guess >= MIN_NUMBER && guess <= MAX_NUMBER) {
                return guess;
            }
            std::cout << "  That is outside the range. Try again.\n";
            continue;
        }
        if (std::cin.eof()) {
            std::cout << "\nNo more input. Bye!\n";
            std::exit(0);
        }
        // Input was not a number: clear the error and throw away the bad line.
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "  Numbers only, please.\n";
    }
}

// Returns true when the user types something starting with 'y'.
bool askToPlayAgain() {
    std::cout << "\nPlay again? (y/n): ";
    std::string answer;
    std::cin >> answer;
    return !answer.empty() && (answer[0] == 'y' || answer[0] == 'Y');
}

void playOneRound() {
    const int secret = secretNumber();
    int attempt = 1;

    std::cout << "\nI picked a number between " << MIN_NUMBER << " and " << MAX_NUMBER << ".\n";

    while (true) {
        const int guess = askForGuess(attempt);

        if (guess < secret) {
            std::cout << "  Too low.\n";
        } else if (guess > secret) {
            std::cout << "  Too high.\n";
        } else {
            std::cout << "\nCorrect! The number was " << secret
                      << ". You found it in " << attempt
                      << (attempt == 1 ? " guess." : " guesses.") << "\n";
            return;
        }
        ++attempt;
    }
}

int main() {
    std::cout << "==============================\n";
    std::cout << "   1 to 100 - Number Guesser\n";
    std::cout << "==============================\n";

    do {
        playOneRound();
    } while (askToPlayAgain());

    std::cout << "Thanks for playing!\n";
    return 0;
}
