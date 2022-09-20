//
//  BlackJack.h
//  FinalProject
//
//  Created by Yue Sun on 9/19/22.
//

#ifndef BlackJack_h
#define BlackJack_h

#include <iostream>

#include "Deck.hpp"
#include "Hand.hpp"


class Backjack {
private:
    Deck deck;
    double wallet;
    unsigned int round;
//    unsigned long gameNumber; // an auto-increment unique id for a Blackjack object
    
public:
    BlackJack(double money) {
        deck = Deck();
        wallet = money;
        round = 0;
    }
    
    unsigned short calculateScore(const Hand& hand);
    
    // dealer must stand if they receive a score of 17 or higher
    void HitOrStand(Hand& hand); // need to interact with user
    
    void determineWinner(unsigned short playerScore, unsigned short dealerScore) {
        if (playSore > 21) {
            std::cout << "Dealer wins.\n";
        } else if (dealerScore > 21) {
            std::cout << "Player wins. \n";
        } else if (playerScore == dealerScore) {
            std::cout << "Push.\n";
        } else if (playerScore < dealerScore) {
            std::cout << "Dealer wins.\n";
        } else {
            std::cout << "Player wins. \n";
        }
    }
    
    // play the game
    void play() {
        
    };
}


#endif /* BlackJack_h */
