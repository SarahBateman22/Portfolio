//
//  TrashedIdeas.cpp
//  Poker
//
//  Created by Sarah Bateman on 8/31/23.
//

#include <stdio.h>

//    sort max to min - not necessary if I force sort min-max
//    std::vector<int> handSortedMaxtoMin = dealtHandRanks(firstFive);
//    std::sort(handSortedMaxtoMin.begin(), handSortedMaxtoMin.end(), std::greater<int>());
    
//    test to see if it prints out right
//    for(int r: handSortedMaxtoMin){
//        std::cout << r << "\n";
//    }
    
    
//    if(isStraightAscending(handSortedMinToMax) || isStraightDescending(handSortedMaxtoMin)
//       ){
//        std::cout << "This hand is a straight!\n";
//    }
//    else{
//        std::cout << "This hand is NOT a straight.\n";
//    }


//TEST to see if it also works in descending order
//    std::vector<int> straightDescending {10, 9, 8, 7, 6};
//
//    if(isStraightDescending(straightDescending)){
//        std::cout << "Test straight.2 passed!\n";
//    }
//    else{
//        std::cout << "Test failed - straight descending\n";
//    }


//don't need this anymore because I'm always going to sort the hand
//min to max

//bool isStraightDescending (std::vector<int> sortedCards){
//    for(int a = sortedCards.size() - 1 ; a > 0; a--){
//        if(sortedCards[a] != sortedCards[a-1] - 1){
//            return false;
//        }
//    }
//    return true;
//}
    
//    for(int a = 1; a < sortedCards.size()-1; a++){
//        for(int b = 0; b < sortedCards.size()-2; b++){
//            if(sortedCards[a] != sortedCards[b] + 1){
//                return false;
//            }
//        }
//    }
//    return true;
//  }
    
    
    
    //    if(sortedCards[1] == sortedCards[0] + 1 && sortedCards[2] == sortedCards[1] + 1){
//        return true;
//    }
        
//        && sortedCards[2] == sortedCards[1] + 1 && sortedCards[3] == sortedCards[2] + 1 && sortedCards[4] == sortedCards[3] + 1 &&){


//std::vector<cards> findMaxCard (std::vector<cards> fiveCards){
//    for(int i=0; i<5; i++){
//        for(int a = 0; a < fiveCards.size(); a++){
//            for(int b = 1; b < fiveCards.size()-1; b++){
//                if(fiveCards[a].rank > fiveCards[b].rank){
//                    fiveCards.push_back(fiveCards[a]);
//                }
//            }
//        }
//    }
//    return fiveCards;
//}


//std::vector<cards> shuffledDeck(std::vector<cards> deckOfCards){
//    std::vector<cards> shuffledDeck;
//    for(int i=0; i<51; i++){
//        int j = std::rand() %52;
//        cards tmp;
//        tmp =shuffledDeck[i];
//        shuffledDeck[i] = shuffledDeck[j];
//        shuffledDeck[j] = tmp;
//    }
//}



//std::vector<cards> shuffledDeck(std::vector<int> suit,std::vector<int> rank){
//    std::vector<cards> shuffledDeck;
//    for(int i = 0; i < 52;){
//        for(int s = 0; s < suit.size(); s++){
//            for(int r = 0; r < rank.size(); r++){
//                cards c;
//                c.rank = std::rand() %13;
//                c.suit = std::rand() %4;
//                    for(cards previousCards: shuffledDeck){
//                        if(c.rank == previousCards.rank && c.suit == previousCards.suit){
//                                        //trash c and start the loop over
//                                }
//                        else {shuffledDeck.push_back(c);
//                                        i++;
//                                    }
//                                }
//            }
//        }
//    }
//    return shuffledDeck;
//}

//test to see if it prints out right
//    for(int r: sortedHandofCards){
//        std::cout << r << "\n";
//    }


//    std::cout <<"\n \n after shuffle: \n";
//    printDeck(deck);

//ask the user how many times they would like to shuffle
//        int numberOfShuffles;
//        std::cout << "How many times would you like to shuffle?\n";
//        std::cin >> numberOfShuffles;

//void shuffleTheDeck(std::vector<cards>& deckToShuffle, int numOfShuffles){
//    for(int a = 0; a < numOfShuffles; a++){
//        shuffledDeck(deckToShuffle);
//    }
//}

//void shuffleTheDeck(std::vector<cards>& deckToShuffle, int numOfShuffles);





