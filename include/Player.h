//
// Created by simteam-j on 9/5/24.
//

#ifndef TERRARIA_PLAYER_H
#define TERRARIA_PLAYER_H

#include <SFML/Graphics.hpp>
#include "Collider.h"

class Player {
public:
    // Constructor
    Player(float x, float y);

    void drawShape(sf::RenderWindow &window);

    // Movement
    void handleMovement(sf::Event ev);

    Collider GetCollider() {return Collider(*body);};

    // Getter functions
    [[nodiscard]] sf::Vector2f getPos() const;
    [[nodiscard]] sf::Vector2f getShape() const;
    [[nodiscard]] sf::Vector2f getVelocity() const;

    // Setter functions

private:
    sf::RectangleShape* body{};
    sf::Vector2f velocity{};
    const float dAcc;
};


#endif //TERRARIA_PLAYER_H
