#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "Hero.h"
#include "block.h"
std::vector<std::string> map{
    "  S                        ",
    "                           ",
    "                           ",
    "                           ",
    "  #                        ",
    "                           ",
    "                           ",
    "                           ",
    "                           ",
    "                           ",
    "                           ",
    "                       #   ",
    "                       #   ",
    "####################  #####",
    "                           ",
    "                           "
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");
    std::vector<sf::IntRect> rects = {
        sf::IntRect(0, 96, 32, 32),
        sf::IntRect(32,96, 32, 32),
        sf::IntRect(64,96, 32, 32),
        sf::IntRect(96,96, 32, 32),
    };
    Block::setTexture("/home/konstantin/CLionProjects/Students/Examples/Mario/images/blocks.png");
    auto hero = std::make_shared<Hero>("/home/konstantin/CLionProjects/Students/Examples/Mario/images/hero.png",50,rects,map);

    // Block block;
    std::vector<std::shared_ptr<sf::Drawable>> objects = {
         hero
    };

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j] == '#') {
                auto block = std::make_shared<Block>();
                block->setPosition(j,i);
                 objects.push_back(block);
            }
            if (map[i][j] == 'S') {
                // std::make_shared<Hero>("/home/konstantin/CLionProjects/Students/Examples/Mario/images/hero.png",50,rects);

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