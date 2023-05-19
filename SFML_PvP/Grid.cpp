#include "Grid.h"
#include "Predator.h"
#include "Prey.h"
#include "Wall.h"
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "animate.h"
#include <cstdlib>

Grid::Grid()
{
    fill_grid();
}

Grid :: ~Grid()
{
    for (int i = 0; i < maxgridsize; i++)
    {
        for (int j = 0; j < maxgridsize; j++)
        {
            if (_grid[i][j])
            {
                delete _grid[i][j];
            }
        }
    }
}

void Grid::fill_grid()
{
    // fill top and bottom walls

    for (int i = 0; i < maxgridsize; i++)
    {
        _grid[0][i] = new Wall(location(0, i));

        _grid[maxgridsize - 1][i] = new Wall(location(maxgridsize - 1, i));
    }


    // fill left and right border

    for (int i = 1; i < maxgridsize - 1; i++)
    {
        _grid[i][0] = new Wall(location(i, 0));

        _grid[i][maxgridsize - 1] = new Wall(location(i, maxgridsize - 1));
    }


    // make everywhere else NULL

    for (int i = 1; i < maxgridsize - 1; i++)
    {
        for (int j = 1; j < maxgridsize - 1; j++)
        {
            _grid[i][j] = nullptr;
        }
    }


    // Fill in Preys and Predators

    const int maxprey = 400;

    const int maxpred = 200;

    int count_prey = 0;

    int count_predator = 0;

    while(count_prey != maxprey || count_predator != maxpred)
    {
        int random_row = ((rand() % maxgridsize - 2) + 1);
                                                    //limited between 1 and 8
        int random_column = ((rand() % maxgridsize - 2) + 1);

        if (_grid[random_row][random_column] == nullptr &&  //if its a nullptr
                count_prey != maxprey)                      //and maxprey still
        {                                                   //not reached
            _grid[random_row][random_column] =
                    new Prey(location(random_row, random_column));

            count_prey++;
        }

        else if (_grid[random_row][random_column] == nullptr)
        {
            _grid[random_row][random_column] =
                    new Predator(location(random_row, random_column));

            count_predator++;
        }
    }
}

void Grid::Step()
{
    /*
    Move:
        - Prey takes a random move

        - Predator either moves to a blank or onto an adjacent prey, killing it

    Breed:

        - Check counter/blank squares to see if it's time to breed

    Kill:

        - Predator starves after n turns
    */


    // perform all moves

    for (int i = 0; i < maxgridsize; i++)
    {
        for (int j = 0; j < maxgridsize; j++)
        {
            if (_grid[i][j])
            {
                // cout << *this << endl;

                _grid[i][j]->move(_grid);
            }
        }
    }

    //alternate where pred moves first

//    for (int i = 0; i < maxgridsize; i++)
//    {
//        for (int j = 0; j < maxgridsize; j++)
//        {
//            if (_grid[i][j]->get_type() == 3)
//            {
//                // cout << *this << endl;

//                _grid[i][j]->move(_grid);
//            }
//        }
//    }

    //alternate version where kill is done only in pred class

//    for (int i = 0; i < maxgridsize; i++)
//    {
//        for (int j = 0; j < maxgridsize; j++)
//        {
//            if (_grid[i][j])
//            {
//                _grid[i][j]->breed(_grid);

//                _grid[i][j]->kill(_grid);

//                _grid[i][j] = nullptr;
//            }
//        }
//    }

    // perform all breed & kills

    for (int i = 0; i < maxgridsize; i++)
    {
        for (int j = 0; j < maxgridsize; j++)
        {
            if (_grid[i][j])
            {
                _grid[i][j]->breed(_grid);

                _grid[i][j]->kill(_grid);
            }
        }
    }


    // reset all moved statuses

    for (int i = 0; i < maxgridsize; i++)
    {
        for (int j = 0; j < maxgridsize; j++)
        {
            if (_grid[i][j])
            {
                _grid[i][j]->set_moved(false);
            }
        }
    }
}

bool Grid :: Wincheck()
{
    int preyalivecheck = 0;

    int predalivecheck = 0;

    for (int i = 0; i < maxgridsize; i++)
    {
        for (int j = 0; j < maxgridsize; j++)
        {
            if (_grid[i][j])
            {
                if (_grid[i][j]->get_type() == 3)
                {
                    predalivecheck ++;
                }
                if (_grid[i][j]->get_type() == 2)
                {
                    preyalivecheck ++;
                }
            }
        }
    }

    if(predalivecheck == 0)
    {
        cout << "\nPrey Wins!" << endl;

        return true;
    }

    if(preyalivecheck == 0)
    {
        cout << "\nPredator Wins!" << endl;

        return true;
    }
}
ostream &operator<<(ostream &outs, const Grid &grid)
{
    for (int i = 0; i < maxgridsize; i++)
    {
        for (int j = 0; j < maxgridsize; j++)
        {
            if(grid._grid[i][j])
            {
                outs << grid._grid[i][j];
            }

            else
            {
                outs << "| ";
            }
        }
        outs << '|' << endl;
    }

    return outs;
}

void Grid::draw(sf::RenderWindow& window)
{
    Step();

    for (int row = 0; row < maxgridsize; row++)
    {
        for (int col = 0; col < maxgridsize; col++)
        {
             location loc(row, col);

             //window.draw(sf::RectangleShape(sf::Vector2f(maxgridsize0,maxgridsize0)));

            if(_grid[row][col] != nullptr)
            {
                _grid[row][col]->draw(window, loc);
            }


//            if(_grid[row][col]->draw() == 1)
//            {
//                rectangle[row][col].setFillColor(sf::Color::White);
//            }
//            if(_grid[row][col]->get_type() == 2)
//            {
//                rectangle[row][col].setFillColor(sf::Color(0,255,0));
//            }

//            if(_grid[row][col]->get_type() == 3)
//            {
//                rectangle[row][col].setFillColor(sf::Color(255,0,0));
//            }

//            int vectorY=row*(GRID_WIDTH+1);

//            int vectorX=col*(GRID_WIDTH+1);

//            rectangle[row][col].setSize(sf::Vector2f(GRID_WIDTH,GRID_WIDTH));

//            rectangle[row][col].setPosition(sf::Vector2f(vectorX,vectorY));

//            window.draw(rectangle[row][col]);
        }
    }
}

void Grid::clear_grid()
{
    for(int i = 1; i < maxgridsize - 1; i++)
    {
        for(int j = 1; j < maxgridsize - 1; j++)
        {
            if(_grid[i][j])
            {
                delete _grid[i][j];

                _grid[i][j] = nullptr;
            }
        }
    }
}

void Grid::spawn(int row, int col, bool draw_prey)
{
    if(_grid[row][col] == nullptr && draw_prey)     //if prey switch is flip
    {
        _grid[row][col] = new Prey(location(row, col)); //creates prey at loc
    }

    else if(_grid[row][col] == nullptr && !draw_prey)   //creates pred
    {
        _grid[row][col] = new Predator(location(row, col));
    }
}
