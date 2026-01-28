
#include "Player.hpp"
#include <iostream>

using namespace std;

Player::Player()
{
    cout << "Game initialized" << endl;
}

Player::Player(const Player &other) : _mainPlayer(other._mainPlayer)
{
    cout << "Player copied" << endl;
}

Player &Player::operator=(const Player &other)
{
    if (this != &other)
    {
        _mainPlayer = other._mainPlayer;
    }
    std::cout << "Player assigned" << std::endl;
    return *this;
}

Player::~Player()
{
}

void Player::start()
{
    cout << "Player starting..." << endl;
    _mainPlayer.speak();
}
