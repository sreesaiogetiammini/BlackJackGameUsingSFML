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
#include <vector>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Blackjack.hpp"
#include "PlayerHand.hpp"



enum screens {
    IntroScreen,
    GameScreen,
    HitScreen,
    StandScreen,
    ResultScreen
};
void runGameWindow();
short verifyGameResults(sf::RenderWindow& blackJackWindow,sf::Event& event,PlayerHand& player,DealerHand& dealer,Blackjack game,screens& screen,short& winner);

#endif /* gameWindow_hpp */

