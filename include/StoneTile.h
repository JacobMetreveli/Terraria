#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"

class StoneTile {
public:
    StoneTile(float x, float y, const sf::Texture& texture);

    void drawShape(sf::RenderWindow &window);

    [[nodiscard]] sf::Vector2f getPos() const;
    [[nodiscard]] sf::Vector2f getShape() const;

private:
    sf::Sprite* tile{};
    float width{};
    float height{};

    void initShape();
    void initTexture(const sf::Texture& texture);
};