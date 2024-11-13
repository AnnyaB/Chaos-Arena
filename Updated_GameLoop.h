// GameLoop.h

#include "Arena.h"
#include "EndGame.h"

class GameLoop {
public:
    GameLoop(int width, int height) : arena(width, height) {}

    void start() {
        arena.run();
    }

private:
    Arena arena;
    EndGame endGameScreen;
};
