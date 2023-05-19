#include "animate.h"
#include "constants.h"
#include "Grid.h"
#include <iostream>
using namespace std;
//#include "system.h"


animate::animate()

{
    command = 0;

    pause_animation = false;

    //cout<<"animate CTOR: TOP"<<endl;

    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML window!");

    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.

    //System will be implemented to manage a vector of objects to be animated.
    //  at that point, the constructor of the System class will take a vector
    //  of objects created by the animate object.
    //  animate will
    //system = System();
    //window.setFramerateLimit(2);

    //window.setFramerateLimit(-500);

    window.setFramerateLimit(60);

    mouseIn = true;




    //    mousePoint = sf::CircleShape();
    //    mousePoint.setRadius(5.0);
    //    mousePoint.setFillColor(sf::Color::Red);

    //cout<<"Geme CTOR. preparing to load the font."<<endl;
    //--- FONT ----------
    //font file must be in the "working directory:
    //      debug folder
    //Make sure working directory is where it should be and not
    //  inside the app file:
    //  Project->RUN->Working Folder
    //
    //font must be a member of the class.
    //  Will not work with a local declaration

//    if (!font.loadFromFile("arial.ttf"))
//    {
//        cout<<"animate() CTOR: Font failed to load"<<endl;
//        cin.get();
//        exit(-1);
//    }

    //    myTextLabel = sf::Text("Initial String for myTextLabel", font);
    //    myTextLabel.setCharacterSize(20);
    //    myTextLabel.setStyle(sf::Text::Bold);
    //    myTextLabel.setColor(sf::Color::Green);
    //    myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-5));







    cout<<"animate instantiated successfully."<<endl;
}

void animate::Draw()
{
    if(command == 1) // clear the grid
    {
        _grid.clear_grid();

        command = 0;    //important to reset
    }



    //Look at the data and based on the data, draw shapes on window object.

    _grid.draw(window); //I guess this draws with grid


    //- - - - - - - - - - - - - - - - - - -
    //getPosition() gives you screen coords, getPosition(window) gives you window coords
    //cout<<"mosue pos: "<<sf::Mouse::getPosition(window).x<<", "<<sf::Mouse::getPosition(window).y<<endl;
    //- - - - - - - - - - - - - - - - - - -

    //drawing Test: . . . . . . . . . . . .
    //This is how you draw text:)
    //window.draw(myTextLabel);
    //. . . . . . . . . . . . . . . . . . .
}

void animate::update()
{
    //cause changes to the data for the next frame
    // _grid.Step(command);
    //    command = 0;
    //    if (mouseIn)
    //    {
    //        //mousePoint red dot:
    //        mousePoint.setPosition(sf::Mouse::getPosition(window).x-5,
    //                               sf::Mouse::getPosition(window).y-5);
    //    }
}
void animate::render()
{
    window.clear();

    //cout << "1";

    Draw();

    window.display();
}



void animate::processEvents()
{
    sf::Event event;

    float mouseX, mouseY;

    while (window.pollEvent(event))//or waitEvent
    {
        // check the type of the event...
        switch (event.type)
        {
        // window closed
        case sf::Event::Closed:
            window.close();
            break;

            // key pressed
        case sf::Event::KeyPressed:
            switch(event.key.code)
            {
            case sf::Keyboard::C:

                command = 1;

                break;

            case sf::Keyboard::P:

                if(pause_animation == true)
                {
                    pause_animation = false;
                }

                else
                {
                    pause_animation = true;
                }

                break;

            case sf::Keyboard::Escape:
                window.close();
                break;
            }
            break;
        case sf::Event::MouseEntered:
            mouseIn = true;
            break;

        case sf::Event::MouseLeft:
            mouseIn = false;
            break;

        case sf::Event::MouseMoved:
            mouseX = event.mouseMove.x;
            mouseY = event.mouseMove.y;
            //Do something with it if you need to...
            break;
        case sf::Event::MouseButtonReleased:
        {
            bool spawn_prey = true; //auto default to true

            if (event.mouseButton.button == sf::Mouse::Right)   //rightclick
            {
                spawn_prey = false; //means pred will spawn
            }
            else
            {
                spawn_prey = true;
            }
            int x = sf::Mouse::getPosition(window).x;
                                                        //gets coords
            int y = sf::Mouse::getPosition(window).y;
            /*
                            sf::RectangleShape rect;
                            rect.setSize(sf::Vector2f(GRID_WIDTH,GRID_WIDTH));
                            for(int i = 0; i < maxgridsize; i++)
                                for(int j = 0; j < maxgridsize; j++)
                                {
        rect.setPosition(sf::Vector2f(i*GRID_HEIGHT + 1, j*GRID_WIDTH + 1));
               if(rect.getGlobalBounds().contains(sf::Vector2f(x, y)));
                                        _grid.spawn(i, j, spawn_prey);
                                }
                            */
            int upper_bound;

            int lower_bound;
                                //basically the max x and y of the square
            int left_bound;

            int right_bound;

            for(int i = 0; i < maxgridsize; i++)
            {
                upper_bound = GRID_HEIGHT * i;

                lower_bound = upper_bound + GRID_HEIGHT;

                for(int j = 0; j < maxgridsize; j++)
                {
                    left_bound = j * GRID_WIDTH;

                    right_bound = left_bound + GRID_WIDTH;

                    if(x >= left_bound && x <= right_bound &&
                            y >= upper_bound && y <= lower_bound)

                        _grid.spawn(i, j, spawn_prey);  //if coords are within
                }                                       //location, spawn
            }

            break;

        }

        default:
            break;
        }
    }
}
void animate::run()
{
    while (window.isOpen())
    {
        processEvents();

        //update();

        //Draw();

        if(!pause_animation)
            render(); //clear/draw/display
    }
    cout<<endl<<"-------ANIMATE MAIN LOOP EXITING ------------"<<endl;
}

string mouse_pos_string(sf::RenderWindow& window)
{
    return "(" +
            to_string(sf::Mouse::getPosition(window).x) +
            ", " +
            to_string(sf::Mouse::getPosition(window).y) +
            ")";
}
