//
//  drawHelpers.cpp
//  FinalProject
//
//  Created by Yue Sun on 9/21/22.
//

#include <SFML/Graphics.hpp>
#include "drawHelpers.hpp"
#include "Card.hpp"

Position playerText {1000, 450};
Position dealerText {1800, 450};

Position playerScore {850, playerText.y + 10};
Position dealerScore {2100, dealerText.y + 10};
Position playerScoreCircle {playerScore.x - 30, playerScore.y + 10};
Position dealerScoreCircle {dealerScore.x - 30, dealerScore.y + 10};

sf::Font introFont;
void initFont(){
    introFont.loadFromFile("../fonts/IntroFont.otf");
}

bool checkMousePosition(sf::RenderWindow& window, sf::Shape& shape) {
    sf::Vector2i mouse = sf::Mouse::getPosition(window);//Get mouse position
    window.mapPixelToCoords(mouse);
    return shape.getGlobalBounds().contains(mouse.x, mouse.y);
}

void drawBackground(sf::RenderWindow& window) {
    window.clear(sf::Color(0,65,0));
    window.draw(*drawGameTitle());
    window.draw(*drawPlayerText());
    window.draw(*drawDelearText());
}

std::unique_ptr<sf::Text> drawText(const std::string& text,const sf::Vector2f& textPosition,const sf::Color& textColor ,const size_t& characterSize)
{
    std::unique_ptr<sf::Text> textSf(new sf::Text);
    textSf->setColor(textColor);
    textSf->setPosition(textPosition);
    textSf->setFont(introFont);
    textSf->setString(text);
    textSf->setCharacterSize(characterSize);
    return textSf;
}

std::unique_ptr<sf::Text> drawGameTitle(){
    sf::Vector2f textPos(900,2);
    sf::Color textColor(145,0,0);
    return drawText("BlackJack", textPos, textColor,400);
}

std::unique_ptr<sf::Text> drawPlayerText() {
    const sf::Vector2f textPos(playerText.x, playerText.y);
    const sf::Color textColor(sf::Color::White);
    const size_t cap = 90;
    return drawText("Player",textPos,textColor,cap);
}

std::unique_ptr<sf::Text> drawDelearText() {
    const sf::Vector2f textPos(dealerText.x, dealerText.y);
    const sf::Color textColor(sf::Color::White);
    const size_t cap= 90;
    return drawText("Delear", textPos, textColor,cap);
}

std::unique_ptr<sf::Text> drawPlayText() {
    const sf::Vector2f textPos(1000,950);
    const sf::Color textColor(sf::Color::White);
    const size_t cap= 90;
    return drawText(" PLAY ",textPos,textColor,cap);
}

std::unique_ptr<sf::Text> drawQuitText(){
    const sf::Vector2f textPos(1800,950);
    const sf::Color textColor(sf::Color::White);
    const size_t cap= 90;
    return drawText(" Quit ", textPos, textColor,cap);
}

std::unique_ptr<sf::RectangleShape> drawRectangle(const sf::Vector2f& rectanglePosition, const sf::Vector2f& rectangularSize, const sf::Color& rectangleFillColor){
    
    std::unique_ptr<sf::RectangleShape> rectangle(new sf::RectangleShape);
    rectangle->setPosition(rectanglePosition);
    rectangle->setOutlineThickness(6);
    rectangle->setSize(rectangularSize);
    rectangle->setFillColor(rectangleFillColor);
    return rectangle;
}

std::unique_ptr<sf::RectangleShape> drawPlayRect(){
    sf::Vector2f cardPosition(1000,970);
    sf::Vector2f cardSize(220,75);
    sf::Color cardColor(sf::Color :: Black);
    return drawRectangle(cardPosition, cardSize, cardColor);
}

std::unique_ptr<sf::RectangleShape> drawQuitRect(){
    sf::Vector2f cardPosition(1800,970);
    sf::Vector2f cardSize(220,75);
    sf::Color cardColor(sf::Color :: Black);
    return drawRectangle(cardPosition, cardSize, cardColor);
}

std::unique_ptr<sf::Text> drawHitText(){
    const sf::Vector2f textPos(1375,800);
    const sf::Color textColor(sf::Color::White);
    const size_t cap = 60;
    return drawText(" Press H to Hit ",textPos,textColor,cap);
}

std::unique_ptr<sf::Text> drawStandText(){
    const sf::Vector2f textPos(1350,1150);
    const sf::Color textColor(sf::Color::White);
    const size_t cap = 60;
    return drawText(" Press S to Stand ", textPos, textColor,cap);
}

std::unique_ptr<sf::Text> drawCardText(const Card card, sf::Vector2f& cardPosition) {
    std::unique_ptr<sf::Text> textSf(new sf::Text);
    textSf->setPosition(cardPosition);
    textSf->setFont(introFont);
    textSf->setString(card.getRank());
    textSf->setCharacterSize(10);
    return textSf;
}

std::unique_ptr<sf::RectangleShape> drawCardRec(sf::Vector2f& cardPos, bool visible) {
    sf::Vector2f cardPosition(cardPos);
    sf::Vector2f cardSize(400,600);
    sf::Color cardColor;
    if (visible) {
        cardColor = sf::Color::White;
    } else {
        cardColor = sf::Color(128, 128, 128);
    }
    return drawRectangle(cardPosition, cardSize, cardColor);
}

std::unique_ptr<sf::CircleShape> drawHitCircle(){
    const float radius = 150;
    const sf::Vector2f circlePosition(1350,700);
    const sf::Color circleFillColor(sf::Color :: Black);
    return drawCircle(radius, circlePosition, circleFillColor);
};

std::unique_ptr<sf::CircleShape> drawStandCircle(){
    const float radius = 150;
    const sf::Vector2f circlePosition(1350,1050);
    const sf::Color circleFillColor(sf::Color :: Black);
    return drawCircle(radius, circlePosition, circleFillColor);
};

std::unique_ptr<sf::CircleShape> drawCircle(const float& radius,const sf::Vector2f& circlePosition , const sf::Color& circleFillColor){
    std::unique_ptr<sf::CircleShape> circle(new sf::CircleShape);
    circle->setRadius(radius);
    circle->setPosition(circlePosition);
    circle->setOutlineThickness(3);
    circle->setFillColor(circleFillColor);
    return circle;
}

std::unique_ptr<sf::Text> drawPlayerScore(unsigned short score) {
    const sf::Vector2f textPos(playerScore.x, playerScore.y);
    const sf::Color textColor(sf::Color::White);
    const size_t cap = 80;
    return drawText(std::to_string(score),textPos,textColor,cap);
}

std::unique_ptr<sf::CircleShape> drawPlayerScoreCircle() {
    const float radius = 50;
    const sf::Vector2f circlePosition(playerScoreCircle.x, playerScoreCircle.y);
    const sf::Color circleFillColor(sf::Color(0, 65, 0));
    return drawCircle(radius, circlePosition, circleFillColor);
}

std::unique_ptr<sf::Text> drawDealerScore(unsigned short score) {
    const sf::Vector2f textPos(dealerScore.x, dealerScore.y);
    const sf::Color textColor(sf::Color::White);
    const size_t cap = 80;
    return drawText(std::to_string(score),textPos,textColor,cap);
}

std::unique_ptr<sf::CircleShape> drawDealerScoreCircle() {
    const float radius = 50;
    const sf::Vector2f circlePosition(dealerScoreCircle.x, dealerScoreCircle.y);
    const sf::Color circleFillColor(sf::Color(0, 65, 0));
    return drawCircle(radius, circlePosition, circleFillColor);
}
