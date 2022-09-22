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


using namespace std;

void runGameWindow(){
    
    
    // create the window
    sf::RenderWindow blackJackWindow(sf::VideoMode::getDesktopMode(), "BlackJack Game",sf::Style::Default);
    blackJackWindow.setFramerateLimit(60);
    
    sf::Text gameTitle = *drawGameTitle();
    sf::Text playerText = *drawPlayerText();
    sf::Text delearText = *drawDelearText();
    sf::Text playText = *drawPlayText();
    sf::Text quitText = *drawQuitText();
    sf::RectangleShape playTextRect = *drawPlayRect();
    sf::RectangleShape quitTextRect = *drawQuitRect();
    sf:: Text hitText = *drawHitText();
    sf:: Text standText = *drawStandText();
    
    
    enum screens
    {
        IntroScreen,
        GameScreen,
        HitScreen,
        StandScreen,
        ResultScreen
    };
    
    Blackjack game;
    PlayerHand player;
    DealerHand dealer;
    int count =0;
    screens e = IntroScreen;
    sf::Text textSf ;
    while (blackJackWindow.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (blackJackWindow.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                blackJackWindow.close();
        }
    
        if(e == IntroScreen){
            introScreen(blackJackWindow);
        }

        if(e==GameScreen){
            cout << "Came to Game" << endl;
            gameScreen(blackJackWindow,player,dealer);
        }
        
        if(e==HitScreen){
            cout << "Came to Hit Screen" << endl;
            hitScreen(blackJackWindow,player);
        }
        
        if (e==GameScreen && event.type == sf::Event::MouseButtonReleased){
            cout << "Came to Mouse Button" << endl;
                //Get the mouse position:
                sf::Vector2i mouse = sf::Mouse::getPosition(blackJackWindow);
                //Map Pixel to Coords:
                blackJackWindow.mapPixelToCoords(mouse);
                //Set position of the mouse to the rectangle:
                if(hitText.getGlobalBounds().contains(mouse.x, mouse.y)){
                    game.hit(player);
                    if(player.getScore()>21){
                        // Display Result Screen;
                    }
                    else{
                        e = HitScreen;
                        
                    }
                }
           }
        
        
        if (e==IntroScreen && event.type == sf::Event::MouseButtonReleased){
            cout << "Came to Mouse Button" << endl;
                //Get the mouse position:
                sf::Vector2i mouse = sf::Mouse::getPosition(blackJackWindow);
                //Map Pixel to Coords:
                blackJackWindow.mapPixelToCoords(mouse);
                //Set position of the mouse to the rectangle:
                if(playText.getGlobalBounds().contains(mouse.x, mouse.y)){
                    game.play(player, dealer);
                    cout << player.getScore() << endl;
                    if(player.getScore()>21){
                        // Display Result Screen;
                    }
                    else{
                        e = GameScreen;
                        
                    }
                }
           }
        blackJackWindow.display();
        }
    
    
       
}
    

    
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


