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
        this->handleEvents();
        this->handleDisplay();
    }
}

void Game::handleEvents() {
    // Handle input keys
    while(window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Key::D) {
                    this->player->move(5, 0);
                }
                if (event.key.code == sf::Keyboard::Key::A) {
                    this->player->move(-5, 0);
                }
                if (event.key.code == sf::Keyboard::Key::W)
                    this->player->move(0, -5);
                if (event.key.code == sf::Keyboard::Key::S)
                    this->player->move(0, 5);
            default:
                break;
        }
//        if (event.type == sf::Event::Closed)
//            window->close();
//        else if (event.type == sf::Event::KeyPressed) {
//            if (event.key.code == sf::Keyboard::Key::D)
//                this->player->move(5, 0);
//        }
    }
}

void Game::handleDisplay() {
    window->clear();
    this->drawObjects();
    window->display();
}

void Game::initWindow() {
    window = new sf::RenderWindow(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Terraria");
}

void Game::initTextures() {
    if(!groundTexture.loadFromFile("../assets/tiles/Ground.png"))
        std::cout << "error opening file\n";
}

void Game::initPlayer() {
    player = new Player(700, 200);
}

void Game::generateGround() {
    for (int i = 0; i < WIN_WIDTH; i += 51) {
        for (int j = 250; j < WIN_HEIGHT; j += 51) {
            this->ground.emplace_back(float(i), float(j), this->groundTexture);
        }
    }
}

void Game::drawObjects() {
    // Draw ground
    for (auto tile: ground) {
        tile.drawShape(*window);
    }
    // Draw player
    this->player->drawShape(*window);
}