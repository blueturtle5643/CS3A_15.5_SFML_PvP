/*********************************************************
* AUTHOR : Brian Ouyang
* PROJECT: Assignment # 15.5 : Chapter 15
* CLASS : CS 3A
* SECTION : MTH: 1:00p – 3:05p
* Due Date : 5/10/20
*********************************************************/
#include <iostream>
#include "animate.h"
using namespace std;
/**********************************************************
*
* Programming Project: Predator vs Prey
*_________________________________________________________
*
* Simulates game of life.
*_________________________________________________________
* INPUT:
*
* Takes any input to display the next state of the board
*
* OUTPUT:
*
* Current state of the board, message of one type of
* creature remains
*
* PROCESSING:
*
* Program iterates through a 2D array, executing specific
* actions for every object at the coordinate.
*
***********************************************************/

int main()
{
    animate game;

    game.run();



//    char option;

//    do

//    {
//        bool gameover = false;

//        srand(time(0));

//        Grid g;

//        cout << g << endl;

//        while(gameover == false)
//        {
//            g.Step();

//            cout << g << endl;

//            if(g.Wincheck() == true)
//            {
//                gameover = true;

//                break;
//            }

//            cin.get();
//        }

//        cout << "\nDo you want to repeat the calculation? Enter 'Y' or 'y': ";

//        cin >> option;
//    }

//    while (option == 'y' || option == 'Y');

//    return 0;

    cout<<endl<<endl<<"------ MAIN EXITING --------------------------"<<endl;

    return 0;
}
