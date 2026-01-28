#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Player.hpp"

class Player
{
public:
    Player();
    Player(const Player &other);
    Player &operator=(const Player &other);
    ~Player();

    void start();

private:
    Player _mainPlayer;
};

#endif