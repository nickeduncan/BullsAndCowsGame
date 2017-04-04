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
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

// the entry point to our application
int main()
{

    bool bPlayAgain = false;
    do
    {
        PrintIntro();
        PlayGame();
        bPlayAgain = AskToPlayAgain();
    }
    while(bPlayAgain);

    return 0; // exit application
}

// introduce the game
void PrintIntro()
{
  std::cout << "Welcome to Bulls and Cows.\n";
  std::cout << "Can you guess what " << BCGame.GetWordLength();
  std::cout << " letter isogram I'm thinking of?\n";
  return;
}

void PlayGame()
{
  BCGame.Reset();
  int32 MaxTries = BCGame.GetMaxTries();

  // looop asking for guess while the game is NOT won
  // and there are still tries remaining
  while(!BGGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)  {
    FText Guess = GetValidGuess();

    // submit valid guess to the game, and receive counts
    FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

    std::cout << "Bulls = " << BullCowCount.Bulls;
    std::cout << " Cows = " << BullCowCount.Cows << "\n\n";
  }

  // TODO: Add game summary
}

// loop continually until the user gives a valid guess
FText GetValidGuess()
{
  EGuessStatus Status = EGuessStatus::Invalid_Status;
  FText Guess = "";
  do
  {

    int32 CurrentTry = BCGame.GetCurrentTry();
    std::cout << "Try " << CurrentTry << ". Enter your guess: ";
    std::getline(std::cin, Guess);

    Status = BCGame.CheckGuessValidity(Guess);
    switch (Status)
    {
      case EGuessStatus::Wrong_Length:
        std::cout << "Please enter a " << BCGame.GetWordLength() << " letter word.\n";
        break;
      case EGuessStatus::Not_Isogram:
        std::cout << "Please enter an isogram.\n";
        break;
      case EGuessStatus::Not_Lowercase:
        std::cout << "Please use lowercase letters." << '\n';
        break;
      default:
        // assume the guess is valid
        break;
    }
    std::cout << std::endl;
  } while(Status != EGuessStatus::OK); // keep looping until we get no errors
  return Guess;
};

bool AskToPlayAgain()
{
  std::cout << "Do you want to play again (y/n)?";
  FText Response = "";
  std::getline(std::cin, Response);
  return (Response[0] == 'y' || Response[0] == 'Y');
}
