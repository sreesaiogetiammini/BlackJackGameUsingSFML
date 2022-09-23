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
    std::vector<Card> cards_; // all cards visible
    unsigned short score_;
    
public:
    PlayerHand(){};
    
    std::vector<Card> getCards() const {
        return cards_;
    }
    
    unsigned short getScore() const {
        return score_;
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
    
    void setScore(unsigned short score) {
        score_ = score;
    }
};

#endif /* Hand_hpp */
