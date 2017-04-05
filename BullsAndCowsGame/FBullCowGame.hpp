//
//  FBullCowGame.hpp
//  BullsAndCowsGame
//
//  Created by Nicholas Duncan on 4/2/17.
//  Copyright © 2017 Nicholas Duncan. All rights reserved.
//

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <stdio.h>

#endif /* FBullCowGame_hpp */

/* The game logic (no view code or direct user interaciton)
The game is a simple guess the word game based on mastermind */

#pragma once
#include <string>

// to make syntax Unreal friendly
using FString = std::string;
using int32 = int;

struct FBullCowCount
{
  int32 Bulls = 0;
  int32 Cows = 0;
};

enum class EGuessStatus
{
  Invalid_Status,
  OK,
  Not_Isogram,
  Wrong_Length,
  Not_Lowercase
};


class FBullCowGame
{
  public:
    FBullCowGame(); // constructor

    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetWordLength() const;
    bool IsGameWon() const;

    EGuessStatus CheckGuessValidity(FString) const;

    void Reset();
    FBullCowCount SubmitValidGuess(FString);


  // please try and ignore this and focus on the interface above ^^
  private:
    // see constructor for initiailization
    int32 MyCurrentTry;
    FString MyHiddenWord;
    bool bGameIsWon;

    bool IsIsogram(FString) const;
    bool IsLowerCase(FString) const;
};
