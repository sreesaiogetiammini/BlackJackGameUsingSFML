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
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>


using namespace std;

void runGameWindow(){
    // create the window
    sf::RenderWindow blackJackWindow(sf::VideoMode::getDesktopMode(), "BlackJack Game",sf::Style::Default);
    blackJackWindow.setFramerateLimit(60);
    
//    sf::Text gameTitle = *drawGameTitle();
//    sf::Text playerText = *drawPlayerText();
//    sf::Text delearText = *drawDelearText();
    sf::Text playText = *drawPlayText();
    sf::Text quitText = *drawQuitText();
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
    bool winner ;
    while (blackJackWindow.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
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

        if(screen==HitScreen){
            cout << "In a Hit Screen"<< endl;
            if(event.type == sf::Event::KeyReleased)
            {
                if(event.key.code == sf::Keyboard::H){
                    game.hit(player);
                    cout << game.calculateScore(player)<< endl;
                    if(game.calculateScore(player)>21){
                        winner = false;
                        screen = ResultScreen;
                    }
                    else{
                        screen = GameScreen;
                        
                    }
                    
                }
                if(event.key.code == sf::Keyboard::S)
                {
                    cout << "In a Hit Stand Screen"<< endl;
                    if(game.calculateScore(player)>21){
                        screen = ResultScreen;
                    }
                    else{
                        screen = GameScreen;
                        
                    }
                }
            }
            else{
                cout << "In Hit Else Part" << endl;
                hitScreen(blackJackWindow,player);
            }
        event.type = sf::Event::KeyPressed;
        }
        
     
       
        if (screen == GameScreen ){
            if(event.type == sf::Event::KeyReleased)
            {
                if(event.key.code == sf::Keyboard::H){
                    game.hit(player);
                    cout << game.calculateScore(player)<< endl;
                    if(game.calculateScore(player)>21){
                        cout << "The Score is Greater than 21 and Dealer Wins" << endl;
                        winner = false;
                        screen = ResultScreen;
                    }
                    else{
                        screen = HitScreen;
                    }
                    
                }
                if(event.key.code == sf::Keyboard::S)
                {
                    cout << "In a Game Stand Screen"<< endl;
                    screen = StandScreen;
                    game.hit(dealer);
                    if(game.calculateScore(dealer)>21){
                        cout << "The Score is Greater than 21 and Player Wins" << endl;
                        winner = true;
                        screen = ResultScreen;
                    }
                    else if(game.calculateScore(player)>game.calculateScore(dealer)){
                        cout << "The Score is of Player is greater than Dealer and Less than 21 Player Wins" << endl;
                        winner = true;
                        screen = ResultScreen;
                    }
                    else if(game.calculateScore(player)<game.calculateScore(dealer)){
                        cout << "The Score is of Dealer is greater than Player and Less than 21 Dealer Wins" << endl;
                        winner = false;
                        screen = ResultScreen;
                    }
                    
                }
                event.type = sf::Event::KeyPressed;
            }
            
            else{
                cout << "Came to Game" << endl;
                gameScreen(blackJackWindow,player,dealer);
            }
        
        if(screen==ResultScreen){
            resultScreen(blackJackWindow, winner,player,dealer);
        }
        
        if(screen == StandScreen){
            standScreen(blackJackWindow, dealer);
        }
        
        if (screen==IntroScreen && event.type == sf::Event::MouseButtonReleased){
            cout << "Came to Mouse Button" << endl;
                //Get the mouse position:
                sf::Vector2i mouse = sf::Mouse::getPosition(blackJackWindow);
                //Map Pixel to Coords:
                blackJackWindow.mapPixelToCoords(mouse);
                //Set position of the mouse to the rectangle:
                if(playText.getGlobalBounds().contains(mouse.x, mouse.y)){
                    game.deal2Cards(player, dealer);
                    cout << game.calculateScore(player)<< endl;
                    if(game.calculateScore(player)>21){
                        winner = false;
                        screen = ResultScreen;
                    }
                    else{
                        screen = GameScreen;
                        
                    }
                }
            event.type = sf::Event::MouseButtonPressed;
           }
        blackJackWindow.display();
        }
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
            playerCardPosition.x = playerCardPosition.x+75;
            playerCardPosition.y = playerCardPosition.y+75;
        }
    }

    if(dealer.getCards().size()!=0){
        sf::Vector2f dealerCardPosition(1800,700);
        for(size_t i = 0; i<dealer.getCards().size() ;i++){
            window.draw(*drawDelearCard(dealerCardPosition));
            if(i>0){
                window.draw(*drawText(dealer.getCards()[i].getRank(), dealerCardPosition, sf::Color::Black, 90));
                dealerCardPosition.y = dealerCardPosition.y+500;
                window.draw(*drawText(dealer.getCards()[i].getRank(), dealerCardPosition, sf::Color::Black, 90));
                dealerCardPosition.y = dealerCardPosition.y-500;
            }
            dealerCardPosition.x = dealerCardPosition.x+75;
            dealerCardPosition.y = dealerCardPosition.y+75;
        }
    }
}

void hitScreen(sf::RenderWindow& window ,PlayerHand& player)
{
    if(player.getCards().size()!=0){
        sf::Vector2f playerCardPosition(700,700);
        for(size_t i = 0; i<player.getCards().size() ;i++){
            window.draw(*drawPlayerCard(playerCardPosition));
            window.draw(*drawText(player.getCards()[i].getRank(), playerCardPosition, sf::Color::Black, 90));
            playerCardPosition.y = playerCardPosition.y+500;
            window.draw(*drawText(player.getCards()[i].getRank(), playerCardPosition, sf::Color::Black, 90));
            playerCardPosition.y = playerCardPosition.y-500;
            playerCardPosition.x = playerCardPosition.x+75;
            playerCardPosition.y = playerCardPosition.y+75;
        }
    }
}


void standScreen(sf::RenderWindow& window,DealerHand& dealer)
{
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


void resultScreen(sf::RenderWindow& window, bool winner,PlayerHand& player,DealerHand& dealer)
{
    window.clear(sf::Color(0,65,0));
    window.draw(*drawPlayerText());
    window.draw(*drawDelearText());
    if(player.getCards().size()!=0){
        sf::Vector2f playerCardPosition(700,600);
        for(size_t i = 0; i<player.getCards().size() ;i++){
            window.draw(*drawPlayerCard(playerCardPosition));
            window.draw(*drawText(player.getCards()[i].getRank(), playerCardPosition, sf::Color::Black, 90));
            playerCardPosition.y = playerCardPosition.y+500;
            window.draw(*drawText(player.getCards()[i].getRank(), playerCardPosition, sf::Color::Black, 90));
            playerCardPosition.y = playerCardPosition.y-500;
            playerCardPosition.x = playerCardPosition.x+75;
            playerCardPosition.y = playerCardPosition.y+75;
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
    
    
    
    sf::Vector2f winnerPosition(900,2);
    if(winner){
        window.draw(*drawText("Player Wins", winnerPosition,  sf::Color(145,0,0), 400));
    }
    else {
        window.draw(*drawText("Dealer Wins", winnerPosition,  sf::Color(145,0,0), 400));
    }
    winnerPosition.y = winnerPosition.y + 50;
    drawRectangle(winnerPosition, sf::Vector2f(1800,900), sf::Color::Black);
 
}
