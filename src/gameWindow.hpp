//
//  gameWindow.hpp
//  FinalProject
//
//  Created by Sree Sai on 9/20/22.
//

#ifndef gameWindow_hpp
#define gameWindow_hpp

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>


void runGameWindow();
void runExtraGameWindow();


sf::Text* drawPlayerText();
sf::Text* drawGameTitle();
sf::Text* drawDelearText();
sf::Text* drawText (const std::string& text,const sf::Vector2f& textPosition,const sf::Color& textColor ,const size_t& characterSize);
sf::RectangleShape* drawRectangle(const sf::Vector2f& rectanglePosition, const sf::Vector2f& rectangularSize, const sf::Color& rectangleFillColor);
sf::RectangleShape* drawCard();
void drawTitleText(sf::RenderWindow& window);
sf::Text* drawPlayText();
sf::Text* drawQuitText();
sf::RectangleShape* drawPlayRect();
sf::RectangleShape* drawQuitRect();
void moveRectangle(sf::RectangleShape& rectangle);
void moveText(sf::Text& text);
void introScreen(sf::RenderWindow& window);
void gameScreen(sf::RenderWindow& window);
#endif /* gameWindow_hpp */
