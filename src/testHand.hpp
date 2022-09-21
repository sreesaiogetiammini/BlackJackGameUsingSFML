//
//  testHand.hpp
//  FinalProject
//
//  Created by Yue Sun on 9/19/22.
//

#ifndef testHand_hpp
#define testHand_hpp

#include "Card.hpp"
#include "PlayerHand.hpp"
#include "Blackjack.hpp"

void testHand() {
    Card card1("A", "spades");
    Card card2("2", "diamonds");
    Card card3("3", "clubs");
    Card card4("4", "hearts");
    Card card5("5", "spades");
    Card card6("K", "diamonds");
    Card card7("J", "clubs");
    Card card8("Q", "hearts");
    
    PlayerHand playerHand; // don't use playerHand()
    playerHand.addCard(card1);
    playerHand.addCard(card2);
    playerHand.addCard(card3);
    playerHand.addCard(card7);
    playerHand.printHand();
    playerHand.sortHand();
    playerHand.printHand();
    
    DealerHand dealerHand;
    dealerHand.addCard(card4);
    dealerHand.addCard(card6);
    dealerHand.addCard(card5);
    dealerHand.printHand();
    dealerHand.sortHand();
    dealerHand.printHand();
}

#endif /* testHand_hpp */
