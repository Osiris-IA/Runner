/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumini <https://moustoifa.moumini.xyz/>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:37:20 by mmoumini          #+#    #+#             */
/*   Updated: 2025/04/22 19:36:16 by mmoumini         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

class Character {
public:
    Character();
    Character(const Character& other);
    Character& operator=(const Character& other);
    ~Character();

    void speak() const;

private:
    std::string _name;
};

#endif
