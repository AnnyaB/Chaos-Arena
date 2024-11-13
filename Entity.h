// Entity.h
#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <iostream>

enum class EntityType { Player, Enemy, Ally }; // Enumeration for entity types

class Entity {
public:
    Entity(EntityType type, const std::string& textureFile, float x, float y, int health, int attackPower, float speed);
    
    void attack(Entity& target);     // Method to attack another entity
    bool isAlive() const;            // Checks if the entity is still alive
    void draw(sf::RenderWindow& window); // Draws the entity and health bar on the window

    sf::Sprite sprite;
    sf::Texture texture;
    EntityType type;
    int health;
    int maxHealth;
    int attackPower;
    float speed;
};

#endif
