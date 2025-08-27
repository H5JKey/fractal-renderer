#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Animation {
private:
    std::vector<sf::Vector2f> points;
    std::vector<float> zooms;
    float speed;
    int step;
    float progress;
public:
    float getCurrentZoom() const;
    sf::Vector2f getCurrentPoint() const;
    Animation(const std::string& configFilePath);
    void run(sf::Time ellapsedTime);
};