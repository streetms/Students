//
// Created by konstantin on 18.04.2026.
//

#ifndef MARIO_HERO_H
#define MARIO_HERO_H
#include <SFML/Graphics.hpp>
#include "map.h"

class Hero : public sf::Drawable {
    enum class State {left=-1,stay=0, right=1};
    sf::Texture _texture;
    sf::Sprite _sprite;
    double _speed;
    double _speedY;
    double _speedX;
    std::vector<sf::IntRect> _rects;
    double _currentFrame;
    int _currentRect;
    sf::IntRect reflect(sf::IntRect rect);
    State _state;
    Map _map;
    double a;
    void animate(double dt);
    public:
    Hero(std::string texture_path, double speed, std::vector<sf::IntRect> rects,Map& map);
    void update(double dt);
    void setPosition(int x, int y);
    sf::Vector2f getPosition();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};



#endif //MARIO_HERO_H
