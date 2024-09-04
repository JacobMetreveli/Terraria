#pragma once
#include <SFML/Graphics.hpp>

class StoneTile {
public:
    StoneTile(float x, float y);

    [[nodiscard]] sf::Vector2f getPos() const;
    void draw_shape(sf::RenderWindow &window);

private:
    sf::Sprite* tile{};
    sf::Texture texture{};
    float width{};
    float height{};

    void initShape();
    int initTexture();
};