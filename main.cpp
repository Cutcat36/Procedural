#include "GameMath.h"
#include "Window.cpp"



int main()
{
    
    Window window(1920, 1080);
    Body body;

    sf::RectangleShape rect(sf::Vector2f(200, 200));
    rect.setPosition(0, 0);
    rect.setFillColor(sf::Color::White);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            window.move(-10, 0);
            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {            
            window.move(10, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            window.move(0, 10);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            window.move(0, -10);
        }
       
        window.update(body);
    }

    return 0;
}