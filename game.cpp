// No incluir mas cabeceras aqui, utilizar includes.h
#include "includes.h"

int main2()
{
   sf::RenderWindow Window(sf::VideoMode(800, 800, 32), "Probe");

   // La lista que contendra las instancias que necesitan Update()
   // Posteriormente formara parte de la clase Scene
   // Falta por implementar el mapa de instancias (mirar especificacion)
   std::list<GameObject*> Instances;
   std::list<GameObject*>::iterator it;

   sf::Clock Clock;

   // Instanciacion de prueba
   Player p1;
   Instances.insert(Instances.begin(), &p1);
   Block b1;
   Instances.insert(Instances.begin(), &b1);

   while (Window.isOpen()) {
       // Clock
       sf::Time Time = Clock.getElapsedTime();
       Clock.restart();


       // Events
       sf::Event Event;
       while (Window.pollEvent(Event)) {
           switch (Event.type) {
           case sf::Event::Closed:
               Window.close();
               break;
           case sf::Event::KeyPressed:
               if (Event.key.code == sf::Keyboard::Escape) Window.close();
               break;
           default:
               break;
           }
       }

       // Updates y Draw (Recorrer una vez la lista resulta mas eficiente)
       Window.clear();

       for (it = Instances.begin(); it != Instances.end(); ++it) {
           (*it)->Update(Time.asSeconds(), Instances);
           (*it)->Draw(Window);
       }

       Window.display();
   }
   return 0;
}