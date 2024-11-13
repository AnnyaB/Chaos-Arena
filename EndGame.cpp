// EndGame.cpp
#include "EndGame.h"
#include <SFML/Graphics.hpp>

EndGame::EndGame(int width, int height)
    : endGameWindow(sf::VideoMode(width, height), "Game Over"), playerWon(false) {}

void EndGame::setPlayerWon(bool playerWon) {
    this->playerWon = playerWon;
}

void EndGame::display() {
    while (endGameWindow.isOpen()) {
        sf::Event event;
        while (endGameWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                endGameWindow.close();
        }

        endGameWindow.clear();
        
        // Show a different message based on whether the player won
        sf::Font font;
        font.loadFromFile("arial.ttf");
        sf::Text text;
        text.setFont(font);
        text.setString(playerWon ? "You Won!" : "Game Over");
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::White);
        text.setPosition(200, 300);

        endGameWindow.draw(text);
        endGameWindow.display();
    }
}