void gameScreen(sf::RenderWindow& window,PlayerHand& player,DealerHand& dealer)
{
    window.clear(sf::Color(0,65,0));
    window.draw(*drawGameTitle());
    window.draw(*drawPlayerText());
    window.draw(*drawDelearText());
    if(player.getCards().size()!=0){
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
    window.draw(*drawHitCircle());
    window.draw(*drawHitText());
    window.draw(*drawStandCircle());
    window.draw(*drawStandText());
}

void hitScreen(sf::RenderWindow& window ,PlayerHand& player)
{
    cout << "Came to Hit Screen" << endl;
    if(player.getCards().size()!=0){
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
    window.clear(sf::Color(0,65,0));
    window.draw(*drawGameTitle());
    window.draw(*drawPlayerText());
    window.draw(*drawDelearText());
    sf::Vector2f cardPosition(700,700);
    sf::Vector2f cardPosition1(720,720);
    window.draw(*drawPlayerCard(cardPosition));
    window.draw(*drawPlayerCard(cardPosition1));
//    window.draw(*drawDelearCard());
    window.draw(*drawStandCircle());
    window.draw(*drawStandText());
}


sf::Text* drawText(const std::string& text,const sf::Vector2f& textPosition,const sf::Color& textColor ,const size_t& characterSize){
    sf::Font* introFont;
    introFont = new sf::Font;
    if(!introFont->loadFromFile("Fonts/IntroFont.otf")){
        
    }
    sf::Text* textSf;
    textSf = new sf::Text;
    textSf->setColor(textColor);
    textSf->setPosition(textPosition);
    textSf->setFont(*introFont);
    textSf->setString(text);
    textSf->setCharacterSize(characterSize);
    return textSf;
}

sf::Text* drawCard(const Card card ,sf::Vector2f& cardPosition){
    sf::Font* introFont;
    introFont = new sf::Font;
    if(!introFont->loadFromFile("Roboto-Bold.ttf")){
        
    }
    sf::Text* textSf;
    textSf = new sf::Text;
    textSf->setPosition(cardPosition);
    textSf->setFont(*introFont);
    textSf->setString(card.getRank());
    textSf->setCharacterSize(10);
    return textSf;
}


sf::Text* drawGameTitle(){
    sf::Vector2f textPos(900,2);
    sf::Color textColor(145,0,0);
    return drawText("BlackJack", textPos, textColor,400);
}



sf::Text* drawPlayerText(){
    const sf::Vector2f textPos(1000,450);
    const sf::Color textColor(sf::Color::White);
    const size_t cap= 90;
    return drawText("Player",textPos,textColor,cap);
}

sf::Text* drawDelearText(){
    const sf::Vector2f textPos(1800,450);
    const sf::Color textColor(sf::Color::White);
    const size_t cap= 90;
    return drawText("Delear", textPos, textColor,cap);
}


sf::Text* drawPlayText(){
    const sf::Vector2f textPos(1000,950);
    const sf::Color textColor(sf::Color::White);
    const size_t cap= 90;
    return drawText(" PLAY ",textPos,textColor,cap);
}

sf::Text* drawQuitText(){
    const sf::Vector2f textPos(1800,950);
    const sf::Color textColor(sf::Color::White);
    const size_t cap= 90;
    return drawText(" Quit ", textPos, textColor,cap);
}

sf::RectangleShape* drawRectangle(const sf::Vector2f& rectanglePosition, const sf::Vector2f& rectangularSize, const sf::Color& rectangleFillColor){
    sf::RectangleShape* rectangle = new sf::RectangleShape ;
    rectangle->setPosition(rectanglePosition);
    rectangle->setOutlineThickness(6);
    rectangle->setSize(rectangularSize);
    rectangle->setFillColor(rectangleFillColor);
    return rectangle;
}

sf::RectangleShape* drawPlayerCard(sf::Vector2f& cardPos){
        //sf::Vector2f cardPosition(700,700);
        sf::Vector2f cardPosition(cardPos);
        sf::Vector2f cardSize(400,600);
        sf::Color cardColor(sf::Color::White);
        return drawRectangle(cardPosition, cardSize, cardColor);
}
sf::RectangleShape* drawDelearCard(sf::Vector2f& cardPos){
    //sf::Vector2f cardPosition(1800,700);
    sf::Vector2f cardSize(400,600);
    sf::Color cardColor(sf::Color::White);
    return drawRectangle(cardPos, cardSize, cardColor);
}

sf::RectangleShape* drawPlayRect(){
    sf::Vector2f cardPosition(1000,970);
    sf::Vector2f cardSize(220,75);
    sf::Color cardColor(sf::Color :: Black);
    return drawRectangle(cardPosition, cardSize, cardColor);
}

sf::RectangleShape* drawQuitRect(){
    sf::Vector2f cardPosition(1800,970);
    sf::Vector2f cardSize(220,75);
    sf::Color cardColor(sf::Color :: Black);
    return drawRectangle(cardPosition, cardSize, cardColor);
}

sf::CircleShape* drawHitCircle(){
    const float radius = 150;
    const sf::Vector2f circlePosition(1350,700);
    const sf::Color circleFillColor(sf::Color :: Black);
    return drawCircle(radius, circlePosition, circleFillColor);
};


sf::Text* drawHitText(){
    const sf::Vector2f textPos(1375,750);
    const sf::Color textColor(sf::Color::White);
    const size_t cap= 60;
    return drawText(" Press H to HIT ",textPos,textColor,cap);
}

sf::Text* drawStandText(){
    const sf::Vector2f textPos(1350,1100);
    const sf::Color textColor(sf::Color::White);
    const size_t cap= 60;
    return drawText(" Press S to Stand ", textPos, textColor,cap);
}


sf::CircleShape* drawStandCircle(){
    const float radius = 150;
    const sf::Vector2f circlePosition(1350,1050);
    const sf::Color circleFillColor(sf::Color :: Black);
    return drawCircle(radius, circlePosition, circleFillColor);
};



sf::CircleShape* drawCircle(const float& radius,const sf::Vector2f& circlePosition , const sf::Color& circleFillColor){
    sf::CircleShape* circle = new sf::CircleShape;
    circle->setRadius(radius);
    circle->setPosition(circlePosition);
    circle->setOutlineThickness(3);
    circle->setFillColor(circleFillColor);
    return circle;
}


void moveRectangle(sf::RectangleShape& rectangle)
{
    rectangle.move(0, 0);
}

void moveText(sf::Text& text)
{
    text.move(0, 0);
}
