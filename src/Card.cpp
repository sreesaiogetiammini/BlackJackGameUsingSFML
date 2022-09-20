//
//  Card.cpp
//  FinalProject
//
//  Created by Yue Sun on 9/19/22.
//

#include "Card.hpp"


bool compareCard(Card& a, Card& b) {
    return a.getRank() < b.getRank();
}
