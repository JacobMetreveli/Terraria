//
// Created by simteam-j on 9/4/24.
//

#ifndef TERRARIA_GAME_H
#define TERRARIA_GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "StoneTile.h"
#include "Player.h"

#define WIN_WIDTH 960
#define WIN_HEIGHT 540

class Game {
public:
    Game();
    void run();

private:
    sf::RenderWindow* window{};
    sf::Event event{};

    // Textures
    sf::Texture groundTexture;

    // Game objects
    std::vector<StoneTile> ground;
    Player* player{};

    // Event handlers
    void handleMovement();
    void handleEvents();
    void handleDisplay();

    // Draw objects
    void drawObjects();

    //Initialize functions
    void initWindow();
    void initTextures();
    void initPlayer();

    void generateGround();
};


#endif //TERRARIA_GAME_H
