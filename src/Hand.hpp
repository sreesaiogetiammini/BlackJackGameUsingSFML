//
//  Hand.hpp
//  FinalProject
//
//  Created by Yue Sun on 9/19/22.
//

#ifndef Hand_hpp
#define Hand_hpp

#include <vector>
#include "Card.hpp"

class Hand {
private:
    // playerhand: all cards visible
    std::vector<Card> cards;
    
public:
    Hand(){};
    
    std::vector<Card> getCards() const {
        return cards;
    }
    
    void sortHand() {
        sort(cards.begin(), cards.end(), compareCard);
    }
    
    // TODO: add cards then sort them
    void addCards(Card* cards);
};

class Dealer : public Hand {
private:
    bool visible;
public:
    Dealer():Hand() { // call parent class's constructor
        visible = false;
        // TODO: the first card is not visible
    }
    
    // TODO: add cards unsortedly
    void addCards(Card* cards);
    
    // TODO: make all cards visible and then sorted them
    void revealHand();
    
}

#endif /* Hand_hpp */
