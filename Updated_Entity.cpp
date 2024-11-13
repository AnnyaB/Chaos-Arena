// Entity.h

#include <SFML/Graphics.hpp>
#include <string>

enum class EntityType { Player, Enemy, Ally };

class Entity {
public:
    sf::Sprite sprite;
    sf::Texture texture;
    EntityType type;
    int health;
    int maxHealth;
    int attackPower;
    float speed;

    Entity(EntityType type, const std::string& textureFile, float x, float y, int health, int attackPower, float speed);
    void attack(Entity& target);
    bool isAlive() const;
    void draw(sf::RenderWindow& window);
    
    // Returns priority value used in sorting (based on speed or health)
    float actionPriority() const { return speed; }
};

// Comparator for priority queue
struct EntityComparator {
    bool operator()(const std::shared_ptr<Entity>& a, const std::shared_ptr<Entity>& b) const {
        return a->actionPriority() < b->actionPriority();  // Max-heap based on speed
    }
};
