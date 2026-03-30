#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({600,600}), "Snowflake");
    sf::Texture texture;
    //вставить правильный путь до файла с картинкой
    texture.loadFromFile("/home/konstantin/CLionProjects/Students/Examples/snowflake/img.png");
    sf::Sprite snowflake(texture);
    snowflake.setScale(0.05,0.05);
    float speed = 10.f;
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed
                and event.mouseButton.button == sf::Mouse::Left) {
                if (snowflake.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    speed+=50;
                }
            }
        }
        float dt = clock.restart().asSeconds();
        window.clear(sf::Color::Black);
        snowflake.move(0,speed * dt);
        window.draw(snowflake);
        window.display();
    }
}