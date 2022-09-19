//
//  Deck.hpp
//  FinalProject
//
//  Created by Yue Sun on 9/19/22.
//

#ifndef Deck_hpp
#define Deck_hpp

#include <vector>
#include <string>
#include "Card.hpp"
#include "Hand.hpp"

class Deck {
private:
    std::vector<Card> cards;
    
public:
    Deck() {
        std::vector<std::string> suits = {"spade", "heart", "club", "diamond"};
        for (int i = 1; i < 14; i++) {
            for (int j = 0; j < 4; j++) {
                cards.push_back(Card(i, suits[j], false));
            }
        }
    }
    
    std::vector<Card> getCards() const {
        return cards;
    }

    // remove the 1st card form deck and add it to the hand
    void dealHand(Hand& hand);
    
    void shuffle();
    
};

#endif /* Deck_hpp */
