//
// Created by simteam-j on 9/4/24.
//

#include <iostream>
#include "Game.h"

Game::Game() {
    this->initWindow();
    this->initTextures();
    this->generateGround();
    this->initPlayer();
}

void Game::run() {
    while (window->isOpen()) {
        // Handle window events
        this->handleEvents();

        // Handle player movement
        this->player->handleMovement(event);

        // Display stuff on screen
        this->handleDisplay();
    }
}

// Handler functions
void Game::handleEvents() {
    // Handle input keys
    while(window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window->close();
                break;
            default:
                break;
        }
    }
}

void Game::handleDisplay() {
    window->clear();
    this->drawObjects();
    window->display();
}

void Game::checkCollision() {
    for (auto tile: ground) {
        tile.GetCollider().CheckCollision(player->GetCollider(), 0.0f);
    }
}

// Init functions
void Game::initWindow() {
    window = new sf::RenderWindow(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Terraria");
    this->window->setFramerateLimit(60);
}

void Game::initTextures() {
    if(!groundTexture.loadFromFile("../assets/tiles/Ground.png"))
        std::cout << "error opening file\n";
}

// Draw functions
void Game::drawObjects() {
    // Draw ground
    for (auto tile: ground) {
        tile.drawShape(*window);
    }
    // Draw player
    this->player->drawShape(*window);
}

// Game logic
void Game::initPlayer() {
    player = new Player(700, 200);
}

void Game::generateGround() {
    for (int i = 0; i < WIN_WIDTH; i += 51) {
        for (int j = 350; j < WIN_HEIGHT; j += 51) {
            this->ground.emplace_back(float(i), float(j), this->groundTexture);
        }
    }
}
