//
//  testBlackjack.cpp
//  FinalProject
//
//  Created by Yue Sun on 9/20/22.
//

#include "testBlackjack.hpp"
#include "Card.hpp"
#include "PlayerHand.hpp"
#include "DealerHand.hpp"
#include "Blackjack.hpp"

void testBlackjack() {
    Card card1("A", "spades");
    Card card2("A", "clubs");
    Card card3("A", "diamonds");
    Card card4("A", "hearts");
    Card card5("2", "diamonds");
    Card card6("3", "clubs");
    Card card7("4", "hearts");
    Card card8("5", "spades");
    Card card9("K", "diamonds");
    Card card10("J", "clubs");
    Card card11("Q", "hearts");
    Card card12("10", "spades");
    Card card13("9", "spades");
    
    PlayerHand playerHand;
    playerHand.addCard(card1);
    playerHand.addCard(card2);
    playerHand.addCard(card3);
    playerHand.addCard(card4);
    
    DealerHand dealerHand;
    dealerHand.addCard(card10);
    dealerHand.addCard(card11);
    dealerHand.addCard(card1);
    dealerHand.addCard(card2);
    
    PlayerHand playerHand2;
    playerHand2.addCard(card10);
    playerHand2.addCard(card11);
    playerHand2.addCard(card3);
    
    DealerHand dealerHand2;
    dealerHand2.addCard(card12);
    dealerHand2.addCard(card2);
    
    PlayerHand playerHand3;
    playerHand.addCard(card1);
    playerHand.addCard(card5);
    playerHand.addCard(card13);
    
    Blackjack bj;
    assert(card2.getRank() == "A");
    assert(bj.calculateScore(playerHand.getCards()) == 14);
    assert(bj.calculateScore(dealerHand.getCards()) == 22);
    assert(bj.calculateScore(playerHand2.getCards()) == 21);
    assert(bj.calculateScore(dealerHand2.getCards()) == 21);
    assert(bj.calculateScore(playerHand3.getCards()) == 22);
    
    
    std::cout << "All tests passed!\n";
}
