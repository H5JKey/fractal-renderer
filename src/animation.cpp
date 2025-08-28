#include "animation.hpp"
#include <fstream>

Animation::Animation(const std::string& configFilePath) {
    step = 1;
    std::ifstream fin(configFilePath);
    if (!fin.is_open()) throw std::runtime_error("No such file: "+configFilePath);
    double x, y, zoom;
    while (fin>>x>>y>>zoom) {
        points.push_back(sf::Vector2f(x,y));
        zooms.push_back(zoom);
    }
    speed = 0.4;
    fin.close();
}

sf::Vector2f Animation::getCurrentPoint() const {
    return points[step-1]+(points[step] - points[step-1])*progress;
}

float Animation::getCurrentZoom() const {
    return zooms[step-1]+(zooms[step] - zooms[step-1])*progress;
}

void Animation::run(sf::Time ellapsedTime) {
    progress+=ellapsedTime.asSeconds()*speed;
    if (progress>1) {
        if (step<zooms.size()-1) {
            progress = 0;
            step+=1;
        }
    }
}