#include "wall.h"
#include "SFML/Graphics.hpp"

using namespace sf;

// Constructora por defecto
wall::wall()
{
   mask.setFillColor(Color::Black);
}

// Constructora dando el tamaño y la posicion de spawn
wall::wall(const Vector2f& size, const Vector2f& pos)
{
   mask.setSize(size);
   mask.setPosition(pos);
   mask.setFillColor(Color::Black);
}

void wall::Update(float deltatime)
{
	
}