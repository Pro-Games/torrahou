#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <list>
#include <string>
#include "SFML/Graphics.hpp"

class GameObject
{
protected:
   // Los punteros a padres e hijos estan por implementar
   GameObject* parent;
   std::list<GameObject*> childs;

   // ID con la que identificar la instancia en el mapa general
   std::string id;
public:
   GameObject();

   // Las funciones virtuales se ejecutaran tal y como estan implementadas
   // aqui salvo que los hijos cuenten con su propia implementacion

   // Pre: los argumentos han sido inicializados
   // Post: las instancias de la lista se han actualizado segun su metodo
   virtual void Update(float Deltatime, std::list<GameObject*>& Instances);

   // Pre: window ha sido inicializada
   // Post: la mascara se he dibujado en pantalla (posteriormente el sprite)
   virtual void Draw(sf::RenderWindow& window);

   // Pre: aux ha sido inicializado
   // Post: devuelve true si la mascara del invocador colisiona con aux
   virtual bool Collides(const sf::FloatRect& aux);
};

#endif // GAMEOBJECT_H