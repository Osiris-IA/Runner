#include "shape.hpp"

sf::RectangleShape pb_rect(float posX, float posY, float width, float height)
{
    sf::RectangleShape rect(sf::Vector2f(width, height));
    rect.setPosition({posX, posY});
    rect.setFillColor(sf::Color(255, 0, 0, 255));
    return rect;
}
