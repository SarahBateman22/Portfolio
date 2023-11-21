//
//  PokerFunctions.cpp
//  Poker
//
//  Created by Sarah Bateman on 8/30/23.
//

#include "PokerFunctions.hpp"
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


//create a function to stack for loops to assign ranks and suits
//to all 52 cards. Create a new vector to hold all of the cards.
//Return that new vector
std::vector<cards> deckOfCards(std::vector<int> suit,std::vector<int> rank){
    std::vector<cards> deckOfCards;
    for(int s = 0; s < suit.size(); s++){
        for(int r = 0; r < rank.size(); r++){
            cards c = {suit[s], rank[r]};
            deckOfCards.push_back(c);
        }
    }
    return deckOfCards;
}

//create a function to print the deck of cards with special
//characters changed (11,12,13,14)
void printDeck(std::vector <cards> deckOfCards){
    for (cards c: deckOfCards){
        
        else if(c.rank == 1){
            std::cout << "Ace";
        }
        
        if(c.rank == 11){
            std::cout << "Jack";
        }
        
        else if(c.rank == 12){
            std::cout << "Queen";
        }
        
        else if(c.rank == 13){
            std::cout << "King";
        }
        
        else if(c.rank == 14){
            std::cout << "Ace";
        }
        
        else{
            std::cout << c.rank;
        }
        
        std::cout << " of ";
        
        
        if(c.suit == 1){
            std::cout << "Spades\n";
        }
        
        else if(c.suit == 2){
            std::cout << "Hearts\n";
        }
        
        else if(c.suit == 3){
            std::cout << "Diamonds\n";
        }
       
        else if(c.suit == 4){
            std::cout << "Clubs\n";
        }
        
        else{
            std::cout << c.suit << "\n";
        }
    }
}

//function to shuffle the deck by rearranging the order of the
//52 cards
void shuffledDeck(std::vector<cards> &deckOfCards){
    srand(time(0));
    for(int i=0; i<51; i++){
        int j = std::rand() %52;
        cards tmp;
        tmp = deckOfCards[i];
        deckOfCards[i] = deckOfCards[j];
        deckOfCards[j] = tmp;
    }
}

//make a for each loop that prints the first five cards in a
//shuffled hand

std::vector<cards> dealFiveCards (std::vector<cards> deckOfCards){
    std::vector<cards> fiveCards;
    fiveCards.push_back(deckOfCards[0]);
    fiveCards.push_back(deckOfCards[1]);
    fiveCards.push_back(deckOfCards[2]);
    fiveCards.push_back(deckOfCards[3]);
    fiveCards.push_back(deckOfCards[4]);
    return fiveCards;
}

//a flush is when all the cards are the same suit. create a
//boolean to determine if that is the case or not
bool isFlush(std::vector<cards> fiveCards){
    return (fiveCards[0].suit == fiveCards[1].suit && fiveCards[1].suit == fiveCards[2].suit && fiveCards[2].suit == fiveCards[3].suit && fiveCards[3].suit == fiveCards[4].suit);
        }

//create a function to see if the hand is a straight
//What if I seperated it all out into a seperate vector
std::vector<int> dealtHandRanks (std::vector<cards> fiveCards){
    std::vector<int> cardsRanks;
    for(int i = 0; i < 5; i++){
        int rank = fiveCards[i].rank;
        cardsRanks.push_back(rank);
    }
    return cardsRanks;
}

bool isStraight (std::vector<int> sortedCards){
    for(int a = 0; a < sortedCards.size()-1; a++){
        if(sortedCards[a+1] != sortedCards[a] + 1){
            return false;
        }
    }
    return true;
    }

//combine the previous two functions to make isStraightFlush
bool isStraightFlush (std::vector<cards> FiveCards, std::vector<int> sortedCardRanks){
    return(isFlush(FiveCards) && isStraight(sortedCardRanks));
}

//use isStraightFlush and front of the sorted ranks vector to
//see if the lowest card is a 10 which makes it a royal flush
bool isRoyalFlush(std::vector<cards> FiveCards, std::vector<int> sortedCardRanks){
    return (isStraightFlush(FiveCards, sortedCardRanks) && sortedCardRanks.front() == 10);
}

//compare the first two and last two cards in the sorted deck
//also compare the middle card to see if it's the same as either
//side
bool isFullHouse (std::vector<int> sortedCardRanks){
    // Sort here
    return (sortedCardRanks[0] == sortedCardRanks[1] && sortedCardRanks[4] == sortedCardRanks[3] && (sortedCardRanks[2] == sortedCardRanks[1] || sortedCardRanks[2] == sortedCardRanks[3]));
}
