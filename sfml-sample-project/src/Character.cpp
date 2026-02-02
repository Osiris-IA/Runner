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

Character::Character() : name("Marie") {
    cout << "Character created" << endl;
}

Character::Character(const Character& other) : name(other.name) {
    cout << "Character copied" << endl;
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        name = other.name;
    }
    cout << "Character assigned" << endl;
    return *this;
}

Character::~Character() {
}

void Character::speak() const {
    cout << "My name is " << name << "!" << endl;
}
