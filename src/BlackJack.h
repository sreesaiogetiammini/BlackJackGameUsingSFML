//
//  BlackJack.h
//  FinalProject
//
//  Created by Yue Sun on 9/19/22.
//

#ifndef BlackJack_h
#define BlackJack_h

#include "Deck.hpp"
#include "Hand.hpp"


class Backjack {
private:
    Deck deck;
    double wallet;
//    unsigned long gameNumber; // an auto-increment unique id for a Blackjack object
    
public:
    BlackJack(double money) {
        deck = Deck();
        wallet = money;
    }
    
    unsigned short calculateScore(const Hand& hand);
    void HitOrStand(Hand& hand);
    void determineWinner(unsigned short playerScore, unsigned short dealerScore);
    void playRound(); // paly the game, for now I am not sure about the parameters
}


#endif /* BlackJack_h */
