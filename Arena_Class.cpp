//Part-2 code structure Arena Class : manages entities and handles the main game loop, where events, updates, and drawing take place

class Arena {
public:
    sf::RenderWindow window;
    std::vector<std::shared_ptr<Entity>> entities;

    // Constructor for setting up the game window
    Arena() : window(sf::VideoMode(800, 600), "Chaos Arena") {}

    // Add entity to the arena
    void addEntity(std::shared_ptr<Entity> entity) {
        entities.push_back(entity);
    }

    // Main game loop
    void run() {
        while (window.isOpen()) {
            processEvents();
            update();
            render();
        }
    }

private:
    // Handle input and window events
    void processEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Basic movement control for the first entity
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            entities[0]->move(-1, 0); // Move left
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            entities[0]->move(1, 0); // Move right
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            entities[0]->move(0, -1); // Move up
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            entities[0]->move(0, 1); // Move down
        }
    }

    // Update game state (empty for now)
    void update() {
        // Add logic for updating game state, collisions, etc.
    }

    // Draw everything on the screen
    void render() {
        window.clear();
        for (auto& entity : entities) {
            entity->draw(window);
        }
        window.display();
    }
};
