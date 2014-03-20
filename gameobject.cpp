#include "gameobject.h"

GameObject::GameObject() {}

void GameObject::Update(float Deltatime, std::list<GameObject *> &Instances) {}

void GameObject::Draw(sf::RenderWindow& window) {}

bool GameObject::Collides(const sf::FloatRect& aux) {}