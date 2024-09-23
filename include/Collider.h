//
// Created by simteam-j on 9/23/24.
//

#ifndef TERRARIA_COLLIDER_H
#define TERRARIA_COLLIDER_H

#include <SFML/Graphics.hpp>

class Collider {
public:

    explicit Collider(sf::RectangleShape& body);
    explicit Collider(sf::Sprite& body);

    ~Collider();

    void Move(float dx, float dy) {body.move(dx, dy);}

    bool CheckCollision(Collider& other, float push);
    sf::Vector2f GetPosition() {return body.getPosition();}
    sf::Vector2f GetHalfSize() {return body.getSize() / 2.0f;}

private:
    sf::RectangleShape& body;
};


#endif //TERRARIA_COLLIDER_H
