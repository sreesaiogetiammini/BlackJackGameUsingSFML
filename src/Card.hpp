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
#include <SFML/Graphics.hpp>

class Card {
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
    
    
    void drawCard(){
        
        sf::RectangleShape endRect;
        sf::Vector2f endRectPosition(1400,970);
        endRect.setPosition(endRectPosition);
        endRect.setOutlineThickness(6);
        endRect.setSize(sf::Vector2f(220,75));
        endRect.setFillColor(sf::Color :: Black);

        
        sf::Font introFont;
        if(!introFont.loadFromFile("Fonts/IntroFont.otf")){
            
        }
        
        sf::Text headingText;
        headingText.setPosition(sf::Vector2f(800,100));
        headingText.setFont(introFont);
        headingText.setString("BlackJack");
        headingText.setColor(sf::Color(145,0,0));
        headingText.setCharacterSize(400);
        headingText.Italic;
    }
    
    
};

// TODO: A last, compare suits
bool compareCard(Card& a, Card& b);

#endif /* Card_hpp */
