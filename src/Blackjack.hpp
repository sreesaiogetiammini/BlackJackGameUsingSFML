//
//  BlackJack.h
//  FinalProject
//
//  Created by Yue Sun on 9/19/22.
//

#ifndef BlackJack_h
#define BlackJack_h

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Card.hpp"
#include "Deck.hpp"
#include "PlayerHand.hpp"
#include "DealerHand.hpp"


class Blackjack {
private:
    Deck deck_;
//    int wallet_;
//    int bet_;
    
public:
    Blackjack() {
        deck_ = Deck();
//        wallet_ = 20;
//        round = 0;
    }
    
    Deck getDeck() {
        return deck_;
    }
    
    // play the game
    void deal2Cards(PlayerHand& player, DealerHand& dealer) {
        deck_.shuffle();
        // Alternate dealing cards between the player and dealer
        for (int i = 0; i < 2; i++) {
            deck_.dealPlayer(player);
            deck_.dealDealer(dealer);
        }
    }
    
    void hitPlayer(PlayerHand& hand) {
        deck_.dealPlayer(hand);
    }
    
    void hitDealer(DealerHand& hand) {
        while (hand.getScore() < 17) {
            deck_.dealDealer(hand);
        }
    }
    
    // return 0 if push, return 1 if player wins, return -1 if player lose
    short determineWinner(unsigned short playerScore, unsigned short dealerScore) {
        if (playerScore > 21) {
            return -1;
        } else if (dealerScore > 21) {
            return 1;
        } else if (playerScore == dealerScore) {
            return 0;
        } else if (playerScore < dealerScore) {
            return -1;
        } else {
            return 1;
        }
    }
};


#endif /* BlackJack_h */

