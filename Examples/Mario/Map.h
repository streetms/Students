//
// Created by konstantin on 20.04.2026.
//

#ifndef MARIO_MAP_H
#define MARIO_MAP_H
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class Map {
    std::vector<std::string> _map;
    public:
    Map() = default;
    void loadFromFile(std::string fileName);
    char operator()(int i,int j);
    sf::Vector2u getSize();
};



#endif //MARIO_MAP_H
