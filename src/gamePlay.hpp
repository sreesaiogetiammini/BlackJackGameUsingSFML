//
//  gamePlay.hpp
//  FinalProject
//
//  Created by Sree Sai on 9/20/22.
//

#ifndef gamePlay_hpp
#define gamePlay_hpp

#include <stdio.h>
#include "gameWindow.hpp"
#include "Card.hpp"

class Game{
private:
    sf::Vector2f playerCardPosition_;
    sf::Vector2f delearCardPosition_;
    size_t playerTotalScore_;
    size_t delearTotalScore_;
    Card card_();
    
public:
    Game(sf::Vector2f playerCardPosition,sf::Vector2f delearCardPosition,size_t playerTotalScore,size_t delearTotalScore,Card card){
        playerCardPosition_ = playerCardPosition;
        delearCardPosition_ = delearCardPosition;
        playerTotalScore_ = playerTotalScore;
        delearTotalScore_  = delearTotalScore;
        card_() = card;
    }
    
    void setPlayerCardPosition(sf::Vector2f& playerCardPosition){
        playerCardPosition_ = playerCardPosition;
    }
    
    void setDelearCardPosition(sf::Vector2f& delearCardPosition){
        delearCardPosition_ = delearCardPosition;
    }
    
    void setPlayerTotalScore(size_t& playerTotalScore){
        playerTotalScore_ = playerTotalScore;
    }
    
    void setDelearTotalScore(size_t& delearTotalScore){
        delearTotalScore_ = delearTotalScore;
    }
    
    
    
    sf::Vector2f  getPlayerCardPosition(){
        return playerCardPosition_ ;
    }
    
    sf::Vector2f  setDelearCardPosition(){
        return delearCardPosition_ ;
    }
    
    size_t setPlayerTotalScore(){
        return playerTotalScore_ ;
    }
    
    size_t setDelearTotalScore(){
        return delearTotalScore_ ;
    }
    
    size_t hitGame(const Card card , sf::RectangleShape playerCardPosition,size_t& playerTotalScore)
    {
        size_t rank = stoi(card.getRank());
       // playerCardPosition.setPosition(playerCardPosition.getPosition().x-20, playerCardPosition.getPosition().y-20));
        return playerTotalScore+rank;
    }
    
    size_t standGame(const Card card , sf::Vector2f& playerCardPosition,size_t& playerTotalScore)
    {
        
    }
    
    bool gameResult(const size_t& playerTotalScore,const size_t& delearTotalScore){
        if(playerTotalScore>21){
            std::cout << "Delear Wins"<< std::endl;
            return false;
        }
        else if(delearTotalScore >21){
            std::cout << "Player Wins"<< std::endl;
            return true;
        }
    }
    
    
    
};



#endif /* gamePlay_hpp */
