#include <SFML/Graphics.hpp>
#include "renderer.hpp"
#include <math.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800u, 600u}), "Fractal Renderer");
    window.setFramerateLimit(60);

    Renderer renderer("shader.glsl");
    renderer.setView({-1.4,0},1.0);

//*********************************Animation*****************

    std::vector<sf::Vector2f> animationPoints = {
                    sf::Vector2f(-0.5, 0), 
                    sf::Vector2f(-1.7775487449761596, 0.01907162867211394),
                    sf::Vector2f(-1.7595343944256026, 0.01965574732072814),
                    sf::Vector2f(-1.7587797587414404, 0.019121479250630784)
                };
    std::vector<float> animationZooms = {
            1.0,
            10.f,
            600.f,
            45400.f
        };

//*********************************Animation*****************

    int animationStep = 1;
    float zoom = animationZooms[animationStep-1];
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        float progress = std::log(zoom) / std::log(animationZooms[animationStep]);
        progress = std::clamp(progress, 0.0f, 1.0f);
        
        sf::Vector2f position = animationPoints[animationStep-1] + (animationPoints[animationStep] - animationPoints[animationStep-1]) * sqrt(progress);
        
        if (zoom < animationZooms[animationStep]) {
            zoom *= 1.003;
        }
        else {
            if (animationStep<animationZooms.size()-1)
                animationStep++;
        }
        
                
        renderer.setView(position, zoom);
        window.clear();
        renderer.render(window);
        window.display();
    }
}