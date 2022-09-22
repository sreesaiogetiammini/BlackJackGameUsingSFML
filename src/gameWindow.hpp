//
//  gameWindow.hpp
//  FinalProject
//
//  Created by Sree Sai on 9/20/22.
//

#ifndef gameWindow_hpp
#define gameWindow_hpp

#pragma once
#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "PlayerHand.hpp"


void runGameWindow();
void runExtraGameWindow();

// TODO: no drawTitleText
void drawTitleText(sf::RenderWindow& window);
void introScreen(sf::RenderWindow& window);
void gameScreen(sf::RenderWindow& window,PlayerHand& player,DealerHand& dealer);
void hitScreen(sf::RenderWindow& window ,PlayerHand& player);
// TODO: no playScreen
void playScreen(sf::RenderWindow& window);
void standScreen(sf::RenderWindow& window,DealerHand& dealer);
void resultScreen(sf::RenderWindow& window, bool winner,PlayerHand& player,DealerHand& dealer);
#endif /* gameWindow_hpp */

