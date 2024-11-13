// Arena.h
#ifndef ARENA_H
#define ARENA_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Entity.h"

class Arena {
public:
    Arena(int width, int height);        // Constructor with window dimensions
    void addEntity(std::shared_ptr<Entity> entity); // Add an entity to the arena
    void run();                          // Main game loop

private:
    void processEvents();                // Handle window events
    void update();                       // Update game logic
    void render();                       // Render the frame

    sf::RenderWindow window;             // Main window for the game
    std::vector<std::shared_ptr<Entity>> entities; // List of entities in the arena
};

#endif
