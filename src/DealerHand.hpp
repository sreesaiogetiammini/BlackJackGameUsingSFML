//
//  DealerHand.hpp
//  FinalProject
//
//  Created by Yue Sun on 9/22/22.
//

#ifndef DealerHand_hpp
#define DealerHand_hpp

#include <vector>
#include "Card.hpp"

class DealerHand {
private:
    std::vector<Card> cards_;
    unsigned short score_;
    bool visible;
    
public:
    DealerHand(){
        visible = false;
    };
    
    std::vector<Card> getCards() const {
        return cards_;
    }
    
    unsigned short getScore() const {
        return score_;
    }
    
    /*
     Add a card to the dealer. The first card should be invisible.
     If visible = true, then all cards are visible.
     */
    void addCard(Card& card) {
        if (!visible && cards_.size() == 0) {
            card.setVisible(false);
        }
        cards_.push_back(card);
    }
    
    void printHand() {
        for (Card card : cards_) {
            card.printCard();
        }
        std::cout << std::endl;
    }
    
    void setScore(unsigned short score) {
        score_ = score;
    }
    
    // make all cards visible and then sort them
    void revealHand() {
        for (Card& card : cards_) {
            card.setVisible(true);
        }
    }
};

#endif /* DealerHand_hpp */
