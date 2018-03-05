#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../includes/StoryPlayer.hpp"
#include "../includes/StoryMap.hpp"

int main()
{
    StoryMap sm("resources/storyMap.sm");
    StoryMap smOther("resources/storyMap2.sm");

    StoryPlayer sp(sm);
    sp.addStoryMap(smOther);

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::Music buffer;

    GameComponents gameComponents = {
         &window,
         &buffer,
    };

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (gameComponents.window->isOpen())
    {
        sf::Event event;
        while (gameComponents.window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gameComponents.window->close();
            sp.update(&gameComponents);
        }

        gameComponents.window->clear();
        gameComponents.window->draw(shape);
        gameComponents.window->display();
    }

    return 0;
}