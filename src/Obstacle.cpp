
#include "Obstacle.hpp"
#include <iostream>

using namespace std;
// Initialisation de l'objet
Obstacle::Obstacle(int lane, float startZ, int t, float speed)
    : x(startZ), speed(20.0f), type(t), lane(l){}

// Logique pour faire descendre l'obstacle (effet runner)
void Obstacle::move()
{
    y += speed; // L'obstacle avance vers le bas de l'écran
}

float Obstacle::getY() const
{
    return y;
}
