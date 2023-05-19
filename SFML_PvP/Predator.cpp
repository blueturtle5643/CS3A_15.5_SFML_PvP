#include "Predator.h"
#include "constants.h"

Predator::Predator(location loc) : Creature(loc), turns_since_last_bred(0),
    turns_since_last_ate(0)
{
    //created with location, counters set to 0
}

void Predator::move(Creature *grid[][maxgridsize])
{
    if (!get_moved() == true)   //if the object hasn't moved
    {
        vector<location> available_prey = find_this_creature(grid, 2);

        //uses findthiscreature with prey passed in as creature type
        //returns vector of locations of prey

        vector<location> available_blanks = find_blank(grid);

        //also does a check for empty spaces

        if (!available_prey.empty() == true)    //if there are available prey
        {
            int randomresult = rand() % available_prey.size();

            //creates random num from 0 to vector size aka possible choices

            location destination = available_prey[randomresult];

            //location object takes the index(random num) of the vector of
            //available prey

            delete grid[destination._r][destination._c]; //"eat" that prey

            move_to(grid, destination);

            turns_since_last_ate = 0;
        }

        else if(!available_blanks.empty() == true)  //if vector of blanks pops
        {
            int randomresult = rand() % available_blanks.size();

            location destination = available_blanks[randomresult];

            move_to(grid, destination);

            turns_since_last_ate++; //starve counter increases
        }
        turns_since_last_bred++;//breed counter increases
    }
}

void Predator::breed(Creature *grid[][maxgridsize])
{
    if (turns_since_last_bred >= 8) //if breed never popped properly
    {
        vector<location> blank_spaces = Creature::find_blank(grid);

        //looks for empty space to drop new baby

        if (!blank_spaces.empty() == true)  //if vector returns spaces
        {
            int randomresult = rand() % blank_spaces.size();

            location random_blank_space = blank_spaces[randomresult];

            grid[random_blank_space._r][random_blank_space._c]
                    = new Predator(random_blank_space);

            //new predator created at location, with location stored inside

            turns_since_last_bred = 0;
        }
    }
}

void Predator::kill(Creature *grid[][maxgridsize])
{
    if (turns_since_last_ate == 3)
    {
        Creature::kill(grid);   //suicide counter reaches designated number
    }                           //gets executed

    //alternate version where kill is called only here

//    if (turns_since_last_ate == 2)
//    {
//        delete this;
//    }
}

void Predator::print() const
{
    cout << "|x";
}

int Predator::get_type() const
{
    return 3;
}


//NEW STUFF

void Predator :: draw(sf::RenderWindow& window, location loc)
{
    sf::RectangleShape rectangle;

    int vectorY = loc._r * (GRID_HEIGHT + 1);

    int vectorX = loc._c * (GRID_WIDTH + 1);


    rectangle.setSize(sf::Vector2f(GRID_WIDTH, GRID_HEIGHT));

    rectangle.setPosition(sf::Vector2f(vectorX,vectorY));

    rectangle.setFillColor(sf::Color(255,0,0));

    window.draw(rectangle);
}
