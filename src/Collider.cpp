//
// Created by simteam-j on 9/23/24.
//

#include "Collider.h"

Collider::Collider(sf::RectangleShape &body)
    :body(body) {
}

Collider::~Collider() = default;

bool Collider::CheckCollision(Collider &other, float push) {
    sf::Vector2f otherPosition = other.GetPosition();
    sf::Vector2f otherHalfSize = other.GetHalfSize();
    sf::Vector2f thisPosition = this->GetPosition();
    sf::Vector2f thisHalfSize = this->GetHalfSize();

    // Check if the objects intersect with each other using AABB collision
    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;
    float intersectX = std::abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
    float intersectY = std::abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

    if (intersectX < 0.0f && intersectY < 0.0f) {
        push = std::min(std::max(push, 0.0f), 1.0f);

        if (intersectX > intersectY) {
            if (deltaX > 0.0f) {
                this->Move(intersectX * (1.0f - push), 0.0f);
                other.Move(-intersectX * push, 0.0f);
            } else {
                this->Move(-intersectX * (1.0f - push), 0.0f);
                other.Move(intersectX * push, 0.0f);
            }
        } else {
            if (deltaY > 0.0f) {
                this->Move(0.0f, intersectY * (1.0f - push));
                other.Move(0.0f, -intersectY * push);
            } else {
                this->Move(0.0f, -intersectY * (1.0f - push));
                other.Move(0.0f, intersectY * push);
            }
        }

        return true;
    }

    return false;
}