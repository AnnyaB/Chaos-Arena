// EndGame.h
#ifndef ENDGAME_H
#define ENDGAME_H

#include <SFML/Graphics.hpp>

class EndGame {
public:
    EndGame(int width, int height);      // Constructor with window size
    void setPlayerWon(bool playerWon);   // Set result based on player win/lose
    void display();                      // Display the end screen

private:
    sf::RenderWindow endGameWindow;      // Window for the end screen
    bool playerWon;                      // Track if the player won
};

#endif
