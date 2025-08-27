#include <SFML/Graphics.hpp>
#include <string>


class Renderer {
private:
    sf::Shader shader;
    sf::Vector2f center;
    float zoom;
public:
    Renderer(const std::string& path);
    void render(sf::RenderWindow& window);

    void setView(sf::Vector2f center, float zoom);
};