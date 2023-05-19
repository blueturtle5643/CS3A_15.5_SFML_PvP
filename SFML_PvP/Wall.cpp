#include "Wall.h"
#include "constants.h"

Wall::Wall(location loc) : Creature(loc)
{
    //wall created with location
}

//wall functions exist so that when the 2D array iterates through
//and detects a wall, it would call the virtual functions instead of normal
//functions

void Wall::move(Creature *grid[][maxgridsize])
{
    //empty
}

void Wall::breed(Creature *grid[][maxgridsize])
{
    //empty
}

void Wall::kill(Creature *grid[][maxgridsize])
{
    //empty
}

void Wall::print() const
{
    cout << "|Z";
}

int Wall::get_type() const
{
    return 1;
}

void Wall :: draw(sf::RenderWindow& window, location loc)
{
    sf::RectangleShape rectangle;

    int vectorY = loc._r * (GRID_HEIGHT + 1);

    int vectorX = loc._c * (GRID_WIDTH + 1);


    rectangle.setSize(sf::Vector2f(GRID_WIDTH, GRID_HEIGHT));

    rectangle.setPosition(sf::Vector2f(vectorX,vectorY));

    rectangle.setFillColor(sf::Color(200,200,200));

    window.draw(rectangle);
}
