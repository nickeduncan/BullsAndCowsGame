//
//  FBullCowGame.cpp
//  BullsAndCowsGame
//
//  Created by Nicholas Duncan on 4/2/17.
//  Copyright © 2017 Nicholas Duncan. All rights reserved.
//

#include "FBullCowGame.hpp"
#include <map>
#define TMap std::map

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); } // defaut constructor

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

void FBullCowGame::Reset()
{
  constexpr int32 MAX_TRIES = 8;
  const FString HIDDEN_WORD = "planet";

  MyMaxTries = MAX_TRIES;
  MyHiddenWord = HIDDEN_WORD;
  MyCurrentTry = 1;
  bGameIsWon = false;
  return;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
  if (!IsIsogram(Guess)) // if the guess isn't an isogram
  {
    return EGuessStatus::Not_Isogram; // TODO:write function
  }
  else if (!IsLowerCase(Guess)) // if the guess isn't all lowercase
  {
    return EGuessStatus::Not_Lowercase; // TODO: write function
  }
  else if (Guess.length() != GetWordLength()) // if the guess length is wrong
  {
    return EGuessStatus::Wrong_Length;
  }
  else
  {
    return EGuessStatus::OK;
  }
}

// receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
  MyCurrentTry++;
  FBullCowCount BullCowCount;

  // loop through all letters in the hidden word
  int32 WordLength = MyHiddenWord.length(); // assuming same length as guess
  for (int32 GChar = 0; GChar < WordLength; GChar++)
  {
    // compare letters against the guess
    for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
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
  if (BullCowCount.Bulls == WordLength)
  {
    bGameIsWon = true;
  }
  else
  {
    bGameIsWon = false;
  }
  return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
  // treat 0 and 1 letter words as isograms
  if (Word.length() <= 1) { return true; }

  TMap<char, bool> LetterSeen; // setup our map
  for (auto Letter : Word) // for all letters of the word
  {
    Letter = tolower(Letter); // handle mixed case
      if (LetterSeen[Letter]) {// if letter has been seen
        return false; // reject guess
      } else {
        LetterSeen[Letter] = true; // add the letter to the map as seen
      }
  }
  return true; // for example in cases where /0 is entered
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
  if (Word.length() <= 1) { return true; }

  for (auto Letter : Word)
  {
    if (!islower(Letter)) // if not a lowercase letter
    {
      return false;
    }
  }
  return true;
}
