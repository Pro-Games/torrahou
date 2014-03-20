#ifndef PLAYER_H
#define PLAYER_H

#include "actor.h"

class Player : public Actor
{
public:
   Player();

   // Pre: los argumentos han sido inicializados
   // Post: las instancias de la lista se han actualizado segun su metodo
   void Update(float Deltatime, std::list<GameObject*>& Instances);
};

#endif // PLAYER_H