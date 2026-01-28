class Obstacle
{
private:
    float x, y;  // Sa position sur l'écran
    float speed; // Sa vitesse de défilement
    float width, height, depth;
    int lane; // Voie (0, 1, 2 pour 3 voies)
    bool active;
    int type; // 0 pour une barrière, 1 pour un train, etc.

public:
    // Le constructeur : pour créer un obstacle à une position précise
    Obstacle(int lane, float startZ, int type, float speed = 20.0f);

    // La logique de mouvement
    void move(float deltaTime);

    bool isOffScreen(float playerZ) const;

    // Accesseur pour vérifier si l'obstacle est sorti de l'écran
    float getX() const { return x; }
    float getY() const { return y; }
    int getLane() const { return lane; }
    bool isActive() const { return active; }
    int getType() const { return type; }
    float getWidth() const { return width; }
    float getHeight() const { return height; }
    float getDepth() const { return depth; }

    void setActive(bool state) { active = state; }
};