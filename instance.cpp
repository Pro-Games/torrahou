#include "instance.h"

// Constructora por defecto
instance::instance()
{
}

bool instance::Collides(const sf::RectangleShape& rect)
// Pre: rect y el parametro implicito estan inicializados
// Post: si rect y la mascara del parametro implicito colisionan, devuelve TRUE
{
   sf::FloatRect r1 = mask.getGlobalBounds();
   sf::FloatRect r2 = rect.getGlobalBounds();
   return (r1.intersects(r2));
}

// Por implementar
bool instance::isGrounded()
// Pre:
// Post:
{
	return false;
}

void instance::move(const sf::Vector2f& mov)
// Pre: la mascara y el sprite del parametro implicito y mov han sido inicializados
// Post: la mascar y el sprite se han desplazado mov (unidades de SFML, pixeles?)
{
   mask.move(mov);
   sprite.move(mov);
}

sf::RectangleShape instance::getMask()
// Pre:
// Post: devuelve la mascara del parametro implicito
{
   return mask;
}