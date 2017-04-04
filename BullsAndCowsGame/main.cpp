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
  std::cout << "Can you guess what " << BCGame.GetHiddenWordLength();
  std::cout << " letter isogram I'm thinking of?\n";
  return;
}

void PlayGame()
{
  BCGame.Reset();
  int32 MaxTries = BCGame.GetMaxTries();
  std::cout << std::endl;

  for (int32 count = 1; count <= MaxTries; count++) // TODO: change from FOR to WHILE loop once we are validating tries
  {
    FText Guess = GetValidGuess();

    // submit valid guess to the game, and receive counts
    FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

    std::cout << "Bulls = " << BullCowCount.Bulls;
    std::cout << " Cows = " << BullCowCount.Cows << "\n\n";
  }

  // TODO: Add game summary
}

// loop continually until the user gives a valid guess
FText GetValidGuess()
{
  EGuessStatus Status = EGuessStatus::Invalid_Status;
  do
  {

    int32 CurrentTry = BCGame.GetCurrentTry();
    std::cout << "Try " << CurrentTry << ". Enter your guess: ";
    FText Guess = "";
    std::getline(std::cin, Guess);

    Status = BCGame.CheckGuessValidity(Guess);
    switch (Status)
    {
      case EGuessStatus::Wrong_Length:
        std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
        break;
      case EGuessStatus::Not_Isogram:
        std::cout << "Please enter an isogram.\n";
        break;
      case EGuessStatus::Not_Lowercase:
        std::cout << "Please use lowercase letters." << '\n';
        break;
      default:
        return Guess;
    }
    std::cout << std::endl;
  } while(Status != EGuessStatus::OK); // keep looping until we get no errors
};

bool AskToPlayAgain()
{
  std::cout << "Do you want to play again (y/n)?";
  FText Response = "";
  std::getline(std::cin, Response);
  return (Response[0] == 'y' || Response[0] == 'Y');
}
