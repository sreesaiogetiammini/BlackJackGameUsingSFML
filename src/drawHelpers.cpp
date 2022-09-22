//
//  drawHelpers.cpp
//  FinalProject
//
//  Created by Yue Sun on 9/21/22.
//

#include <SFML/Graphics.hpp>
#include "drawHelpers.hpp"
#include "Card.hpp"

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

sf::Text* drawText(const std::string& text,const sf::Vector2f& textPosition,const sf::Color& textColor ,const size_t& characterSize) {
    sf::Font* introFont;
    introFont = new sf::Font;
    if(!introFont->loadFromFile("Fonts/IntroFont.otf")){};
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

sf::Text* drawPlayerText() {
    const sf::Vector2f textPos(1000,450);
    const sf::Color textColor(sf::Color::White);
    const size_t cap= 90;
    return drawText("Player",textPos,textColor,cap);
}

sf::Text* drawDelearText() {
    const sf::Vector2f textPos(1800,450);
    const sf::Color textColor(sf::Color::White);
    const size_t cap= 90;
    return drawText("Delear", textPos, textColor,cap);
}

sf::Text* drawPlayText() {
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

sf::Text* drawCard(const Card card, sf::Vector2f& cardPosition) {
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

sf::CircleShape* drawHitCircle(){
    const float radius = 150;
    const sf::Vector2f circlePosition(1350,700);
    const sf::Color circleFillColor(sf::Color :: Black);
    return drawCircle(radius, circlePosition, circleFillColor);
};

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
