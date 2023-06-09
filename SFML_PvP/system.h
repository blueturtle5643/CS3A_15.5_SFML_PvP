#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "Grid.h"

using namespace std;
class System
{
public:
    System();
    void Step(int command);
    int Size();
    void Draw(sf::RenderWindow& widnow);
private:
//    vector<Particle> system;
    Grid grid;
    sf::CircleShape shape;
    sf::Vector2f vel;
};

#endif // SYSTEM_H
