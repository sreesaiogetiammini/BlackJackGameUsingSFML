//
//  gameWindow.cpp
//  FinalProject
//
//  Created by Sree Sai on 9/20/22.
//

#include "gameWindow.hpp"
#include "Card.hpp"
#include "Blackjack.hpp"
#include "PlayerHand.hpp"
#include "drawHelpers.hpp"


using namespace std;

void runGameWindow(){
    // create the window
    sf::RenderWindow blackJackWindow(sf::VideoMode::getDesktopMode(), "BlackJack Game",sf::Style::Default);
    blackJackWindow.setFramerateLimit(60);
    
//    sf::Text gameTitle = *drawGameTitle();
//    sf::Text playerText = *drawPlayerText();
//    sf::Text delearText = *drawDelearText();
//    sf::Text playText = *drawPlayText();
//    sf::Text quitText = *drawQuitText();
    sf::RectangleShape playRect = *drawPlayRect();
    sf::RectangleShape quitRect = *drawQuitRect();
//    sf::Text hitText = *drawHitText();
//    sf::Text standText = *drawStandText();
    bool stand = false;
    
    enum screens {
        IntroScreen,
        GameScreen,
        HitScreen,
        StandScreen,
        ResultScreen
    };
    
    Blackjack game;
    PlayerHand player;
    DealerHand dealer;
    screens screen = IntroScreen;
    while (blackJackWindow.isOpen()) {
        sf::Event event;
        while (blackJackWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                blackJackWindow.close();
        }
    
        if(screen == IntroScreen){
            introScreen(blackJackWindow);
            if (event.type == sf::Event::MouseButtonReleased) {
                // check mouse position to play or quit the game
                if(checkMousePosition(blackJackWindow, playRect)) {
                    game.deal2Cards(player, dealer);
                    screen = GameScreen;
                } else if (checkMousePosition(blackJackWindow, quitRect)) {
                    blackJackWindow.close();
                }
            }
        }

        if(screen == GameScreen){
            gameScreen(blackJackWindow, player, dealer);
            sf::CircleShape hitCircle = *drawHitCircle();
            sf::CircleShape standCircle = *drawStandCircle();
            if (player.getScore() > 21) {
                cout << "You lose!!\n";
//                screen = ResultScreen;
            } else if (!stand){
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (checkMousePosition(blackJackWindow, hitCircle) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        game.hit(player); // why hit so many cards?
                    }
                    if (checkMousePosition(blackJackWindow, standCircle) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        // hit button disappear
                        stand = true;
                    }
                }
            } else {
                cout << dealer.getScore() << endl;
                game.hit(dealer);
            }
//            screen = ResultScreen;
        }
        
        if (screen == ResultScreen) {
            drawBackground(blackJackWindow);
            short res = game.determineWinner(player.getScore(), dealer.getScore());
            switch (res) {
                case 1:
                    cout << "You win!!!\n";
                case -1:
                    cout << "You lose!!!\n";
                case 0:
                    cout << "Push.\n";
            }
        }

        blackJackWindow.display();
    }
}
    
void introScreen(sf::RenderWindow& window){
    drawBackground(window);
    window.draw(*drawPlayRect());
    window.draw(*drawPlayText());
    window.draw(*drawQuitRect());
    window.draw(*drawQuitText());
}


void gameScreen(sf::RenderWindow& window, PlayerHand& player,DealerHand& dealer)
{
    drawBackground(window);
    window.draw(*drawHitCircle());
    window.draw(*drawHitText());
    window.draw(*drawStandCircle());
    window.draw(*drawStandText());
    if(player.getCards().size() != 0) {
        sf::Vector2f playerCardPosition(700,700);
        for(size_t i = 0; i < player.getCards().size() ;i++){
            window.draw(*drawPlayerCard(playerCardPosition));
            window.draw(*drawText(player.getCards()[i].getRank(), playerCardPosition, sf::Color::Black, 90));
            playerCardPosition.y = playerCardPosition.y+500;
            window.draw(*drawText(player.getCards()[i].getRank(), playerCardPosition, sf::Color::Black, 90));
            playerCardPosition.y = playerCardPosition.y-500;
            playerCardPosition.x = playerCardPosition.x-75;
            playerCardPosition.y = playerCardPosition.y-75;
        }
    }

    if(dealer.getCards().size()!=0){
        sf::Vector2f dealerCardPosition(1800,700);
        for(size_t i = 0; i<dealer.getCards().size() ;i++){
            window.draw(*drawDelearCard(dealerCardPosition));
            window.draw(*drawText(dealer.getCards()[i].getRank(), dealerCardPosition, sf::Color::Black, 90));
            dealerCardPosition.y = dealerCardPosition.y+500;
            window.draw(*drawText(dealer.getCards()[i].getRank(), dealerCardPosition, sf::Color::Black, 90));
            dealerCardPosition.y = dealerCardPosition.y-500;
            dealerCardPosition.x = dealerCardPosition.x+75;
            dealerCardPosition.y = dealerCardPosition.y+75;
        }
    }
}

//void ResultScreen(sf::RenderWindow& window, PlayerHand& player, ) {
//    
//}

void hitScreen(sf::RenderWindow& window, PlayerHand& player) {
    if(player.getCards().size() != 0) {
        sf::Vector2f playerCardPosition(700,700);
        for(size_t i = 0; i<player.getCards().size() ;i++){
            window.draw(*drawPlayerCard(playerCardPosition));
            window.draw(*drawText(player.getCards()[i].getRank(), playerCardPosition, sf::Color::Black, 90));
            playerCardPosition.y = playerCardPosition.y+500;
            window.draw(*drawText(player.getCards()[i].getRank(), playerCardPosition, sf::Color::Black, 90));
            playerCardPosition.y = playerCardPosition.y-500;
            playerCardPosition.x = playerCardPosition.x-75;
            playerCardPosition.y = playerCardPosition.y-75;
        }
    }
}


void StandScreen(sf::RenderWindow& window)
{
    drawBackground(window);
    sf::Vector2f cardPosition(700,700);
    sf::Vector2f cardPosition1(720,720);
    window.draw(*drawPlayerCard(cardPosition));
    window.draw(*drawPlayerCard(cardPosition1));
//    window.draw(*drawDelearCard());
    window.draw(*drawStandCircle());
    window.draw(*drawStandText());
}
