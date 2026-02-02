/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumini  <https://moustoifa.moumini.xyz/> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:15:46 by mmoumini          #+#    #+#             */
/*   Updated: 2026/01/26 11:39:28 by mmoumini         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <SFML/Graphics.hpp>
#include "Game.hpp"

int main() {
    Game game;
    game.start();

    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "SFML Project");
    window.setFramerateLimit(144);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();
        window.display();
    }
    return 0;
}
