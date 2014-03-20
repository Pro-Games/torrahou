#include "player.h"

// Constructor de prueba para ver el funcionamiento basico
Player::Player()
{
   Mask = sf::RectangleShape(sf::Vector2f(50, 50));
   Mask.setPosition(40, 40);
   Mask.setFillColor(sf::Color::White);

   Vel.x = 0;
   Vel.y = 0;
}

void Player::Update(float Deltatime, std::list<GameObject*>& Instances)
{
   // Horizontal Movement
   const float VEL = 5.0;
   const float MAXVEL = 12.0;

   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
       Vel.x -= VEL;
   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
       Vel.x += VEL;
   if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
       Vel.x /= 2;

   if (Vel.x > MAXVEL) Vel.x = MAXVEL;
   if (Vel.x < -MAXVEL) Vel.x = -MAXVEL;

   float Xmove = Vel.x;

   // Vertical Movement
   const float G = 500.0;

   float Ymove;

   if (!isGrounded(Instances)) {
       Vel.y += G*Deltatime;
       Ymove = Vel.y*Deltatime + 0.5*G*Deltatime*Deltatime;
   }
   else  Ymove = 0;

   // Jump (falta mejorar)
   const float JUMP = 200;

   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && isGrounded(Instances))
       Vel.y -= JUMP;
   if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !isGrounded(Instances) && Vel.y < 0)
       Vel.y *= 0.5;

   // Movement Action

   Move(Xmove, Ymove);
}