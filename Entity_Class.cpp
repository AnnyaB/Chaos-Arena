#include <SFML/Graphics.hpp>  // Include SFML's graphics module for visuals
#include <iostream>           // Include iostream for console output (useful for debugging)

// Enumeration to define the types of entities in the game

enum class EntityType { Player, Enemy, Ally };  // EntityType can be Player, Enemy, or Ally

// Entity class to represent characters in the game (like the player or an enemy)

class Entity {
public:
    // Properties (or "attributes") that define each entity
    sf::Sprite sprite;         // Represents the character's visual image on the screen
    sf::Texture texture;       // Stores the character's image file in memory
    EntityType type;           // Type of the entity (player, enemy, etc.)
    int health;                // Current health level of the entity
    int maxHealth;             // Maximum health, used to scale the health bar
    int attackPower;           // The amount of damage this entity deals when attacking
    float speed;               // Speed at which the entity moves

    // Constructor: initializes a new entity with given values for type, texture file, position, health, attack, and speed

    Entity(EntityType type, const std::string& textureFile, float x, float y, int health, int attackPower, float speed)

        : type(type), health(health), maxHealth(health), attackPower(attackPower), speed(speed) {
        
        // Load the image file specified by textureFile into texture
        if (!texture.loadFromFile(textureFile)) {
            std::cerr << "Error loading texture\n";  // Print an error message if the texture fails to load
        }
        
        // Set the loaded texture to the sprite so it has a visual appearance
            
        sprite.setTexture(texture);
        
        // Set the starting position of the sprite on the screen
            
        sprite.setPosition(x, y);
    }

    // Method to make this entity attack another entity (reduces the target's health)

    void attack(Entity& target) {
        
        // Reduce the target entity's health by this entity's attack power
        
        target.health -= attackPower;

        // Ensure the health doesn’t drop below zero
        
        if (target.health < 0) target.health = 0;

        // Printing a message to the console showing the target's remaining health
        
        std::cout << "Attacked target! Target health: " << target.health << std::endl;
    }

    // Method to check if the entity is still alive (health is greater than zero)

    bool isAlive() const {
        return health > 0;  // Returns true if health is above zero
    }

    // Method to draw the entity and its health bar on the screen

    void draw(sf::RenderWindow& window) {
        
        // Draw the entity's sprite (character image) on the game window
        
        window.draw(sprite);

        // Create a small rectangle to represent the health bar
        
        sf::RectangleShape healthBar(sf::Vector2f(40.f, 5.f));
        
        // Set the health bar color to red
        
        healthBar.setFillColor(sf::Color::Red);
        
        // Position the health bar slightly above the entity's sprite
        
        healthBar.setPosition(sprite.getPosition().x, sprite.getPosition().y - 10);
        
        // Scale the health bar based on the entity's current health (shrinks as health decreases)
        
        healthBar.setScale(static_cast<float>(health) / maxHealth, 1);

        // Draw the health bar on the game window
        
        window.draw(healthBar);
    }
};

    
