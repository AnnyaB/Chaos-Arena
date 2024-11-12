#include <vector>            // For storing a list of entities
#include <memory>            // For managing dynamic memory (shared_ptr)
#include <SFML/Graphics.hpp> // For rendering the game window
#include <algorithm>         // For handling collisions and interactions

class Arena {
public:
    // Arena constructor, sets up the main game window

    Arena(int width, int height) 
        : window(sf::VideoMode(width, height), "Chaos Arena") {
    }

    // Method to add a new entity to the arena

    void addEntity(std::shared_ptr<Entity> entity) {
        entities.push_back(entity); // Add entity to the list
    }

    // Main game loop to run the game

    void run() {
        while (window.isOpen()) {
            processEvents();    // Handle user input
            update();           // Update game logic (e.g., entity interactions)
            render();           // Draw everything on the screen
        }
    }

private:
    sf::RenderWindow window;                  // Main game window for displaying the arena
    std::vector<std::shared_ptr<Entity>> entities; // List of entities in the arena

    // Process user input, e.g., closing the window

    void processEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close(); // Close the window if requested
        }
    }

    // Update game logic, such as entity actions and interactions

    void update() {
        // Loop through all entities to handle actions
        for (auto& entity : entities) {
            if (!entity->isAlive()) continue; // Skip if entity is dead

            // Simple example: Check for collisions and interactions
            for (auto& other : entities) {
                if (entity != other && entity->sprite.getGlobalBounds().intersects(other->sprite.getGlobalBounds())) {
                    entity->attack(*other); // Entities attack each other on collision
                }
            }
        }

        // Remove entities that are no longer alive
        
        entities.erase(
            std::remove_if(entities.begin(), entities.end(),
                           [](const std::shared_ptr<Entity>& entity) { return !entity->isAlive(); }),
            entities.end());
    }

    // Render all entities and visual elements on the window

    void render() {
        window.clear();  // Clear the window to prepare for new frame

        // Draw each entity
        
        for (const auto& entity : entities) {
            entity->draw(window);  // Call each entity's draw method
        }

        window.display();  // Display everything drawn on the window
    }
};

