// main.cpp
#include "GameLoop.h"

int main() {
    GameLoop game(800, 600);  // Initialize game with the arena size
    game.start();             // Start the main game loop
    return 0;
}
