#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>

// Entity Types
enum class EntityType { Warrior, Healer, Boss };
//Basic part-1 code structure 


// Entity Class Definition
class Entity {
public:
    sf::Sprite sprite;
    sf::Texture texture;
    EntityType type;
    int health;
    float speed;

    // Constructor
    Entity(EntityType type, const std::string& textureFile, float x, float y, int health, float speed)
        : type(type), health(health), speed(speed) {
        if (!texture.loadFromFile(textureFile)) {
            std::cerr << "Error loading texture\n";
        }
        sprite.setTexture(texture);
        sprite.setPosition(x, y);  // Initial position on screen
    }

    // Move entity (for demonstration purposes)
    void move(float offsetX, float offsetY) {
        sprite.move(offsetX * speed, offsetY * speed);
    }

    // Draw entity on the screen
    void draw(sf::RenderWindow& window) {
        window.draw(sprite);
    }
};
