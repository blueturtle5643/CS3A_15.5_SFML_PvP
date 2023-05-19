#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <vector>
#include "constants.h"
#include <SFML/Graphics.hpp>

    //max 2D array size 10x10

//const int CELL_SIZE = 50;

using namespace std;

struct location     //location object
{
    int _r;
                //row and column variables
    int _c;

    location(int row, int column) : _r(row), _c(column)
    {
                //constructor
    }
};

class Creature
{
    private:

        location _location;         //location object

        bool _moved;                //moved check

        vector<location> find_adjacent(Creature *grid[][maxgridsize]) const;

    public:

        Creature(location loc) : _location(loc), _moved(false)
        {
                //creates a creature object
                //with location object moved set to false
        }

        //Virtual functions

        virtual void move(Creature *grid[][maxgridsize]);

        virtual void breed(Creature *grid[][maxgridsize]);

        virtual void kill(Creature *grid[][maxgridsize]);

        virtual void print() const;

        virtual int get_type() const;

        virtual void draw(sf::RenderWindow& window, location loc);


        //sets and gets

        void set_moved(bool val);

        bool get_moved() const;


        //prints

        friend ostream &operator<<(ostream &outs, Creature *c);


        //move-to an function inside move

        void move_to(Creature *grid[][maxgridsize], location destination);


        //vector storage checks

        vector<location> find_blank(Creature *grid[][maxgridsize]) const;

        vector<location> find_this_creature(Creature *grid[][maxgridsize],
                                            int type) const;

        vector<location> find_not_this_creature(Creature *grid[][maxgridsize],
                                                int type) const;
};

#endif
