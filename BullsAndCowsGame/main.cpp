#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

// the entry point to our application
int main() {
    
    std::cout << BCGame.GetCurrentTry();
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
    constexpr int WORD_LENGTH = 9;
    std::cout << "Welcome to Bulls and Cows.\n";
    std::cout << "Can you guess what " << WORD_LENGTH;
    std::cout << " letter isogram I'm thinking of?\n";
    return;
}

void PlayGame() {
    
    BCGame.Reset();
    int MaxTries = BCGame.GetMaxTries();
    std::cout << MaxTries << std::endl;
    
    // loop for number of turns
    for (int count = 1; count <= MaxTries; count++) {
        std::string Guess = GetGuess();
        std::cout << "Your guess was: " << Guess << std::endl;
        std::cout << std::endl;
    }
    
    // TODO: Add game summary 
} 

// get a guess from the player
std::string GetGuess() {
    int CurrentTry = BCGame.GetCurrentTry();
    
    std::cout << "Try " << CurrentTry << ". Enter your guess: ";
    std::string Guess = "";
    std::getline(std::cin, Guess);
    return Guess;
}

bool AskToPlayAgain() {
    std::cout << "Do you want to play again (y/n)?";
    std::string Response = "";
    std::getline(std::cin, Response);
    return (Response[0] == 'y' || Response[0] == 'Y');
}
