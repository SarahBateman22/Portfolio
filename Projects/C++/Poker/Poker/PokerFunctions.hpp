//
//  PokerFunctions.hpp
//  Poker
//
//  Created by Sarah Bateman on 8/30/23.
//

#ifndef PokerFunctions_hpp
#define PokerFunctions_hpp

#include <stdio.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>

#endif /* PokerFunctions_hpp */

struct cards {
    int suit;
    int rank;
};

std::vector<cards> deckOfCards(std::vector<int> suit,std::vector<int> rank);

void printDeck(std::vector <cards> deckOfCards);

void shuffledDeck(std::vector<cards> &deckOfCards);

std::vector<cards> dealFiveCards (std::vector<cards> deckOfCards);

bool isFlush(std::vector<cards> fiveCards);

std::vector<int> dealtHandRanks (std::vector<cards> fiveCards);

bool isStraight (std::vector<int> sortedCards);

bool isStraightFlush (std::vector<cards> FiveCards, std::vector<int> sortedCardRanks);

bool isRoyalFlush(std::vector<cards> FiveCards, std::vector<int> sortedCardRanks);

bool isFullHouse (std::vector<int> sortedCardRanks);

