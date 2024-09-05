#include <iostream>
#include "StoneTile.h"

void StoneTile::initTexture(const sf::Texture& texture) {
    // Initialize sprite
    tile = new sf::Sprite;
    tile->setTexture(texture);
    // Pick the texture that I need
    sf::IntRect tileRect(0, 0, 32, 32);
    tile->setTextureRect(tileRect);
    // Scale the tile
    tile->setScale(this->width / (float)tileRect.width, this->height / (float)tileRect.height);
}

void StoneTile::initShape() {
    this->width = 50.f;
    this->height = 50.f;
}

StoneTile::StoneTile(float x, float y, const sf::Texture& texture) {
    this->initShape();
    this->initTexture(texture);

    this->tile->setPosition(x, y);
}

void StoneTile::drawShape(sf::RenderWindow &window) {
    window.draw(*this->tile);
}

sf::Vector2f StoneTile::getPos() const {
    return this->tile->getPosition();
}

sf::Vector2f StoneTile::getShape() const {
    return {float(this->width), (float)this->height};
}