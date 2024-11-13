// GameLoop.cpp
#include "GameLoop.h"

GameLoop::GameLoop(int width, int height)
    : arena(width, height), endGameScreen(width, height), playerAlive(true) {
    // Adding player and enemies to the arena
    arena.addEntity(std::make_shared<Entity>(EntityType::Player, "player.png", 100, 100, 100, 10, 1.0f));
    arena.addEntity(std::make_shared<Entity>(EntityType::Enemy, "enemy.png", 400, 400, 50, 5, 1.0f));
}

void GameLoop::start() {
    while (playerAlive && arena.run()) { // Game runs while player is alive
        // Check game over conditions
        playerAlive = false;
        for (const auto& entity : arena.entities) {
            if (entity->type == EntityType::Player && entity->isAlive()) {
                playerAlive = true;
                break;
            }
        }
    }
    endGameScreen.setPlayerWon(playerAlive); // Set result based on player status
    endGameScreen.display();
}
