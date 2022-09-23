//
//  Hand.hpp
//  FinalProject
//
//  Created by Yue Sun on 9/19/22.
//

#ifndef Hand_hpp
#define Hand_hpp

#include <vector>
#include <map>
#include "Card.hpp"


class PlayerHand {
protected:
    std::vector<Card> cards_; // all cards visible
    unsigned short score_;
    
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
        for (int i = 0; i < numA; i++) {
            score += 10;
            if (score == 21) {
                return score;
            } else if (score > 21) {
                return score - 10;
            }
        }
        return score;
    }
    
    void updateScore() {
        score_ = calculateScore();
    }
    
public:
    PlayerHand(){
        score_ = 0;
    };
    
    std::vector<Card> getCards() const {
        return cards_;
    }
    
    Card get(unsigned short i) const {
        return cards_[i];
    }
    
    unsigned short getScore() const {
        return score_;
    }
    
    void addCard(Card& card) {
        cards_.push_back(card);
        updateScore();
    }
    
    void printHand() {
        for (Card card : cards_) {
            card.printCard();
        }
        std::cout << std::endl;
    }
};

#endif /* Hand_hpp */
