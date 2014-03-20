#ifndef ACTOR_H
#define ACTOR_H

#include <list>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "gameobject.h"

// Todas las instancias que podemos considerar "vivas"
// Player, enemigos, otros sprites...
class Actor : public GameObject
{
protected: // Atributos que heredaran los hijos
   sf::RectangleShape Mask;
   sf::Sprite Sprite;

   sf::Vector2f Vel;
public:
   Actor();

   // Pre: los argumentos han sido inicializados
   // Post: las instancias de la lista se han actualizado segun su metodo
   void Update(float Deltatime, std::list<GameObject*>& Instances);

   // Pre: window ha sido inicializada
   // Post: la mascara se he dibujado en pantalla (posteriormente el sprite)
   void Draw(sf::RenderWindow& window);

   // Pre: los argumentos han sido inicializados
   // Post: la mascara y el sprite se han movido x e y unidades
   void Move(float x, float y);

   // Pre: la lista esta inicializada
   // Post: devuelve true si hay una instancia bajo el invocador
   // **Si los bloques (no Actor) no van a estar en
   //      la lista, habra que revisar el metodo
   bool isGrounded(std::list<GameObject*>& Instances);

   // Pre: aux ha sido inicializado
   // Post: devuelve true si la mascara del invocador colisiona con aux
   bool Collides(const sf::FloatRect& aux);
};

#endif // ACTOR_H