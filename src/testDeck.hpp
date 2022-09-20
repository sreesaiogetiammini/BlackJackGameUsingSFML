//
//  testDeck.hpp
//  FinalProject
//
//  Created by Yue Sun on 9/19/22.
//

#ifndef testDeck_hpp
#define testDeck_hpp

#include "Deck.hpp"

void testDeck() {
    Deck deck;
    deck.printDeck();
    
    PlayerHand hand;
    deck.getCards()[0].printCard();
    deck.dealHand(hand);
    deck.getCards()[0].printCard();
    hand.printHand();
    
}

#endif /* testDeck_hpp */
