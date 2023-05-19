#ifndef WALL_H
#define WALL_H

#include "Creature.h"

class Wall : public Creature
{
    public:

        Wall(location loc);  //pretty much all of these functions do nothing

        virtual void move(Creature *grid[][maxgridsize]);

        virtual void breed(Creature *grid[][maxgridsize]);

        virtual void kill(Creature *grid[][maxgridsize]);

        virtual void print() const;

        virtual int get_type() const;

        virtual void draw(sf::RenderWindow& window, location loc);
};

#endif
