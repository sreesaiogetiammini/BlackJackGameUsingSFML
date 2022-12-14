//
//  gameWindow.cpp
//  FinalProject
//
//  Created by Sree Sai on 9/20/22.
//



#include "gameWindow.hpp"

using namespace std;

void runGameWindow(){
    // create the window
    sf::RenderWindow blackJackWindow(sf::VideoMode::getDesktopMode(), "BlackJack Game", sf::Style::Default);
    blackJackWindow.setFramerateLimit(60);
    
    sf::RectangleShape playRect = *drawPlayRect();
    sf::RectangleShape quitRect = *drawQuitRect();
    
    sf::SoundBuffer buffer;
    buffer.loadFromFile("../sounds/deal.wav");
    sf::Sound sound(buffer);
    
    Blackjack game;
    PlayerHand player;
    DealerHand dealer;
    screens screen = IntroScreen;
    initFont();
    short winner ;
    while (blackJackWindow.isOpen()) {
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
                    sound.play();
                    screen = GameScreen;
                } else if (checkMousePosition(blackJackWindow, quitRect)) {
                    blackJackWindow.close();
                }
            }
        }
        
        if (screen == GameScreen ) {
            if(event.type == sf::Event::KeyReleased){
                winner = verifyGameResults( blackJackWindow,event, player, dealer, game, screen, winner, sound);
            }
            else {
                gameScreen(blackJackWindow, player, dealer);
            }
        }
        
        if (screen == HitScreen ) {
            if(event.type == sf::Event::KeyReleased){
                winner = verifyGameResults( blackJackWindow,event, player, dealer, game, screen, winner, sound);
            }
            else {
                hitScreen(blackJackWindow,player);
            }
        }
        
        if(screen == ResultScreen) {
            dealer.revealHand();
            resultScreen(blackJackWindow, winner, player, dealer);
            if(event.type == sf::Event::KeyReleased){
                if(event.key.code == sf::Keyboard::Escape){
                    blackJackWindow.close();
                }
            }
        }
        
        if(screen == StandScreen) {
            dealer.revealHand();
            standScreen(blackJackWindow, dealer);
        }
        
        blackJackWindow.display();
    }
}

short verifyGameResults(sf::RenderWindow& blackJackWindow, sf::Event& event,PlayerHand& player,DealerHand& dealer,Blackjack& game,screens& screen,short& winner, sf::Sound& sound){
    if(event.key.code == sf::Keyboard::H){
        sound.play();
        game.hitPlayer(player);
        if(player.getScore() > 21 ){
            cout << "The Score is Greater than 21 and Dealer Wins" << endl;
            winner = game.determineWinner(player.getScore(), dealer.getScore());
            screen = ResultScreen;
            return winner;
        } else if (player.getScore() == 21) {
            game.hitDealer(dealer);
            winner = game.determineWinner(player.getScore(), dealer.getScore());
            screen = ResultScreen;
            return winner;
        } else {
            screen = HitScreen;
        }
    } else if(event.key.code == sf::Keyboard::S) {
       cout << "In a Game Stand Screen"<< endl;
       dealer.revealHand();
       game.hitDealer(dealer);
       winner = game.determineWinner(player.getScore(), dealer.getScore());
       screen = ResultScreen;
       return winner;
    }
    event.type = sf::Event::KeyPressed;
}

