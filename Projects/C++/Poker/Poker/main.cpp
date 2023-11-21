//
//  main.cpp
//  Poker
//
//  Created by Sarah Bateman on 8/30/23.
//  Partnered with Corinne Jones and
//  Lindsay Haslam

#include <iostream>
#include "PokerFunctions.hpp"
#include <cstdlib>
#include <algorithm>

//it took me 34 shuffles to just get a full house. That means
//there was a 2.9% chance of being dealt a full house 

int main(int argc, const char * argv[]) {
        
    //create one vector with the suits of a deck of cards
    std::vector<int> suit {
        1, 2, 3, 4
    };
    //create another vector with the ranks
    std::vector<int> rank {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13
    };
    
    //use the function to create a variable that is storing the
    //completed deck of cards
    std::vector<cards> deck = deckOfCards(suit, rank);
    
    //create the shuffled deck
    shuffledDeck(deck);
    
    //print a hand of five cards
    std::vector<cards> firstFive = dealFiveCards(deck);
        
    std::cout << "Hand of cards:\n";
    printDeck(firstFive);
    std::cout << "\nAnalysis:\n";
        
    //print if the hand is a flush or not
    if(isFlush(firstFive)){
        std::cout << "This hand is a flush!\n";
    }
    else{
        std::cout << "This hand is not a flush.\n";
    }
        
    //create a new vector that ONLY holds the rank
    std::vector<int> sortedHandofCards = dealtHandRanks(firstFive);
        
    //sort min to max
    std::sort(sortedHandofCards.begin(), sortedHandofCards.end());
        
        
    //use function isStraight to test the hand
    if(isStraight(sortedHandofCards)){
        std::cout << "This hand is a straight!\n";
    }
    else{
        std::cout << "This hand is not a straight.\n";
    }
        
    //is the hand a straight flush
    if(isStraightFlush(firstFive, sortedHandofCards)){
        std::cout << "This hand is a straight flush!\n";
    }
    else{
        std::cout << "This hand is not a straight flush.\n";
    }
        
    if(isRoyalFlush(firstFive, sortedHandofCards)){
        std::cout << "This hand is a royal flush!\n";
    }
    else{
        std::cout << "This hand is not a royal flush.\n";
    }
    
        
    //is the hand a full house?
    if(isFullHouse(sortedHandofCards)){
        std::cout << "This hand is a full house!\n";
    }
    else{
        std::cout << "This hand is not a full house.\n";
    }
        
    //TESTS!!!!
    std::cout << "\nTests:\n";
        
    //is the hand a flush? Need to make a practice vector that is one
    cards f1 {1, 4};
    cards f2 {1, 2};
    cards f3 {1, 14};
    cards f4 {1, 9};
    cards f5 {1, 2};
        
    std::vector<cards> isAFlush {f1, f2, f3, f4, f5};
    
    if(isFlush(isAFlush)){
        std::cout << "Flush test passed!\n";
    }
    else{
        std::cout << "Flush test failed.\n";
    }
    
    //testing to see if IsStraight works correctly for a hand that
    //is straight in ascending order (which is forced with
    //how I sort)
    std::vector<int> isAStraight {10, 11, 12, 13, 14};
        
    if(isStraight(isAStraight)){
        std::cout << "Straight test passed!\n";
    }
    else{
        std::cout << "Straight test failed.\n";
    }
        
    //test for a positive straight flush
    if(isStraightFlush(isAFlush, isAStraight)){
        std::cout << "Straight flush test passed!\n";
    }
    else{
        std::cout << "Straight flush test failed.\n";
    }
        
    //tests for a positive royal flush
    if(isRoyalFlush(isAFlush, isAStraight)){
        std::cout << "Royal flush test passed\n";
    }
    else{
        std::cout << "Royal flush test failed.\n";
    }
        
        
    //tests for a positive full house
    std::vector<int> FullHouseExample {1, 1, 2, 2, 2};
    
    if(isFullHouse(FullHouseExample)){
        std::cout << "Full house test.1 passed!\n";
    }
    else{
        std::cout << "Full house test.1 failed.\n";
    }
        
    std::vector<int> FullHouseExamp2 {7, 7, 7, 14, 14};
        
    if(isFullHouse(FullHouseExamp2)){
        std::cout << "Full house test.2 passed!\n";
    }
    else{
        std::cout << "Full house test.2 failed.\n";
    }
return 0;
}






