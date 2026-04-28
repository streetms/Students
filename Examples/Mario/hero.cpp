//
// Created by konstantin on 18.04.2026.
//

#include "hero.h"

#include <iostream>

sf::IntRect Hero::reflect(sf::IntRect rect) {
    return {rect.left+rect.width, rect.top, -rect.width, rect.height};
}

Hero::Hero(std::string texture_path, double speed, std::vector<sf::IntRect> rects, Map& map)
    : _map(map)
{
    _texture.loadFromFile(texture_path);
    _speed = speed;
    _sprite.setTexture(_texture);
    _rects = rects;
    _currentRect = 0;
    _currentFrame = 0;
    _sprite.setTextureRect(_rects[0]);
    a = 100;
    _speedY = 0;
    _sprite.setOrigin(16,0);
}

void Hero::update(double dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        _state = State::left;
        _speedX = -_speed;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        _state = State::right;
        _speedX = _speed;
    } else {
        if (_state != State::stay) {
            if (_state == State::left) {
                _sprite.setTextureRect(reflect(_rects[0]));
            } else {
                _sprite.setTextureRect(_rects[0]);
            }
        }
        _speedX = 0;
        _state = State::stay;
        _currentRect = 0;
        _currentFrame = 0;
    }
    if (_state != State::stay) {
        animate(dt);
    }
    auto pos = getPosition();
    if (_map(pos.x,pos.y+1) == ' ') {
        _speedY+=a*dt;
    } else if (_speedY > 0){
        _speedY = 0;
    }
    _sprite.move(dt * _speedX, dt*_speedY);
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

void Hero::animate(double dt) {
    _currentFrame+=dt;
    if (_currentFrame >= 0.2) {
        _currentRect++;
        _currentRect%=_rects.size();
        if (_state == State::left) {
            _sprite.setTextureRect(reflect(_rects[(_currentRect)]));
        } else {
            _sprite.setTextureRect(_rects[_currentRect]);
        }
        _currentFrame = 0;
    }
}
