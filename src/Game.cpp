//
// Created by simteam-j on 9/4/24.
//

#include "Game.h"

Game::Game() {
    this->initWindow();
}

void Game::run() {
    while (window->isOpen()) {
        this->handleEvents();
        this->handleDisplay();
    }
}

void Game::handleEvents() {
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
    window->display();
}

void Game::initWindow() {
    window = new sf::RenderWindow(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Terraria");
}