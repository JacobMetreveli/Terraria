//
// Created by simteam-j on 9/5/24.
//

#ifndef TERRARIA_PLAYER_H
#define TERRARIA_PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
    // Constructor
    Player(float x, float y);

    void drawShape(sf::RenderWindow &window);

    // Get functions
    [[nodiscard]] sf::Vector2f getPos() const;
    [[nodiscard]] sf::Vector2f getShape() const;

    // Movement
    void move(float x, float y);
private:
    sf::RectangleShape* playerSprite{};

    void initPlayer();
};


#endif //TERRARIA_PLAYER_H
