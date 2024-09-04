#include <iostream>
#include "StoneTile.h"

int StoneTile::initTexture() {
    if (!texture.loadFromFile("/home/simteam-j/Workspace/WEB/Terraria/assets/tiles/Ground.png"))
        return -1;
    sf::IntRect tileRect(0, 0, 32, 32);

    tile = new sf::Sprite;
    tile->setTexture(texture);
    tile->setTextureRect(tileRect);
    tile->setScale(this->width / (float)tileRect.width, this->height / (float)tileRect.height);

    return 0;
}

void StoneTile::initShape() {
    this->width = 50.f;
    this->height = 50.f;
}

StoneTile::StoneTile(float x, float y) {
    this->initShape();
    if (this->initTexture() == -1)
        std::cout << "Failed to load texture";
    this->tile->setPosition(x, y);
}

void StoneTile::draw_shape(sf::RenderWindow &window) {
    window.draw(*tile);
}

sf::Vector2f StoneTile::getPos() const {
    return this->tile->getPosition();
}