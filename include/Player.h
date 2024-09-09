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

    // Getter functions
    [[nodiscard]] sf::Vector2f getPos() const;
    [[nodiscard]] sf::Vector2f getShape() const;
    [[nodiscard]] sf::Vector2f getVelocity() const;

    // Setter functions

    // Movement
    void handleMovement(sf::Event ev);

private:
    sf::RectangleShape* playerSprite{};
    sf::Vector2f velocity{};

    void initPlayer();
};


#endif //TERRARIA_PLAYER_H
