//
// Created by konstantin on 18.04.2026.
//

#include "Hero.h"

#include <iostream>

sf::IntRect Hero::reflect(sf::IntRect rect) {
    return {rect.left+rect.width, rect.top, -rect.width, rect.height};
}

Hero::Hero(std::string texture_path, double speed, std::vector<sf::IntRect> rects, std::vector<std::string>& map)
    : _map(map)
{
    _texture.loadFromFile(texture_path);
    _speed = speed;
    _sprite.setTexture(_texture);
    _rects = rects;
    _currentRect = 0;
    _currentFrame = 0;
    _sprite.setTextureRect(_rects[0]);
    a = 10;
    _speedY = 0;
}

void Hero::update(double dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        _direction = Direction::left;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        _direction = Direction::right;
    } else {
        if (_direction != Direction::stay) {
            if (_direction == Direction::left) {
                _sprite.setTextureRect(reflect(_rects[0]));
            } else {
                _sprite.setTextureRect(_rects[0]);
            }
        }
        _direction = Direction::stay;
        _currentRect = 0;
        _currentFrame = 0;
    }

    if (_direction != Direction::stay) {
        _sprite.move(static_cast<int>(_direction)*dt*_speed,0);
        _currentFrame+=dt;
        if (_currentFrame >= 0.2) {
            _currentRect++;
            _currentRect%=_rects.size();
            if (_direction == Direction::left) {
                _sprite.setTextureRect(reflect(_rects[(_currentRect)]));
            } else {
                _sprite.setTextureRect(_rects[_currentRect]);
            }
            _currentFrame = 0;
        }
    }

    auto pos = getPosition();
    std::cout << "[" << pos.x << "," << pos.y << "]" << std::endl;
    // std::cout << int(_map[pos.x][pos.y+1]) << std::endl;
    if (_map[pos.y+1][pos.x] == ' ') {
        _speedY+=a*dt;
        _sprite.move(0,dt*_speedY);
    } else {
        _speedY = 0;
    }

}

void Hero::setPosition(int x, int y) {
    _sprite.setPosition(x*32, y*32);
}

sf::Vector2f Hero::getPosition() {
    auto pos = _sprite.getPosition();
    pos.x /=32;
    pos.y /=32;
    return pos;
}

void Hero::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}
