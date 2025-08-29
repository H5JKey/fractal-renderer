#include <SFML/Graphics.hpp>
#include "renderer.hpp"
#include "animation.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({800u, 600u}), "Fractal Renderer", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    Renderer renderer("shader.glsl");
    Animation animation;
    if (argc >= 2) {
       animation.loadFromFile(argv[1]);
    }

    
    sf::Vector2f center = {-0.5f, 0.0f};
    float zoom = 1.0f;
    sf::Clock timer;
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (!animation.isAnimating()) {
                if (event.type == sf::Event::MouseWheelMoved) {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    float windowWidth = static_cast<float>(window.getSize().x);
                    float windowHeight = static_cast<float>(window.getSize().y);
                    
                    sf::Vector2f fragCoord(mousePosition.x, windowHeight - mousePosition.y);
                    sf::Vector2f uv = (2.0f * fragCoord - sf::Vector2f(windowWidth, windowHeight)) / windowHeight;
                    
                    sf::Vector2f worldPosBefore = uv / zoom + center;
                    
                    if (event.mouseWheel.delta > 0) {
                        zoom *= 1.2f;
                    } else {
                        zoom *= 0.83f;
                    }
                    
                    sf::Vector2f worldPosAfter = uv / zoom + center;

                    center += worldPosBefore - worldPosAfter;
                }
            }
        }
        if (animation.isAnimating()) {
            animation.run(timer.restart());
            center = animation.getCurrentPoint();
            zoom = animation.getCurrentZoom();
        }
        
        renderer.setView(center, zoom);
        window.clear();
        renderer.render(window);
        window.display();
    }
}