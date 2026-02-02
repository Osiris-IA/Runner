#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <shape.hpp>
// #include <string>
// #include <cstdlib>

int main()
{
    float MOVE_SPEED = 200.f;
    // Création de la fenêtre
    auto window = sf::RenderWindow(sf::VideoMode({800, 600}), "SFML Project");
    window.setFramerateLimit(144); // Limite le rafraîchissement à 144 images par seconde maximum

    sf::Texture texture;
    if (!texture.loadFromFile("assets/ninja.png"))
        return 1;

    const sf::Vector2f windowSize(800.f, 600.f);

    // sf::Texture texture("assets/img.jpg");
    sf::Sprite sprite(texture);
    const sf::FloatRect bounds = sprite.getLocalBounds();

    sf::Font font;
    if (!font.openFromFile("assets/Debrosee-ALPnL.ttf"))
        return 1;
    sf::Text text(font, "Hello SFML", 50);
    sf::Music music("assets/Song_Guy.ogg");

    music.play();
    // window.setSize(sf::Vector2u (800,600));

    // Modifier la position et la taille
    float SPRITE_SIZE = 100.f;
    sprite.setScale({SPRITE_SIZE / bounds.size.x, SPRITE_SIZE / bounds.size.y});
    sprite.setPosition({windowSize.x / 4.f - SPRITE_SIZE / 4.f,
                        windowSize.y / 2.f - SPRITE_SIZE / 2.f});

    sf::Clock clock;

    // Création de formes
    sf::CircleShape shape(50.f);

    shape.setFillColor(sf::Color(100, 250, 50));
    shape.setRadius(50);
    shape.setPosition({windowSize.x / 2.f - SPRITE_SIZE / 2.f,
                       windowSize.y / 2.f - SPRITE_SIZE / 2.f});

    // sf::RectangleShape rectangle({120.f, 50.f});
    // rectangle.setPosition({windowSize.x / 2.f - SPRITE_SIZE / 2.f,
    //                        windowSize.y / 4.f - SPRITE_SIZE / 2.f});

    std::cout << "Lancement" << std::endl;
    sf::RectangleShape rect = pb_rect(20, 20, 32, 32);

    while (window.isOpen())
    {
        const sf::Time dt = clock.restart();
        const float delta = dt.asSeconds();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        sf::Vector2f offset(0.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            offset.x -= MOVE_SPEED * delta;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            offset.x += MOVE_SPEED * delta;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            offset.y -= MOVE_SPEED * delta;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            offset.y += MOVE_SPEED * delta;
        sprite.move(offset);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            std::cout << "Vous avez appuyé sur la touche A !" << std::endl;
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            std::cout << "btn souris gauche" << std::endl;
        }

        window.clear();
        // window.draw(circle); // Dessiner le cercle
        window.draw(sprite);
        window.draw(text);
        window.draw(shape);
        window.draw(rect);

        window.display();
    }
    return 0;
}

// while (window.isOpen()) // boucle execute tout ca tant qu ela fenêtre est ouverte
// {
//     sf::Event event;
//     while (window.pollEvent(event))
//     { // Tant fenêtre ouverte, je teste si evenement ce produit
//         // si evenement se pruit, et que c'est "event" av-lors ferme la fenêtre
//         if (event.type == sf::Event : Closed)
//             window.close();
//     }
// }
// return 0;