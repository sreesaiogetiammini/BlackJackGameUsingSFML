//
//  gameWindow.hpp
//  FinalProject
//
//  Created by Sree Sai on 9/20/22.
//

#ifndef gameWindow_hpp
#define gameWindow_hpp

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include "PlayerHand.hpp"
#include "DealerHand.hpp"
#include "Blackjack.hpp"
#include "drawHelpers.hpp"
#include "BlackjackScreens.hpp"

enum screens {
    IntroScreen,
    GameScreen,
    HitScreen,
    StandScreen,
    ResultScreen
};
void runGameWindow();
short verifyGameResults(sf::RenderWindow& blackJackWindow,sf::Event& event,PlayerHand& player,DealerHand& dealer,Blackjack& game,screens& screen, short& winner, sf::Sound& sound);
#endif /* gameWindow_hpp */

