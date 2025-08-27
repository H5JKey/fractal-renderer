#include "renderer.hpp"


Renderer::Renderer(const std::string& path) {
    shader.loadFromFile(path, sf::Shader::Fragment);
    zoom = 1.0;
    center = {-0.5,0.0};
}

void Renderer::render(sf::RenderWindow& window) {
    shader.setUniform("u_resolution", sf::Vector2f(window.getSize()));
    shader.setUniform("u_center", center);
    shader.setUniform("u_zoom", zoom);
    
    sf::RenderTexture tex;
	tex.create(window.getSize().x, window.getSize().y);
	sf::Sprite spr(tex.getTexture());
    spr.setScale(1, -1);
    spr.setPosition(0, window.getSize().y);

    tex.draw(spr, &shader);
    window.draw(spr);
}

void Renderer::setView(sf::Vector2f center, float zoom) {
    this->center = center;
    this->zoom = zoom;
}