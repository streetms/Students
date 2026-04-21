#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "Hero.h"
#include "block.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");
    std::vector<sf::IntRect> rects = {
        sf::IntRect(0, 96, 32, 32),
        sf::IntRect(32,96, 32, 32),
        sf::IntRect(64,96, 32, 32),
        sf::IntRect(96,96, 32, 32),
    };
    Map map;
    map.loadFromFile("assets/levels/level1.txt");
    Block::setTexture("assets/images/blocks.png");
    auto hero = std::make_shared<Hero>("assets/images/hero.png",50,rects,map);
    std::vector<std::shared_ptr<sf::Drawable>> objects = {
         hero
    };

    for (int i = 0; i < map.getSize().x; i++) {
        for (int j = 0; j < map.getSize().y; j++) {
            if (map(i,j) == '#') {
                auto block = std::make_shared<Block>();
                block->setPosition(i,j);
                 objects.push_back(block);
            }
            if (map(i,j) == 'S') {
                hero->setPosition(j,i);
            }
        }
    }

    double currentFrame = 0;
    double speed = 50;
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        auto dt = clock.restart().asSeconds();

        hero->update(dt);
        window.clear(sf::Color::Black);
        for (auto& obj : objects ) {
            window.draw(*obj);
        }
        window.display();
    }
}