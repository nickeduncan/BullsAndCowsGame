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

class FBullCowGame {
    public:
        FBullCowGame(); // constructor
    
        int GetMaxTries() const;
        int GetCurrentTry() const;
        bool IsGameWon() const;
    
        bool CheckGuessValidity(std::string);
        void Reset(); // TODO: make a more rich return value.
        
        
        
    // please try and ignore this and focus on the interface above ^^
    private:
        // see constructor for initiailization
        int MyCurrentTry;
        int MyMaxTries;
};
