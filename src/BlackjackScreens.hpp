//
//  BlackjackScreens.hpp
//  FinalProject
//
//  Created by Yue Sun on 9/22/22.
//

#ifndef BlackjackScreens_hpp
#define BlackjackScreens_hpp
#pragma once
#include "gameWindow.hpp"

void introScreen(sf::RenderWindow& window);
void gameScreen(sf::RenderWindow& window, PlayerHand& player, DealerHand& dealer);
void hitScreen(sf::RenderWindow& window, PlayerHand& player);
void standScreen(sf::RenderWindow& window, DealerHand& dealer);
void resultScreen(sf::RenderWindow& window, short winner, PlayerHand& player, DealerHand& dealer);
void displayCards(sf::RenderWindow& window, std::vector<Card> cards, sf::Vector2f cardPosition);

#endif /* BlackjackScreens_hpp */
