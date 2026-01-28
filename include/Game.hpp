#include <vector>
#include "Obstacle.hpp"

class Game
{
private:
    std::vector<Obstacle> obstacles; // Ta liste dynamique d'obstacles

public:
    void spawnObstacle(); // Ajoutera un obstacle avec push_back() [cite: 243]
    void updateGame();    // Fera bouger tout le monde
};