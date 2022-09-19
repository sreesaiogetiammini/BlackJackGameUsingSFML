//
//  Card.hpp
//  FinalProject
//
//  Created by Yue Sun on 9/19/22.
//

#ifndef Card_hpp
#define Card_hpp

#include <string>

class Card {
private:
    char rank_;
    std::string suit_;
    bool visible_;
    
public:
    Card(unsigned short rank, std::string suit, bool visible) {
        rank_ = rank;
        suit_ = suit;
        visible_ = visible;
    }
    
    unsigned short getRank() const {
        return rank_;
    }
    
    std::string getSuit() const {
        return suit_;
    }
    
    void setVisible(bool visible) {
        visible_ = visible;
    }
};

bool compareCard(Card& a, Card& b) {
    return a.getRank() < b.getRank();
}

#endif /* Card_hpp */
