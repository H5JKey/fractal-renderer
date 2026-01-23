#include "renderer.hpp"


Renderer::Renderer(const std::string& path) {
    shader.loadFromFile(path, sf::Shader::Fragment);
    zoom = 1.0;
    center = {-0.5,0.0};
}

void Renderer::render(sf::RenderWindow& window) {
    shader.setUniform("u_resolution", static_cast<sf::Vector2f>(window.getSize()));
    shader.setUniform("u_center", center);
    shader.setUniform("u_zoom", zoom);
    
    sf::RectangleShape rect(sf::Vector2f(window.getSize()));
    window.draw(rect, &shader);
}

void Renderer::setView(sf::Vector2f center, float zoom) {
    this->center = center;
    this->zoom = zoom;
}