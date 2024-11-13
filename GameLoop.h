// GameLoop.h
#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "Arena.h"
#include "EndGame.h"
#include "Entity.h"

class GameLoop {
public:
    GameLoop(int width, int height); // Constructor with arena size
    void start();                    // Start the game loop

private:
    Arena arena;                     // The main game arena
    EndGame endGameScreen;           // End game screen
    bool playerAlive;                // Track if the player is alive
};

#endif
