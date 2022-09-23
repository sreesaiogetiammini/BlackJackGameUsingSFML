//
//  tests.cpp
//  FinalProject
//
//  Created by Yue Sun on 9/22/22.
//

#include <vector>

#include "tests.hpp"
#include "Card.hpp"
#include "PlayerHand.hpp"
#include "DealerHand.hpp"
#include "Deck.hpp"
#include "Blackjack.hpp"

void tests() {
    testCard();
    testHand();
    testDeck();
    testCalculateScore();
    testDetermineWinner();
    testBlackjack();
}

void testCard() {
    Card card1("A", "spades");
    assert(card1.getRank() == "A");
    assert(card1.getSuit() == "spades");
    assert(card1.getVisible());
    card1.setVisible(false);
    assert(!card1.getVisible());
    
    std::cout << "Card test: passed!\n";
}

void testHand() {
    Card card1("A", "spades");
    Card card2("2", "diamonds");
    Card card3("3", "clubs");
    Card card4("4", "hearts");
    Card card5("5", "spades");
    Card card6("6", "diamonds");
    Card card7("7", "clubs");
    Card card8("8", "hearts");
    Card card9("9", "diamonds");
    Card card10("10", "clubs");
    Card card11("J", "hearts");
    Card card12("Q", "spades");
    Card card13("K", "diamonds");
    
    PlayerHand playerHand;
    playerHand.addCard(card1);
    assert(playerHand.getScore() == 11);
    playerHand.addCard(card2);
    assert(playerHand.getScore() == 13);
    playerHand.addCard(card3);
    assert(playerHand.getScore() == 16);
    playerHand.addCard(card7);
    assert(playerHand.getScore() == 13);
    playerHand.printHand();
    
    DealerHand dealerHand;
    dealerHand.addCard(card4);
    assert(dealerHand.getScore() == 4);
    dealerHand.addCard(card6);
    assert(dealerHand.getScore() == 10);
    dealerHand.addCard(card12);
    assert(dealerHand.getScore() == 20);
    dealerHand.addCard(card11);
    assert(dealerHand.getScore() == 30);
    dealerHand.printHand();
    assert(!dealerHand.get(0).getVisible());
    dealerHand.revealHand();
    assert(dealerHand.get(0).getVisible());
    
    std::cout << "Hand test: passed!\n";
}


void testDeck() {
    Deck deck;
    assert(deck.getSize() == 52);
    deck.printDeck();
    
    PlayerHand player;
    DealerHand dealer;
    assert(deck.get(0).getRank() == "2");
    assert(deck.get(0).getSuit() == "spades");
    for (int i = 0; i <5; i++) {
        deck.dealPlayer(player);
        deck.dealDealer(dealer);
        assert(player.getCards().size() == i + 1);
        assert(dealer.getCards().size() == i + 1);
    }
    assert(deck.getSize() == 42);
    assert(deck.get(0).getRank() == "Q");
    assert(deck.get(0).getSuit() == "spades");
    deck.shuffle();
    deck.printDeck();
    std::cout << "Deck test: passed!\n";
}

void testCalculateScore() {
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
    
    PlayerHand playerHand1; // AAAA = 14
    playerHand1.addCard(card1);
    playerHand1.addCard(card2);
    playerHand1.addCard(card3);
    playerHand1.addCard(card4);
    
    PlayerHand playerHand2; // JQA = 21
    playerHand2.addCard(card10);
    playerHand2.addCard(card11);
    playerHand2.addCard(card3);
    
    PlayerHand playerHand3; //A29 = 12
    playerHand3.addCard(card1);
    playerHand3.addCard(card5);
    playerHand3.addCard(card13);
    
    DealerHand dealerHand; //Q,10,AA = 22
    dealerHand.addCard(card10);
    dealerHand.addCard(card11);
    dealerHand.addCard(card1);
    dealerHand.addCard(card2);
    
    DealerHand dealerHand2; // AQ = 21
    dealerHand2.addCard(card12);
    dealerHand2.addCard(card2);
    
    assert(playerHand1.getScore() == 14);
    assert(playerHand2.getScore() == 21);
    assert(playerHand3.getScore() == 12);
    assert(dealerHand.getScore() == 22);
    assert(dealerHand2.getScore() == 21);
    
    std::cout << "Calculate test: passed!\n";
}

void testDetermineWinner() {
    Blackjack bj;
    assert(bj.determineWinner(17, 18) == -1);
    assert(bj.determineWinner(21, 21) == 0);
    assert(bj.determineWinner(22, 4) == -1);
    assert(bj.determineWinner(20, 18) == 1);
    assert(bj.determineWinner(16, 25) == 1);
    std::cout << "DetermineWinner test: passed!\n";
}

void testBlackjack() {
    Blackjack bj;
    PlayerHand player;
    DealerHand dealer;
    std::vector<Card> cards;
    for (int i = 0; i < 4; i++) {
        cards.push_back(bj.getDeck().get(i));
    }
    bj.hitPlayer(player);
    bj.hitPlayer(player);
    assert(player.get(0) == cards[0]);
    assert(player.get(1) == cards[1]);
    assert(bj.getDeck().getSize() == 50);
    bj.hitDealer(dealer);
    assert(dealer.get(0) == cards[2]);
    assert(dealer.get(1) == cards[3]);
    assert(bj.getDeck().getSize() == 46);
    bj.deal2Cards(player, dealer);
    assert(bj.getDeck().getSize() == 42);
    std::cout << "Blackjack test: passed!\n";
}

