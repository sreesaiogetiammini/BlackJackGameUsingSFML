# Blackjack 
Contributors: Yue Sun, Shree Sai Ogetiammini

## Introduction

### Intro Screen

The use clicks `PLAY` to play or `Quit`  to quit the game.

<img src="/Users/sonia/Documents/MSD/CS6010/FinalProjectCS6010/assets/introScreen.png" alt="image-20220923221352127" style="zoom:30%;" />

### Game Screen

The user presses `H` to hit the card or `S` to stand. The score will update automatically. If the user chooses to stand, the dealer will reveal their hand. The dealer must keep hitting until their score is equal or higher than 17.

<img src="/Users/sonia/Documents/MSD/CS6010/FinalProjectCS6010/assets/gameScreen.png" alt="image-20220923221352127" style="zoom:30%;" />

### Result Screen

If the player bust or the player's score is less than the dealer's, Dealer Wins. If the dealer bust or the dealer's score is less, the player wins. If their scores are equal, game draws.

<img src="/Users/sonia/Documents/MSD/CS6010/FinalProjectCS6010/assets/resultScreen.png" alt="image-20220923221615807" style="zoom:30%;" />

## Implementation

- language: C++
- library: [SFML](https://www.sfml-dev.org)
- tools: CMake

## Run it locally

1. Clone this repository to your computer:

   ```bash
   git clone https://github.com/sreesaiogetiammini/FinalProjectCS6010
   cd FinalProjectCS6010
   ```

2. compile the program with CMake:

   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. run the program in your terminal

   `./blackjack`

