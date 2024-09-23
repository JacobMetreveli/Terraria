//
// Created by simteam-j on 9/5/24.
//

#include <iostream>
#include "Player.h"

Player::Player(float x, float y)
    : velocity(sf::Vector2f(0.f, 0.f)), dAcc(2.f)
{
    this->body = new sf::RectangleShape(sf::Vector2f(30, 80));
    this->body->setPosition(500, 240);
    this->velocity = sf::Vector2f(0.f, 0.f);
}

void Player::handleMovement(sf::Event ev) {
    sf::Vector2f acceleration(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        acceleration.x += dAcc;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        acceleration.x -= dAcc;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        acceleration.y -= dAcc;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        acceleration.y += dAcc;

    this->velocity += acceleration;
    this->body->setPosition(this->getPos() + this->velocity);
    this->velocity *= 0.1f;
}

void Player::drawShape(sf::RenderWindow &window) {
    window.draw(*this->body);
}

// Setter functions

// Getter functions
sf::Vector2f Player::getPos() const {
    return {this->body->getPosition()};
}

sf::Vector2f Player::getShape() const {
    return {this->body->getSize()};
}

sf::Vector2f Player::getVelocity() const {
    return this->velocity;
}