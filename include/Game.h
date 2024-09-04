//
// Created by simteam-j on 9/4/24.
//

#ifndef TERRARIA_GAME_H
#define TERRARIA_GAME_H

#include <SFML/Graphics.hpp>

#define WIN_WIDTH 960
#define WIN_HEIGHT 540

class Game {
public:
    Game();
    void run();

private:
    sf::RenderWindow* window;
    sf::Event event;

    void handleEvents();
    void handleDisplay();

    void initWindow();
};


#endif //TERRARIA_GAME_H
