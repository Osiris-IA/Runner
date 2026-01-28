


#include "Game.hpp"
#include <iostream>

using namespace std;

Game::Game() {
    cout << "Game initialized" << endl;
}

Game::Game(const Game& other) : _mainCharacter(other._mainCharacter) {
    cout << "Game copied" << endl;
}

Game& Game::operator=(const Game& other) {
    if (this != &other) {
        _mainCharacter = other._mainCharacter;
    }
    std::cout << "Game assigned" << std::endl;
    return *this;
}

Game::~Game() {
}

void Game::start() {
    cout << "Game starting..." << endl;
    _mainCharacter.speak();
}
