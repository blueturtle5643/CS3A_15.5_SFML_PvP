#include "Creature.h"
#include <cstdlib>
#include <ctime>

void Creature::move(Creature *grid[][maxgridsize])
{
    srand(time(0));

    if (!get_moved() == true)   //if moved isn't true
    {
        vector<location> adjacent_squares = find_blank(grid);

        if (!adjacent_squares.empty())
        {
            // pick random adjacent square

            int randomresult = rand() % adjacent_squares.size();

            //cout << adjacent_squares.size() << endl;

            //cout << randomresult << endl;

            location destination = adjacent_squares[randomresult];

            //move to that location

            move_to(grid, destination);
        }
    }
}

void Creature::breed(Creature *grid[][maxgridsize])
{
    //the base creature class shouldn't handle breeding
}

void Creature::print() const
{

}

void Creature::move_to(Creature *grid[][maxgridsize], location destination)
{
    grid[destination._r][destination._c] = grid[_location._r][_location._c];

    //given destination, and the grid pointer pointing at creature object
    //changes values of grid to match with destination

    grid[_location._r][_location._c] = nullptr;

    //sets old creature location to nullptr

    set_moved(true);

    //creature is considered moved

    _location = destination;

    //the creatures location values are updated
}

int Creature::get_type() const
{
    return 0;   //does nothing
}

vector<location> Creature::find_blank(Creature *grid[][maxgridsize]) const
{
    vector<location> adjacent = find_adjacent(grid);

    //calls adjacent to find the 8 locations around the grid location

    vector<location> blanks;

    //temp storage for results

    //loops through adjacent vector to find nullptr positions aka blanks

    for (int i = 0; i < adjacent.size(); i++)
    {
        if (grid[adjacent[i]._r][adjacent[i]._c] == nullptr)
        {
            blanks.push_back(adjacent[i]);
        }
    }
    return blanks;
}

vector<location> Creature::find_this_creature
(Creature *grid[][maxgridsize], int type) const
{
    vector<location> adjacent = find_adjacent(grid);

    //calls adjacent to pull all 8 coordinates from vector

    vector<location> similar_creatures;

    //storage for result vector

    //loops through vector looks for locations that hold the same type
    //as the type passed in

    for (int i = 0; i < adjacent.size(); i++)
    {
        if (grid[adjacent[i]._r][adjacent[i]._c] != nullptr
        && grid[adjacent[i]._r][adjacent[i]._c]->get_type() == type)
        {
            similar_creatures.push_back(adjacent[i]);
        }
    }

    return similar_creatures;
}

vector<location> Creature::find_not_this_creature
(Creature *grid[][maxgridsize], int type) const
{
    vector<location> adjacent = find_adjacent(grid);

    //calls adjacent to find get 8 positions

    vector<location> dissimilar_creatures;

    for (int i = 0; i < adjacent.size(); i++)

    //loops through vector
    {
        if (grid[adjacent[i]._r][adjacent[i]._c] != nullptr
        && grid[adjacent[i]._r][adjacent[i]._c]->get_type() != type)

            //if the coords aren't null and if the type isn't the same type
            //as the type passed in
        {
            dissimilar_creatures.push_back(adjacent[i]);

            //coords get stored in another vector
        }
    }
    return dissimilar_creatures;
}

void Creature::kill(Creature *grid[][maxgridsize])
{
    grid[_location._r][_location._c] = nullptr;

    delete this;    //suicide function called from predator
}

void Creature::set_moved(bool value)
{
    _moved = value;   //sets for moved
}

bool Creature::get_moved() const
{
    return _moved;      //gets for moved
}

ostream &operator<<(ostream &outs, Creature *c)
{
    c->print();

    return outs;
}

vector<location> Creature::find_adjacent(Creature *grid[][maxgridsize]) const
{
    vector<location> adjacent_squares;

    //creates a vector and scans the 8 locations around the grid
    //stores the 8 locations and stores them in the vector

    //grids start from 0,0 on top left, addition of i is when rows go down
    //addition of j is when you go to the right aka columns

    //checks are clockwise starting from top left

    //greater than and less than are there to prevent walls from being factored

    if(_location._r - 1 > 0 && _location._c - 1 > 0)    //top left
    {
        adjacent_squares.push_back
                (location(_location._r - 1, _location._c - 1));
    }

    if(_location._r - 1 > 0)                            //top
    {
        adjacent_squares.push_back
                (location(_location._r - 1, _location._c));
    }

    if(_location._r - 1 > 0 && _location._c + 1 < maxgridsize - 1)    //topright
    {
        adjacent_squares.push_back
                (location(_location._r - 1, _location._c + 1));
    }

    if(_location._c + 1 < maxgridsize - 1)                            //right
    {
        adjacent_squares.push_back
                (location(_location._r, _location._c + 1));
    }

    if(_location._r + 1 < maxgridsize - 1 && _location._c + 1 < maxgridsize - 1)    //bottom right
    {
        adjacent_squares.push_back
                (location(_location._r + 1, _location._c + 1));
    }

    if(_location._r + 1 < maxgridsize - 1)                            //bottom
    {
        adjacent_squares.push_back
                (location(_location._r + 1, _location._c));
    }

    if(_location._r + 1 < maxgridsize - 1 && _location._c - 1 > 0)    //bottom left
    {
        adjacent_squares.push_back
                (location(_location._r + 1, _location._c - 1));
    }

    if(_location._c - 1 > 0)                            //left
    {
        adjacent_squares.push_back
                (location(_location._r, _location._c - 1));
    }

    return adjacent_squares;
}


void Creature::draw(sf::RenderWindow& window, location loc)
{

}
