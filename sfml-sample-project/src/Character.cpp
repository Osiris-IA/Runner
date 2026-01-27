/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumini <https://moustoifa.moumini.xyz/>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:36:53 by mmoumini          #+#    #+#             */
/*   Updated: 2025/04/22 19:42:45 by mmoumini         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Character.hpp"
#include <iostream>

using namespace std;

Character::Character() : _name("Hero") {
    cout << "Character created" << endl;
}

Character::Character(const Character& other) : _name(other._name) {
    cout << "Character copied" << endl;
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        _name = other._name;
    }
    cout << "Character assigned" << endl;
    return *this;
}

Character::~Character() {
}

void Character::speak() const {
    cout << "My name is " << _name << "!" << endl;
}
