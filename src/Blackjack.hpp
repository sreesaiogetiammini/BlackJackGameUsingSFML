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
    int wallet_;
    int bet_;
//    unsigned int round;
//    unsigned long gameNumber; // an auto-increment unique id for a Blackjack object
    
public:
    Blackjack() {
        deck_ = Deck();
        wallet_ = 20;
//        round = 0;
    }
    
    // play the game
    void deal2Cards(PlayerHand& player, DealerHand& dealer) {
        deck_.shuffle();
        // Alternate dealing cards between the player and dealer
        for (int i = 0; i < 2; i++) {
            deck_.dealPlayer(player);
            player.setScore(calculateScore(player.getCards()));
            deck_.dealDealer(dealer);
            dealer.setScore(calculateScore(dealer.getCards()));
        }
    }
    
    void hitPlayer(PlayerHand& hand) {
        deck_.dealPlayer(hand);
        hand.setScore(calculateScore(hand.getCards()));
    }
    
    void hitDealer(DealerHand& hand) {
        while (hand.getScore() < 17) {
            deck_.dealDealer(hand);
            hand.setScore(calculateScore(hand.getCards()));
        }
    }
    
    unsigned short calculateScore(std::vector<Card> cards) {
        std::map<std::string, int> rankToValue = {
            {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5},
            {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9}, {"10", 10},
            {"J", 10}, {"Q", 10}, {"K", 10}, {"A", 0}
        };
        int score = 0, numA = 0;
        for (Card card : cards) {
            score += rankToValue[card.getRank()];
            if (card.getRank() == "A") {
                numA += 1;
            }
        }
        if (numA == 0) {
            return score;
        }
        score += numA;
        std::vector<int> scores;
        scores.push_back(score);
        for (int i = 0; i < numA; i++) {
            score += 10;
            scores.push_back(score);
        }
        for (int i = 0; i < numA + 1; i++) {
            if (scores[i] > 21) {
                if (i == 0) {
                    return scores[0];
                } else {
                    return scores[i - 1];
                }
            } else if (scores[i] == 21) {
                return 21;
            }
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

