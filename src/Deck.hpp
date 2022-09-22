//
//  Deck.hpp
//  FinalProject
//
//  Created by Yue Sun on 9/19/22.
//

#ifndef Deck_hpp
#define Deck_hpp

#include <vector>
#include <string>
#include "Card.hpp"
#include "PlayerHand.hpp"

class Deck {
private:
    std::vector<Card> cards_;
    
    void swap(int i, int j) {
        Card temp  = cards_[i];
        cards_[i] = cards_[j];
        cards_[j] = temp;
    }
    
public:
    Deck() {
        std::vector<std::string> suits = {"spades", "hearts", "clubs", "diamonds"};
        std::vector<std::string> ranks = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
        for (std::string suit: suits) {
            for (std::string rank : ranks) {
                cards_.push_back(Card(rank, suit));
            }
        }
    }
    
    std::vector<Card> getCards() const {
        return cards_;
    }

    // remove the 1st card form deck and add it to the hand
    void dealHand(PlayerHand& hand) {
        hand.addCard(cards_.front());
        cards_.erase(cards_.begin());
    }

    // TODO: improve shuffle methods
    void shuffle() {
        srand(time(0));
        int j;
        for (int i = cards_.size() - 1; i >= 1; i--) {
            j = rand() % i;
            swap(i, j);
        }
    }
    
    void printDeck() {
        for (Card card : cards_) {
            card.printCard();
        }
        std::cout << std::endl;
    }
    
};

#endif /* Deck_hpp */
