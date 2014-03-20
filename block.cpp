#include "block.h"

// Constructor de prueba para comprobar las colisiones basicas
Block::Block()
{
   Mask.setPosition(0, 500);
   Mask.setFillColor(sf::Color::Red);
   Mask.setSize(sf::Vector2f(700, 50));
}