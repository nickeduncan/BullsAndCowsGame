//
//  FBullCowGame.cpp
//  BullsAndCowsGame
//
//  Created by Nicholas Duncan on 4/2/17.
//  Copyright © 2017 Nicholas Duncan. All rights reserved.
//

#include "FBullCowGame.hpp"

using int32 = int;

FBullCowGame::FBullCowGame() {
    Reset();
}

int32 FBullCowGame::GetMaxTries() const {return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset() {

    constexpr int32 MAX_TRIES = 8;
    MyMaxTries = MAX_TRIES;

    MyCurrentTry = 1;
    return;
}

bool FBullCowGame::IsGameWon() const {
return false;
}

bool FBullCowGame::CheckGuessValidity(std::string) {
    return false;
}
