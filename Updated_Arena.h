// Arena.h

#include <vector>
#include <queue>
#include <memory>
#include "Entity.h"

class Arena {
public:
    Arena(int width, int height);

    void addEntity(std::shared_ptr<Entity> entity);
    void run();  // Main loop to execute the game
    
private:
    sf::RenderWindow window;
    std::vector<std::shared_ptr<Entity>> entities;

    // Priority queue for processing entities based on priority
    std::priority_queue<std::shared_ptr<Entity>, std::vector<std::shared_ptr<Entity>>, EntityComparator> actionQueue;

    void processEvents();
    void update();
    void render();
};
