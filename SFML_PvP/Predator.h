#ifndef PREDATOR_H
#define PREDATOR_H

#include "Creature.h"

class Predator : public Creature
{
    private:

        int turns_since_last_bred;  //breed counter ticks up to 8 for breed

        int turns_since_last_ate;   //starvation counter ticks up to die

    public:

        Predator(location loc);     //creates predator subclass at that loc

        virtual void move(Creature *grid[][maxgridsize]);   //move and kill

        virtual void breed(Creature *grid[][maxgridsize]);  //breed logic

        virtual void kill(Creature *grid[][maxgridsize]);   //starvation logic

        virtual void print() const;

        virtual int get_type() const;   //gets specific type of creature


        //NEW STUFF

        virtual void draw(sf::RenderWindow& window, location loc);

};

#endif
