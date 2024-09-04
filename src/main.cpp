#include <SFML/Graphics.hpp>
#include "StoneTile.h"
#include <vector>

#define WIN_WIDTH 960
#define WIN_HEIGHT 540

std::vector<StoneTile> generateGround() {
    std::vector<StoneTile> tiles;
    for (int i = 0; i < WIN_WIDTH; i+=51) {
        for (int j = 300; j < WIN_HEIGHT; j+=51) {
            tiles.emplace_back((float)i, (float)j);
        }
    }
    return tiles;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Terraria");
    sf::CircleShape shape(100.f);
    std::vector<StoneTile> tiles = generateGround();

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (auto tile: tiles) {
            tile.draw_shape(window);
        }

        window.display();
    }
}
