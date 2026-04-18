//
// Created by konstantin on 18.04.2026.
//

#include "block.h"

Block::Block() {
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(sf::IntRect(273, 20, 96, 96));
    _sprite.setScale(sf::Vector2f(0.35, 0.35));
}

void Block::setTexture(std::string path) {
    _texture.loadFromFile(path);
}

void Block::setPosition(int x, int y) {
    _sprite.setPosition(sf::Vector2f((x*32), y*32));
}

void Block::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}
