/* This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction */

#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

// the entry point to our application
int main() {

    bool bPlayAgain = false;
    do {
        PrintIntro();
        PlayGame();
        bPlayAgain = AskToPlayAgain();
    }
    while(bPlayAgain);

    return 0; // exit application
}

// introduce the game
void PrintIntro() {
    constexpr int32 WORD_LENGTH = 9;
    std::cout << "Welcome to Bulls and Cows.\n";
    std::cout << "Can you guess what " << WORD_LENGTH;
    std::cout << " letter isogram I'm thinking of?\n";
    return;
}

void PlayGame() {

    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    std::cout << std::endl;

    // loop for number of turns asking for guesses
    // TODO: change from FOR to WHILE loop once we are validating tries
    for (int32 count = 1; count <= MaxTries; count++) {
        FText Guess = GetGuess(); // TODO: make loop checking valid

        // submit valid guess to the game
        // print number of bulls and cows
        std::cout << "Your guess was: " << Guess << std::endl;
        std::cout << std::endl;
    }

    // TODO: Add game summary
}

// get a guess from the player
FText GetGuess() {
    int32 CurrentTry = BCGame.GetCurrentTry();

    std::cout << "Try " << CurrentTry << ". Enter your guess: ";
    FText Guess = "";
    std::getline(std::cin, Guess);
    return Guess;
}

bool AskToPlayAgain() {
    std::cout << "Do you want to play again (y/n)?";
    FText Response = "";
    std::getline(std::cin, Response);
    return (Response[0] == 'y' || Response[0] == 'Y');
}
