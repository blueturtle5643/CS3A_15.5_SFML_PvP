#include "Prey.h"
#include "constants.h"
#include <cstdlib>
#include <iostream>

Prey::Prey(location loc) : Creature(loc), turns_since_last_bred(0)
{
    //creates prey with location and turn set to 0
}

void Prey::move(Creature *grid[][maxgridsize])
{
    if(!get_moved() == true)    //inverse of moved aka if it hasn't moved
    {
        Creature::move(grid);   //calls parent class move

        turns_since_last_bred++;    //adds onto breed counter
    }
}

void Prey::breed(Creature *grid[][maxgridsize])
{
    if (turns_since_last_bred >= 3) //if breed counter is higher than 3
    {                               //(no space to breed previously)

        vector<location> blank_spaces = Creature::find_blank(grid);

        if (!blank_spaces.empty())  //if the vector isn't empty
        {
            int randomresult = rand() % blank_spaces.size();

            //creates a random num from 0 to the size of vector

            location random_blank_space = blank_spaces[randomresult];

            //singular grid coordinates stored inside location

            grid[random_blank_space._r][random_blank_space._c] =
                    new Prey(random_blank_space);

            //new prey created at location assigned with location as well

            turns_since_last_bred = 0;

            //breed counter set to 0
        }
    }
}

void Prey::kill(Creature *grid[][maxgridsize])
{
    //empty
}

void Prey::print() const
{
    cout << "|o";
}

int Prey::get_type() const
{
    return 2;
}

void Prey :: draw(sf::RenderWindow& window, location loc)
{
    sf::RectangleShape rectangle;

    int vectorY = loc._r * (GRID_HEIGHT + 1);

    int vectorX = loc._c * (GRID_WIDTH + 1);


    rectangle.setSize(sf::Vector2f(GRID_WIDTH, GRID_HEIGHT));

    rectangle.setPosition(sf::Vector2f(vectorX,vectorY));

    rectangle.setFillColor(sf::Color(0,255,0));

    window.draw(rectangle);
}
