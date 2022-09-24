//
//  drawHelpers.hpp
//  FinalProject
//
//  Created by Yue Sun on 9/21/22.
//

#ifndef drawHelpers_hpp
#define drawHelpers_hpp

#include "Card.hpp"

struct Position {
    unsigned int x;
    unsigned int y;
};

bool checkMousePosition(sf::RenderWindow& window, sf::Shape& text);
void drawBackground(sf::RenderWindow& window);

std::unique_ptr<sf::Text> drawText(const std::string& text,const sf::Vector2f& textPosition,const sf::Color& textColor ,const size_t& characterSize);
std::unique_ptr<sf::Text> drawGameTitle();
std::unique_ptr<sf::Text> drawPlayerText();
std::unique_ptr<sf::Text> drawDelearText();
std::unique_ptr<sf::Text> drawPlayText();
std::unique_ptr<sf::Text> drawQuitText();
std::unique_ptr<sf::RectangleShape> drawRectangle(const sf::Vector2f& rectanglePosition, const sf::Vector2f& rectangularSize, const sf::Color& rectangleFillColor);
std::unique_ptr<sf::RectangleShape> drawPlayRect();
std::unique_ptr<sf::RectangleShape> drawQuitRect();
std::unique_ptr<sf::Text> drawHitText();
std::unique_ptr<sf::Text> drawStandText();
std::unique_ptr<sf::Text> drawCardText(const Card card ,sf::Vector2f& cardPosition);
std::unique_ptr<sf::RectangleShape> drawCardRec(sf::Vector2f& cardPos, bool visible);
std::unique_ptr<sf::CircleShape> drawHitCircle();
std::unique_ptr<sf::CircleShape> drawStandCircle();
std::unique_ptr<sf::CircleShape> drawCircle(const float& radius, const sf::Vector2f& circlePosition, const sf::Color& circleFillColor);
std::unique_ptr<sf::Text> drawPlayerScore(unsigned short score);
std::unique_ptr<sf::CircleShape> drawPlayerScoreCircle();
std::unique_ptr<sf::Text> drawDealerScore(unsigned short score);
std::unique_ptr<sf::CircleShape> drawDealerScoreCircle();

#endif /* drawHelpers_hpp */
