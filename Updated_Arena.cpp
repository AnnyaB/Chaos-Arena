// Arena.cpp

#include "Arena.h"

Arena::Arena(int width, int height)
    : window(sf::VideoMode(width, height), "Chaos Arena") {}

void Arena::addEntity(std::shared_ptr<Entity> entity) {
    entities.push_back(entity);
}

void Arena::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Arena::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Arena::update() {
    // Add all alive entities to the priority queue
    for (auto& entity : entities) {
        if (entity->isAlive()) {
            actionQueue.push(entity);
        }
    }

    // Process entities based on priority (highest speed first)
    while (!actionQueue.empty()) {
        auto entity = actionQueue.top();
        actionQueue.pop();

        // Check for interactions/collisions
        for (auto& other : entities) {
            if (entity != other && entity->isAlive() && other->isAlive() &&
                entity->sprite.getGlobalBounds().intersects(other->sprite.getGlobalBounds())) {
                entity->attack(*other);  // Attack or interact on collision
            }
        }
    }

    // Remove dead entities from the list
    entities.erase(std::remove_if(entities.begin(), entities.end(),
                   [](const std::shared_ptr<Entity>& entity) { return !entity->isAlive(); }),
                   entities.end());
}

void Arena::render() {
    window.clear();
    for (const auto& entity : entities) {
        entity->draw(window);
    }
    window.display();
}
