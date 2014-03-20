#ifndef WALL_H
#define WALL_H

#include "instance.h"
#include "SFML/Graphics.hpp"

class wall : public instance // Hereda de la clase instance
{
private:
public:
// COnstructora
   wall();
   wall(const sf::Vector2f& size, const sf::Vector2f& pos);
	void Update(float deltatime);
};

#endif // WALL_H