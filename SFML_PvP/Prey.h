#ifndef PREY_H
#define PREY_H

#include "Creature.h"

class Prey : public Creature
{
    private:

        int turns_since_last_bred;      //ticks up to breed

    public:

        Prey(location loc);     //creatures prey object at location

        virtual void move(Creature *grid[][maxgridsize]); //prey movement

        virtual void breed(Creature *grid[][maxgridsize]);  //prey breed

        virtual void kill(Creature *grid[][maxgridsize]);   //does nothing

        virtual void print() const;

        virtual int get_type() const;

        virtual void draw(sf::RenderWindow& window, location loc);
};

#endif
