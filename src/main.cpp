#include <SFML/Graphics.hpp>
#include "renderer.hpp"
#include "animation.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    sf::RenderWindow window(sf::VideoMode({800u, 600u}), "Fractal Renderer");
    window.setFramerateLimit(60);

    Renderer renderer("shader.glsl");

    if (argc<2) {
        std::cerr << "Usage: " << argv[0] << " <animation_config_file>" << std::endl;
        return 1;
    }
    Animation animation(argv[1]);

    sf::Clock timer;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        renderer.setView(animation.getCurrentPoint(), animation.getCurrentZoom());
        animation.run(timer.restart());
        window.clear();
        renderer.render(window);
        window.display();
    }
}