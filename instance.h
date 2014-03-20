#ifndef INSTANCE_H
#define INSTANCE_H

#include "SFML/Graphics.hpp"
#include <list>

class instance
{
protected: // Atributos que heredaran los hijos
   sf::RectangleShape mask;
   sf::Sprite sprite;
   bool isSolid;

// Esta lista contiene todas las instancias de cada mapa
   static std::list<instance*> instancias;
   static std::list<instance*>::iterator it;
   
   bool collision_free()
   {
	   
   }

public:
// Constructora
   instance();

// Update
// Funcion virtual: no hace nada por si, solo sus hijos la llaman y cada uno de una manera diferente
   virtual void Update(float deltatime) =0;

// Otras funciones
   void move(const sf::Vector2f& mov);
   bool Collides(const sf::RectangleShape& rect);
   bool isGrounded();

   // Consultora
   sf::RectangleShape getMask();
};

#endif // INSTANCE_H