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

FBullCowGame BCGame = FBullCowGame(6); // instantiate a new game

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
  std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
  std::cout << std::endl;
  std::cout << "          }   {         ___ " << std::endl;
  std::cout << "          (o o)        (o o) " << std::endl;
  std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
  std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
  std::cout << " *  |-,--- |              |------|  * " << std::endl;
  std::cout << "    ^      ^              ^      ^ " << std::endl;
  std::cout << std::endl; std::cout << "A Bull is the right letter in the right place." << '\n';
  std::cout << "\t A Cow is the right letter in the wrong place.\n\n";
  std::cout << "Can you guess what isogram (word with no repeating letters) I'm thinking of?\n\n";
  return;
}

inline bool isInteger(const FString & s)
{
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

    char * p;
    strtol(s.c_str(), &p, 10);

    return (*p == 0);
}

int GetDesiredWordLength()
{
    int minLength = 3;
    int maxLength = 6;
    int WordLength = 5;
    const int32 maxInvalidTries = 10;
    std::cout << "How long would you like the mystery word to be? Enter a number between " << minLength << " and " << maxLength << ":\n";
    int Attempts = 0;
    while (Attempts < maxInvalidTries) {
        FText input;
        std::getline(std::cin, input);
        std::cout << std::endl;
        if (!isInteger(input)) {
            std::cout << "\n could not convert input into a whole number, please try again\n";
        }else{
            char *p;
            long i = strtol(input.c_str(), &p, 10);
            if (i < minLength || i > maxLength) {
                std::cout << "\n number was not between " << minLength << " and " << maxLength << ", please try again\n";
            }else {
                WordLength = i;
                break;
            }
        }
        Attempts++;
    }
    return WordLength;
}

void PlayGame()
{
  int wordLength = GetDesiredWordLength();
  BCGame.Reset(wordLength);
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
    std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
    std::cout << ". Enter your guess: ";
    std::getline(std::cin, Guess);

    Status = BCGame.CheckGuessValidity(Guess);
    switch (Status)
    {
      case EGuessStatus::Wrong_Length:
        std::cout << "Please enter a " << BCGame.GetWordLength() << " letter word.\n\n";
        break;
      case EGuessStatus::Not_Isogram:
        std::cout << "Please enter a word without repeating letters.\n\n";
        break;
      case EGuessStatus::Not_Lowercase:
        std::cout << "Please use lowercase letters.\n\n";
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
      std::cout << "The word was " << BCGame.MyHiddenWord << '\n\n';
  }
}

bool AskToPlayAgain()
{
  std::cout << "Do you want to play again (y/n)?";
  FText Response = "";
  std::getline(std::cin, Response);
  return (Response[0] == 'y' || Response[0] == 'Y');
}
