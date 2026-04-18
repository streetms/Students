//
// Created by konstantin on 18.04.2026.
//

#ifndef MARIO_BLOCK_H
#define MARIO_BLOCK_H
#include <string>
#include <SFML/Graphics.hpp>


class Block : public sf::Drawable {
    static inline sf::Texture _texture;
    sf::Sprite _sprite;

    public:
     Block();
    static void setTexture(std::string path);
    void setPosition(int x, int y);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};



#endif //MARIO_BLOCK_H
