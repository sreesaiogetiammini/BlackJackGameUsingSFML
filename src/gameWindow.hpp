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
#include "Card.hpp"
#include <vector>


void runGameWindow();
void runExtraGameWindow();


sf::Text* drawPlayerText();
sf::Text* drawGameTitle();
sf::Text* drawDelearText();
sf::Text* drawText (const std::string& text,const sf::Vector2f& textPosition,const sf::Color& textColor ,const size_t& characterSize);
sf::RectangleShape* drawRectangle(const sf::Vector2f& rectanglePosition, const sf::Vector2f& rectangularSize, const sf::Color& rectangleFillColor);
sf::RectangleShape* drawPlayerCard(sf::Vector2f& cardPos);
sf::RectangleShape* drawDelearCard();
void drawTitleText(sf::RenderWindow& window);
sf::Text* drawPlayText();
sf::Text* drawQuitText();
sf::RectangleShape* drawPlayRect();
sf::RectangleShape* drawQuitRect();
void moveRectangle(sf::RectangleShape& rectangle);
void moveText(sf::Text& text);
void introScreen(sf::RenderWindow& window);
//void gameScreen(sf::RenderWindow& window, std::vector<Card> playerCard,std::vector<Card> delearCard);

sf::CircleShape* drawCircle(const float& radius,const sf::Vector2f& circlePosition , const sf::Color& circleFillColor);
sf::CircleShape* drawHitCircle();
sf::Text* drawHitText();
sf::Text* drawStandText();
sf::CircleShape* drawStandCircle();

void playScreen(sf::RenderWindow& window);
void StandScreen(sf::RenderWindow& window);


#endif /* gameWindow_hpp */
