//
//  gameWindow.cpp
//  FinalProject
//
//  Created by Sree Sai on 9/20/22.
//

#pragma once
#include "gameWindow.hpp"


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

    sf::Text textSf ;
    while (blackJackWindow.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (blackJackWindow.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                blackJackWindow.close();
            }
            blackJackWindow.clear(sf::Color(0,65,0));
            blackJackWindow.draw(gameTitle);
            blackJackWindow.draw(playerText);
            blackJackWindow.draw(delearText);
            blackJackWindow.draw(playTextRect);
            blackJackWindow.draw(playText);
            blackJackWindow.draw(quitTextRect);
            blackJackWindow.draw(quitText);
            
            switch (event.type)
            {
                case sf::Event::MouseButtonPressed:{
                    size_t xAxis =  sf::Mouse::getPosition(blackJackWindow).x;
                    size_t yAxis =  sf::Mouse::getPosition(blackJackWindow).y;
                    if(yAxis>=970 && yAxis <= 1045){
                        if(xAxis>=900 && xAxis <= 1120){
                            std::cout  << "Play Button Pressed" << std::endl;
                            moveText(playText);
                        }

                        else if(xAxis>=1400 && xAxis <= 1660){
                            std::cout  << "End Button Pressed" << std::endl;
                        }
                    }
                    break;
                }
                default:
                break;
        }
            
            blackJackWindow.display();
        }
    }
    
    
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

sf::RectangleShape* drawCard(){
    sf::Vector2f cardPosition(800,100);
    sf::Vector2f cardSize(800,100);
    sf::Color cardColor(145,0,0);
    return drawRectangle(cardPosition, cardSize, cardColor);
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

void moveRectangle(sf::RectangleShape& rectangle)
{
    rectangle.move(0, 0);
}

void moveText(sf::Text& text)
{
    text.move(0, 0);
}




