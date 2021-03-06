#include <iostream>
#include "cscreen.h"

#include <SFML/Graphics.hpp>

class screen_game : public cscreen
{
private:
    float movement_step;
    float posx;
    float posy;
    sf::RectangleShape Rectangle;
public:
    screen_game(void);
    virtual int Run(sf::RenderWindow &App);
};

screen_game::screen_game(void)
{
    movement_step = 5;
    posx = 320;
    posy = 240;
    //Setting sprite
    Rectangle.setFillColor(sf::Color(255, 255, 255, 150));
    Rectangle.setSize(sf::Vector2f(10,10));
}

int screen_game::Run(sf::RenderWindow &App)
{
    sf::Event Event;
    bool Running = true;

    while (Running)
    {
        //Verifying events
        while (App.pollEvent(Event))
        {
            // Window closed
            if (Event.type == sf::Event::Closed)
            {
                return (-1);
            }
            //Key pressed
            if (Event.type == sf::Event::KeyPressed)
            {
                switch (Event.key.code)
                {
                case sf::Keyboard::Escape:
                    return (0);
                    break;
                case sf::Keyboard::Up:
                    posy -= movement_step;
                    break;
                case sf::Keyboard::Down:
                    posy += movement_step;
                    break;
                case sf::Keyboard::Left:
                    posx -= movement_step;
                    break;
                case sf::Keyboard::Right:
                    posx += movement_step;
                    break;
                default:
                    break;
                }
            }
        }

        //Updating
        if (posx>630)
            posx = 630;
        if (posx<0)
            posx = 0;
        if (posy>470)
            posy = 470;
        if (posy<0)
            posy = 0;
        Rectangle.setPosition( posx, posy );

        //Clearing screen
        App.clear(sf::Color(0, 0, 0, 0));
        //Drawing
        App.draw(Rectangle);
        App.display();
    }

    //Never reaching this point normally, but just in case, exit the application
    return -1;
}