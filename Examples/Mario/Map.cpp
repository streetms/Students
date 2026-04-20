//
// Created by konstantin on 20.04.2026.
//

#include "Map.h"
#include <fstream>
void Map::loadFromFile(std::string fileName) {
    std::ifstream fin(fileName);
    if (not fin.is_open()) {
        throw std::runtime_error("Cannot open file");
    }
    std::string line;
    while (std::getline(fin,line)) {
        _map.push_back(line);
    }
    _map.pop_back();
}

char Map::operator()(int i, int j) {
    return _map[j][i];
}

sf::Vector2u Map::getSize() {
    return sf::Vector2u(_map[0].size(),_map.size());
}
