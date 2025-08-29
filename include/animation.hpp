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
    bool m_isAnimating;
public:
    float getCurrentZoom() const;
    sf::Vector2f getCurrentPoint() const;
    Animation();
    void run(sf::Time ellapsedTime);
    void loadFromFile(const std::string& configFilePath);
    bool isAnimating();
};