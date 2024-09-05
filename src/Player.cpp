//
// Created by simteam-j on 9/5/24.
//

#include "Player.h"

Player::Player(float x, float y) {
    this->initPlayer();
}

void Player::initPlayer() {
    this->playerSprite = new sf::RectangleShape(sf::Vector2f(30, 80));
    this->playerSprite->setPosition(500, 240);
}

void Player::move(float x, float y) {
    this->playerSprite->setPosition(this->getPos() + sf::Vector2f(x, y));
}

void Player::drawShape(sf::RenderWindow &window) {
    window.draw(*this->playerSprite);
}

sf::Vector2f Player::getPos() const {
    return {this->playerSprite->getPosition()};
}

sf::Vector2f Player::getShape() const {
    return {this->playerSprite->getSize()};
}