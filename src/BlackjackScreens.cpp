//
//  BlackjackScreens.cpp
//  FinalProject
//
//  Created by Yue Sun on 9/22/22.
//

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Audio.hpp>
#include "BlackjackScreens.hpp"
#include "drawHelpers.hpp"
#include "PlayerHand.hpp"

void introScreen(sf::RenderWindow& window){
    window.clear(sf::Color(0,65,0));
    window.draw(*drawGameTitle());
    window.draw(*drawPlayerText());
    window.draw(*drawDelearText());
    window.draw(*drawPlayRect());
    window.draw(*drawPlayText());
    window.draw(*drawQuitRect());
    window.draw(*drawQuitText());
}


void gameScreen(sf::RenderWindow& window,PlayerHand& player,DealerHand& dealer) {
    drawBackground(window);
    hitScreen(window, player);
    standScreen(window, dealer);
    window.draw(*drawHitCircle());
    window.draw(*drawHitText());
    window.draw(*drawStandCircle());
    window.draw(*drawStandText());
    window.draw(*drawPlayerScoreCircle());
    window.draw(*drawPlayerScore(player.getScore()));
    window.draw(*drawDealerScoreCircle());
    if (dealer.getVisible()) {
        window.draw(*drawDealerScore(dealer.getScore()));
    }
}

void hitScreen(sf::RenderWindow& window, PlayerHand& player) {
    sf::Vector2f playerCardPosition(700,700);
    displayCards(window, player.getCards(), playerCardPosition);
    window.draw(*drawPlayerScoreCircle());
    window.draw(*drawPlayerScore(player.getScore()));
}

void standScreen(sf::RenderWindow& window, DealerHand& dealer) {
    sf::Vector2f dealerCardPosition(1800,700);
    displayCards(window, dealer.getCards(),dealerCardPosition);
    window.draw(*drawDealerScoreCircle());
    window.draw(*drawDealerScore(dealer.getScore()));
}

void resultScreen(sf::RenderWindow& window, short winner, PlayerHand& player, DealerHand& dealer) {
    window.clear(sf::Color(0,65,0));
    window.draw(*drawPlayerText());
    window.draw(*drawDelearText());
    sf::Vector2f playerCardPosition(700,700);
    displayCards(window, player.getCards(), playerCardPosition);
    sf::Vector2f dealerCardPosition(1800,700);
    displayCards(window, dealer.getCards(), dealerCardPosition);
    window.draw(*drawPlayerScoreCircle());
    window.draw(*drawPlayerScore(player.getScore()));
    window.draw(*drawDealerScoreCircle());
    window.draw(*drawDealerScore(dealer.getScore()));
    sf::Vector2f winnerPosition(900,2);
    
    if(winner == 1){
        window.draw(*drawText("Player Wins!", winnerPosition,  sf::Color(253, 216, 53), 400));
    } else if(winner ==0){
        window.draw(*drawText("Game Draw", winnerPosition,  sf::Color(253, 216, 53), 400));
    } else if(winner == -1){
        window.draw(*drawText("Dealer Wins!", winnerPosition,  sf::Color(253, 216, 53), 400));
    }
    winnerPosition.y += 50;
    drawRectangle(winnerPosition, sf::Vector2f(1800,900), sf::Color::Black);
}

void displayCards(sf::RenderWindow& window, std::vector<Card> cards, sf::Vector2f cardPosition) {
    for(size_t i = 0; i < cards.size(); i++){
        window.draw(*drawCardRec(cardPosition, cards[i].getVisible()));
        if(cards[i].getVisible()){
            window.draw(*drawText(cards[i].getRank(), cardPosition, sf::Color::Black, 60));
            sf::Texture cardImage;
            if(cardImage.loadFromFile("images/"+cards[i].getSuit()+".png")){
                sf::Sprite imageSprite;
                imageSprite.setTexture(cardImage,true);
                cardPosition.y += 250;
                imageSprite.setPosition(cardPosition);
                window.draw(imageSprite);
                cardPosition.y -= 250;
            }
            cardPosition.y += 500;
            window.draw(*drawText(cards[i].getRank(), cardPosition, sf::Color::Black, 60));
            cardPosition.y -= 500;
        }
        
        cardPosition.x += 75;
        cardPosition.y += 75;
    }
}
