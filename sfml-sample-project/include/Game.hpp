/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumini <https://moustoifa.moumini.xyz/>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:36:29 by mmoumini          #+#    #+#             */
/*   Updated: 2025/04/22 19:36:33 by mmoumini         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Character.hpp"

class Game {
public:
    Game();
    Game(const Game& other);
    Game& operator=(const Game& other);
    ~Game();

    void start();

private:
    Character _mainCharacter;
};

#endif
