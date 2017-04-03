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

class FBullCowGame {
    public:
        FBullCowGame(); // constructor

        int32 GetMaxTries() const;
        int32 GetCurrentTry() const;
        bool IsGameWon() const;

        bool CheckGuessValidity(std::string); // TODO: make a more rich return value.
        void Reset(); // TODO: make a more rich return value.
        // provide a method for counting bulls and cows, and increasing try #



    // please try and ignore this and focus on the interface above ^^
    private:
        // see constructor for initiailization
        int32 MyCurrentTry;
        int32 MyMaxTries;
};