//
//  drawHelpers.hpp
//  FinalProject
//
//  Created by Yue Sun on 9/21/22.
//

#ifndef drawHelpers_hpp
#define drawHelpers_hpp

#include "Card.hpp"
bool checkMousePosition(sf::RenderWindow& window, sf::Shape& text);
void drawBackground(sf::RenderWindow& window);
sf::Text* drawText(const std::string& text,const sf::Vector2f& textPosition,const sf::Color& textColor ,const size_t& characterSize);
sf::Text* drawGameTitle();
sf::Text* drawPlayerText();
sf::Text* drawDelearText();
sf::Text* drawPlayText();
sf::Text* drawQuitText();
sf::RectangleShape* drawRectangle(const sf::Vector2f& rectanglePosition, const sf::Vector2f& rectangularSize, const sf::Color& rectangleFillColor);
sf::RectangleShape* drawPlayRect();
sf::RectangleShape* drawQuitRect();
sf::Text* drawHitText();
sf::Text* drawStandText();
sf::Text* drawCard(const Card card ,sf::Vector2f& cardPosition);
sf::RectangleShape* drawCard(sf::Vector2f& cardPos);
sf::CircleShape* drawHitCircle();
sf::CircleShape* drawStandCircle();
sf::CircleShape* drawCircle(const float& radius, const sf::Vector2f& circlePosition, const sf::Color& circleFillColor);
sf::Text* drawScore(unsigned short score);

#endif /* drawHelpers_hpp */
