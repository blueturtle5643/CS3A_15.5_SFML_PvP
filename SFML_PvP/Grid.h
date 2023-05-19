#ifndef GRID_H
#define GRID_H

#include "Creature.h"
#include <iostream>

using namespace std;

class Grid
{
    private:

        void fill_grid();   //initializes grid

        Creature *_grid[maxgridsize][maxgridsize];

        //pointer _grid that points at creature object at location of grid

        sf::RectangleShape rectangle[maxgridsize][maxgridsize];

    public:

        Grid();     //grid constructor

        ~Grid();

        void Step(); //movement and actions of all creatures

        bool Wincheck();

        friend ostream &operator<<(ostream &outs, const Grid &grid);

        void draw(sf::RenderWindow& window);

        void clear_grid();

        void spawn(int row, int col, bool draw_prey);


};

#endif
