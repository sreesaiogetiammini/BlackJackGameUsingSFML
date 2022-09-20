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

class PlayerHand {
protected:
    // all cards visible
    std::vector<Card> cards_;
    
public:
    PlayerHand(){};
    
    std::vector<Card> getCards() const {
        return cards_;
    }
    
    // Sort hand in ascending order
    void sortHand() {
        sort(cards_.begin(), cards_.end(), compareCard);
    }
    
    void addCard(Card& card) {
        cards_.push_back(card);
    }
    
    void printHand() {
        for (Card card : cards_) {
            card.printCard();
        }
        std::cout << std::endl;
    }
};

class DealerHand : public PlayerHand {
private:
    bool visible;
    
public:
    DealerHand():PlayerHand() { // call parent class's constructor
        visible = false;
    }
    
    /*
     Add a card to the dealer. The first card should be invisible.
     If visible = true, then all cards are visible.
     */
    void addCard(Card& card) {
        if (!visible && cards_.size() > 0) {
            card.setVisible(false);
        }
        cards_.push_back(card);
    }
    
    // make all cards visible and then sort them
    void revealHand() {
        for (Card card : cards_) {
            card.setVisible(true);
        }
        sortHand();
    }
};


#endif /* Hand_hpp */
