//
//  FBullCowGame.cpp
//  BullsAndCowsGame
//
//  Created by Nicholas Duncan on 4/2/17.
//  Copyright © 2017 Nicholas Duncan. All rights reserved.
//

#include "FBullCowGame.hpp"

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const{ return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 8;
    const FString HIDDEN_WORD = "planet";

    MyMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = 1;
    return;
}

bool FBullCowGame::IsGameWon() const
{
return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
  if (false) // if the guess isn't an isogram
  {
    return EGuessStatus::Not_Isogram;
  }
  else if (false) // if the guess isn't all lowercase
  {
    return EGuessStatus::Not_Lowercase;
  }
  else if (Guess.length() != GetHiddenWordLength()) // if the guess length is wrong
  {
    return EGuessStatus::Wrong_Length;
  }
  else
  {
    return EGuessStatus::OK;
  }
}

// receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
  // increment the turn number
  MyCurrentTry++;

  // setup a return variable
  FBullCowCount BullCowCount;
  // loop through all letters in the guess
  int32 HiddenWordLength = MyHiddenWord.length();
  for (int32 GChar = 0; GChar < HiddenWordLength; GChar++)
  {
    // compare letters against the hidden word
    for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
    {
      // if they match then
      if (Guess[GChar] == MyHiddenWord[MHWChar])
      {
        if (MHWChar == GChar)
        { // if they're in the place
          BullCowCount.Bulls++; // increment bulls
        }
        else {
          BullCowCount.Cows++; // must be a cow
        }
      }
    }
  }
  return BullCowCount;
}
