//
//  DealerHand.hpp
//  FinalProject
//
//  Created by Yue Sun on 9/22/22.
//

#ifndef DealerHand_hpp
#define DealerHand_hpp

#include <vector>
#include <map>
#include "Card.hpp"

class DealerHand {
private:
    std::vector<Card> cards_;
    unsigned short score_;
    bool visible;
    
    unsigned short calculateScore() {
        std::map<std::string, int> rankToValue = {
            {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5},
            {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9}, {"10", 10},
            {"J", 10}, {"Q", 10}, {"K", 10}, {"A", 0}
        };
        int score = 0, numA = 0;
        for (Card card : cards_) {
            score += rankToValue[card.getRank()];
            if (card.getRank() == "A") {
                numA += 1;
            }
        }
        if (numA == 0) {
            return score;
        }
        score += numA;
        for (int i = 0; i < numA + 1; i++) {
            score += 10;
            if (score == 21) {
                return score;
            } else if (score > 21) {
                return score - 10;
            }
        }
    }
    
    void updateScore() {
        score_ = calculateScore();
    }
    
public:
    DealerHand(){
        visible = false;
        score_ = 0;
    };
    
    std::vector<Card> getCards() const {
        return cards_;
    }
    
    unsigned short getScore() const {
        return score_;
    }
    
    Card get(unsigned short i) const {
        return cards_[i];
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
        updateScore();
    }
    
    void printHand() {
        for (Card card : cards_) {
            card.printCard();
        }
        std::cout << std::endl;
    }
    
    // make all cards visible and then sort them
    void revealHand() {
        for (Card& card : cards_) {
            card.setVisible(true);
        }
    }
};

#endif /* DealerHand_hpp */
