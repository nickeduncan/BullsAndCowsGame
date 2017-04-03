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

#include <string>

using FString = std::string;
using int32 = int;

// all values initialized to zero
struct FBullCowCount
{
  int32 Bulls = 0;
  int32 Cows = 0;
};

class FBullCowGame
{
    public:
        FBullCowGame(); // constructor

        int32 GetMaxTries() const;
        int32 GetCurrentTry() const;
        bool IsGameWon() const;

        bool CheckGuessValidity(std::string); // TODO: make a more rich return value.
        void Reset(); // TODO: make a more rich return value.
        FBullCowCount SubmitGuess(FString Guess);


    // please try and ignore this and focus on the interface above ^^
    private:
        // see constructor for initiailization
        int32 MyCurrentTry;
        int32 MyMaxTries;
        FString MyHiddenWord;
};
