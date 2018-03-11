#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../includes/StoryPlayer.hpp"

int main()
{
    sp::StoryMap sm("resources/storyMap.sm");

    sp::StoryPlayer sp(sm);

    //mutex here ? 
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::Music buffer;

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            sp.update();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}