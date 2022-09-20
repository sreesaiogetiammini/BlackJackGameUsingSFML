//
//  SFMLRectangles.cpp
//  FinalProject
//
//  Created by Sree Sai on 9/20/22.
//

#include "SFMLRectangles.hpp"




void drawRectangle(sf::RectangleShape rectangle ,sf::Vector2f rectanglePosition, ){
    sf::RectangleShape endRect;
    sf::Vector2f endRectPosition(1400,970);
    endRect.setPosition(endRectPosition);
    endRect.setOutlineThickness(6);
    endRect.setSize(sf::Vector2f(220,75));
    endRect.setFillColor(sf::Color :: Black);
}
