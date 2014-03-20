#include "actor.h"

Actor::Actor()
{
	
}

void Actor::Update(float Deltatime, std::list<GameObject *> &Instances) {}

void Actor::Draw(sf::RenderWindow& window) { window.draw(Mask); }

void Actor::Move(float x, float y) { Mask.move(x, y); }

bool Actor::isGrounded(std::list<GameObject*>& Instances)
{
   sf::RectangleShape Aux = Mask;
   Aux.move(0, Mask.getSize().y);
   Aux.setSize(sf::Vector2f(Aux.getSize().x, 2));

   std::list<GameObject*>::iterator it;
   for (it = Instances.begin(); it != Instances.end(); ++it)
       if ((*it)->Collides(Aux.getGlobalBounds()))
           return true;

   return false;
}

bool Actor::Collides(const sf::FloatRect& aux)
{
   return Mask.getGlobalBounds().intersects(aux);
}