cmake_minimum_required(VERSION 3.29)
project(Terraria)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML COMPONENTS system window graphics REQUIRED)

add_executable(Terraria src/main.cpp
        src/StoneTile.cpp
        include/StoneTile.h
        src/Game.cpp
        include/Game.h
        src/Player.cpp
        include/Player.h
        src/Collider.cpp
        include/Collider.h)

include_directories(include)

target_link_libraries(Terraria sfml-system sfml-window sfml-graphics)