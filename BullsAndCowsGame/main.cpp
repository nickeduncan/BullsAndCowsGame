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
void PrintGameSummary();
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
  std::cout << "\n\nWelcome to Bulls and Cows, a fun word game.\n";
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
  while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
  {
    FText Guess = GetValidGuess();

    // submit valid guess to the game, and receive counts
    FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

    std::cout << "Bulls = " << BullCowCount.Bulls;
    std::cout << " Cows = " << BullCowCount.Cows << "\n\n";
  }
  PrintGameSummary();
  return;
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
        std::cout << "Please enter a " << BCGame.GetWordLength() << " letter word.\n\n";
        break;
      case EGuessStatus::Not_Isogram:
        std::cout << "Please enter a word without repeat letters.\n\n";
        break;
      case EGuessStatus::Not_Lowercase:
        std::cout << "Please use lowercase letters." << '\n\n';
        break;
      default:
        // assume the guess is valid
        break;
    }
  } while(Status != EGuessStatus::OK); // keep looping until we get no errors
  return Guess;
};

void PrintGameSummary()
{
  if (BCGame.IsGameWon())
  {
    std::cout << "Great job! You won!" << '\n';
  }
  else
  {
    std::cout << "Sorry, you ran out of turns..." << '\n';
  }
}

bool AskToPlayAgain()
{
  std::cout << "Do you want to play again with the same hidden word (y/n)?";
  FText Response = "";
  std::getline(std::cin, Response);
  return (Response[0] == 'y' || Response[0] == 'Y');
}
