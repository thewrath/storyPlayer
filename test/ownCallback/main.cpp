#include <SFML/Graphics.hpp>
#include "../../includes/StoryPlayer.hpp"

int main()
{   

    sp::StoryPlayer storyplayer;
    sp::StoryMap sm("resources/storymap.sm"); 
    storyplayer.addStoryMap(sm);
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        storyplayer.update();
        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}