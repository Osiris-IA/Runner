#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <shape.hpp>
// #include <string>
// #include <cstdlib>

int main()
{ // Initialisation
    float MOVE_SPEED = 200.f;
    const float WORLD_WIDTH = 2000.f; // Largeur de ton monde
    const float WORLD_HEIGHT = 1500.f;
    // Création de la fenêtre
    auto window = sf::RenderWindow(sf::VideoMode({800, 600}), "SFML Project");
    window.setFramerateLimit(144); // Limite le rafraîchissement à 144 images par seconde maximum

    // Chargement des textures
    sf::Texture texture;
    if (!texture.loadFromFile("assets/ninja.png"))
        std::cout << "Erreur" << std::endl;

    // sf::Texture perso;
    // if (!perso.loadFromFile("assets/1_Pink_Monster/Pink_Monster.png"))
    //     return 1;
    // sf::Sprite sprite_perso(perso);
    // sprite_perso.setScale({2.f, 2.f});        // Agrandir 2x
    // sprite_perso.setPosition({100.f, 100.f}); // Positionner

    sf::Texture textureRun;
    if (!textureRun.loadFromFile("assets/1_Pink_Monster/Pink_Monster_Run_6.png"))
        return 1;

    sf::Texture textureJump;
    if (!textureJump.loadFromFile("assets/1_Pink_Monster/Pink_Monster_Jump_8.png"))
        return 1;

    // Configuration du sprite animé
    // Chaque frame du Pink Monster fait généralement 32x32 pixels
    int frameWidth = 32;
    int frameHeight = 32;
    int totalFrames = 6; // Car le fichier finit par _6.png

    sf::Sprite sprite_perso(textureRun); // Crée le sprite avec la texture

    // On définit la zone de la texture à afficher : sf::IntRect(gauche, haut, largeur, hauteur)
    sprite_perso.setTextureRect(sf::IntRect({0, 0}, {frameWidth, frameHeight}));

    sprite_perso.setOrigin({static_cast<float>(frameWidth / 2), static_cast<float>(frameHeight / 2)}); // Centre le sprite (32/2 = 16)
    sprite_perso.setScale({4.f, 4.f});                                                                 // Un peu plus grand pour mieux voir
    sprite_perso.setPosition({200.f, 700.f});                                                          // Position initiale

    // Variables d'animation pour le temps
    float timer = 0.0f;         // Temps écoulé depuis la dernière frame
    float frameDuration = 0.1f; // Change de frame toutes les 0.1s (10 FPS)
    int currentFrame = 0;       // Frame actuelle (0 à 5)
    bool isRunning = true;      // true = Run, false = Idle
    bool isJumping = false;     // true = Jump, false = pas de saut

    // Variables pour la physique du saut
    float velocityY = 0.f;           // Vitesse verticale
    const float GRAVITY = 800.f;     // Gravité (pixels/s²)
    const float JUMP_FORCE = -400.f; // Force du saut (négatif = vers le haut)
    const float GROUND_Y = 700.f;    // Position du sol

    // Texture Idle
    sf::Texture textureIdle;
    if (!textureIdle.loadFromFile("assets/1_Pink_Monster/Pink_Monster_Idle_4.png"))
        return 1; // 4 frames pour l'animation Idle (repos)

    // Clock & Font
    sf::Clock clock; // Chronomètre pour mesurer le temps entre frames

    textureRun.setSmooth(false);
    textureIdle.setSmooth(false);
    textureJump.setSmooth(false);

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
    sf::RectangleShape rect2 = pb_rect(500, 500, 48, 48);

    sf::View view;
    int screenW = 800, screenH = 600;

    while (window.isOpen())
    {
        const sf::Time dt = clock.restart(); // Temps depuis dernière frame
        const float delta = dt.asSeconds();  // Conversion en secondes

        // Gestion événements
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close(); // Ferme si on clique sur X
        }
        // Déplacement Pink Monster
        sf::Vector2f perso_offset(0.f, 0.f); // Vecteur de déplacement

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            perso_offset.x -= MOVE_SPEED * delta;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            perso_offset.x += MOVE_SPEED * delta;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            perso_offset.y -= MOVE_SPEED * delta;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            perso_offset.y += MOVE_SPEED * delta;
        if (sprite_perso.getPosition().x <= 0)
            sprite_perso.setPosition(sf::Vector2f(0, sprite_perso.getPosition().y));
        if (sprite_perso.getPosition().y <= 0)
            sprite_perso.setPosition(sf::Vector2f(sprite_perso.getPosition().x, 0));
        sprite_perso.move(perso_offset); // Applique le déplacement

        // Déplacement du ninja avec ZQSD
        sf::Vector2f offset(0.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
            offset.x -= MOVE_SPEED * delta;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            offset.x += MOVE_SPEED * delta;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z))
            offset.y -= MOVE_SPEED * delta;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            offset.y += MOVE_SPEED * delta;
        sprite.move(offset);

        // 1. CALCUL DU MOUVEMENT (On centralise tout ici)+ flip
        sf::Vector2f movement(0.f, 0.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            movement.x -= MOVE_SPEED * delta;
            sprite_perso.setScale({-4.f, 4.f}); // Regarde à gauche
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            movement.x += MOVE_SPEED * delta;
            sprite_perso.setScale({4.f, 4.f}); // Regarde à droite
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            movement.y -= MOVE_SPEED * delta;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            movement.y += MOVE_SPEED * delta;

        // Gestion du saut avec physique
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        {
            // Saut seulement si on est au sol
            if (!isJumping && sprite_perso.getPosition().y >= GROUND_Y)
            {
                sprite_perso.setTexture(textureJump);
                totalFrames = 8;
                currentFrame = 0;
                timer = 0;
                isJumping = true;
                isRunning = false;
                velocityY = JUMP_FORCE; // Impulsion vers le haut
            }
        }

        // Applique la gravité
        velocityY += GRAVITY * delta;
        movement.y += velocityY * delta;

        // Si on touche le sol
        if (sprite_perso.getPosition().y >= GROUND_Y && velocityY > 0)
        {
            sprite_perso.setPosition({sprite_perso.getPosition().x, GROUND_Y});
            velocityY = 0.f;
            if (isJumping)
                isJumping = false; // Fin du saut
        }

        bool isMoving = (movement.x != 0.f || movement.y != 0.f); // true si le joueur bouge

        // 2. GESTION DES TEXTURES (Changement d'état) / Changement de texture

        if (isJumping)
        {
            // En saut : on garde l'animation Jump
        }
        else if (isMoving)
        {
            if (!isRunning) // Si on était en Idle
            {
                sprite_perso.setTexture(textureRun); // Passe en Run
                totalFrames = 6;
                currentFrame = 0; // Recommence l'anim au début
                timer = 0;        // Reset le timer pour commencer l'anim proprement
                isRunning = true;
            }
        }
        else
        {
            if (isRunning) // Si on était en Run
            {
                sprite_perso.setTexture(textureIdle); // Passe en Idle
                totalFrames = 4;
                currentFrame = 0;
                timer = 0;
                isRunning = false;
            }
        }

        // 3. ANIMATION (Mise à jour du rectangle)
        timer += delta;             // Ajoute le temps écoulé
        if (timer >= frameDuration) // Toutes les 0.1s
        {
            timer = 0;
            currentFrame = (currentFrame + 1) % totalFrames;
            // Passe à la frame suivante, revient à 0 après la dernière

            sprite_perso.setTextureRect(sf::IntRect({currentFrame * frameWidth, 0}, // Position X de la frame
                                                    {frameWidth, frameHeight}));    // Taille de la frame
        }

        // 4. APPLICATION DU MOUVEMENT
        sprite_perso.move(movement); // Déplace le sprite

        // sprite_perso.move(offset);

        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        // {
        //     std::cout << "Vous avez appuyé sur la touche A !" << std::endl;
        // }

        // if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        // {
        //     std::cout << "btn souris gauche" << std::endl;
        // }

        // Caméra qui suit le personnage
        sf::Vector2f position;
        position.x = sprite_perso.getPosition().x - (screenW / 2.f);
        position.y = sprite_perso.getPosition().y - (screenH / 2.f);
        if (position.x < 0)
            position.x = 0;
        if (position.y < 0)
            position.y = 0;
        // Limites droite et bas (NOUVEAU)
        if (position.x + screenW > WORLD_WIDTH)
            position.x = WORLD_WIDTH - screenW;
        if (position.y + screenH > WORLD_HEIGHT)
            position.y = WORLD_HEIGHT - screenH;

        view.setCenter({position.x + screenW / 2.f, position.y + screenH / 2.f});
        view.setSize({static_cast<float>(screenW), static_cast<float>(screenH)});
        window.setView(view);

        window.clear();
        // window.draw(circle); // Dessiner le cercle
        window.draw(sprite);
        window.draw(text);
        // window.draw(shape);
        window.draw(rect);
        window.draw(rect2);
        window.draw(sprite_perso);

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