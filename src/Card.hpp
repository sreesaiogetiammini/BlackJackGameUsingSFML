//
//  Card.hpp
//  FinalProject
//
//  Created by Yue Sun on 9/19/22.
//

#ifndef Card_hpp
#define Card_hpp

#include <string>
#include <iostream>

class Card{
private:
    std::string rank_;
    std::string suit_;
    bool visible_;
  
    
    
public:
    Card(std::string rank, std::string suit) {
        rank_ = rank;
        suit_ = suit;
        visible_ = true;
    }
    
    std::string getRank() const {
        return rank_;
    }
    
    std::string getSuit() const {
        return suit_;
    }
    
    bool getVisible() const {
        return visible_;
    }
    
    void setVisible(bool visible) {
        visible_ = visible;
    }
    
    void printCard() {
        std::string suit;
        if (suit_ == "spades") {
            suit = "♠︎";
        } else if (suit_ == "hearts") {
            suit = "♥︎";
        } else if (suit_ == "clubs") {
            suit = "♣︎";
        } else if (suit_ == "diamonds") {
            suit = "♦︎";
        }
        std::cout << "(" << rank_ << ", " << suit << ") " ;
        //std::cout << "____\n" << "|" << rank_ << "  |\n" << "| " << suit << " |\n" << "|__" << rank_ << "|\n" ;
    }
    
};

// TODO: A last, compare suits
bool compareCard(Card& a, Card& b);

#endif /* Card_hpp */
