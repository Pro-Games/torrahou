#include <iostream>
#include "cscreen.h"

#include <SFML/Graphics.hpp>

class screen_menu : public cscreen
{
private:
    int alpha_max;
    int alpha_div;
    bool playing;
public:
    screen_menu(void);
    virtual int Run(sf::RenderWindow &App);
};

screen_menu::screen_menu(void)
{
    alpha_max = 3 * 255;
    alpha_div = 3;
    playing = false;
}

int screen_menu::Run(sf::RenderWindow &App)
{
    sf::Event Event;
    bool Running = true;
    sf::Texture Texture;
    sf::Sprite Sprite;
    int alpha = 0;
    sf::Font Font;
    sf::Text Menu1;
    sf::Text Menu2;
    sf::Text Menu3;
	sf::Text Menu4; //"Play the other game"
    int menu = 0;

    if (!Texture.loadFromFile("presentation.png"))
    {
        std::cerr << "Error loading presentation.png" << std::endl;
        return (-1);
    }
    Sprite.setTexture(Texture);
    Sprite.setColor(sf::Color(255, 255, 255, alpha));
    if (!Font.loadFromFile("PNRegular.ttf"))
    {
        std::cerr << "Error loading PNRegular.ttf" << std::endl;
        return (-1);
    }
    Menu1.setFont(Font);
    Menu1.setCharacterSize(20);
    Menu1.setString("Play");
    Menu1.setPosition( 280.f, 160.f );

    Menu2.setFont(Font);
    Menu2.setCharacterSize(20);
    Menu2.setString("Exit");
    Menu2.setPosition( 280.f, 220.f );

    Menu3.setFont(Font);
    Menu3.setCharacterSize(20);
    Menu3.setString("Continue");
    Menu3.setPosition( 280.f, 160.f );
	
	Menu4.setFont(Font);
    Menu4.setCharacterSize(20);
    Menu4.setString("Play the other game");
    Menu4.setPosition( 280.f, 160.f );

    if (playing)
    {
        alpha = alpha_max;
    }

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
                case sf::Keyboard::Up:
                    ++menu;
                    break;
                case sf::Keyboard::Down:
                    --menu;
                    break;
                case sf::Keyboard::Return:
                    if (menu == 0)
                    {
                        //Let's get play !
                        playing = true;
                        return (1);
                    }
                    else if (menu == 1)
                    {
                        //Let's get work...
                        return (-1);
                    }
					else
					{
						return (2);
					}
                    break;
                default:
                    break;
                }
            }
        }
        //When getting at alpha_max, we stop modifying the sprite
        if (alpha<alpha_max)
        {
            alpha++;
        }
        Sprite.setColor(sf::Color(255, 255, 255, alpha / alpha_div));
        if (menu == 0)
        {
            Menu1.setColor(sf::Color(255, 0, 0, 255));
            Menu2.setColor(sf::Color(255, 255, 255, 255));
            Menu3.setColor(sf::Color(255, 0, 0, 255));
			Menu4.setColor(sf::Color(255, 0, 0, 255));
        }
        else if (menu == 1)
        {
            Menu1.setColor(sf::Color(255, 255, 255, 255));
            Menu2.setColor(sf::Color(255, 0, 0, 255));
            Menu3.setColor(sf::Color(255, 255, 255, 255));
			Menu4.setColor(sf::Color(255, 0, 0, 255));
        }
		else
		{
			Menu1.setColor(sf::Color(255, 0, 0, 255));
            Menu2.setColor(sf::Color(255, 0, 0, 255));
            Menu3.setColor(sf::Color(255, 0, 0, 255));
			Menu4.setColor(sf::Color(255, 255, 255, 255));
		}

        //Clearing screen
        App.clear();
        //Drawing
        App.draw(Sprite);
        if (alpha == alpha_max)
        {
            if (playing)
            {
                App.draw(Menu3);
            }
            else
            {
                App.draw(Menu1);
				App.draw(Menu4);
            }
            App.draw(Menu2);
        }
        App.display();
    }

    //Never reaching this point normally, but just in case, exit the application
    return (-1);
}