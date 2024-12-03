#ifndef NYANCAT_H
#define NYANCAT_H

#include "GameObject.h"
#include "Cheeseburger.h"
#include "PowerUp.h"

class NyanCat : public GameObject {
protected:
    int falling_speed;
    int playerLives;
    int player_col;
    Cheeseburger* burger;
    static const int maxCats = 3;  // Maximum number of Nyan Cats
    struct Cat {
        int row;
        int col;
    };
    Cat cats[maxCats];            // Array of cats
    PowerUp* powerUp;             // PowerUp object

public:
    NyanCat(int startRow, int startCol, int speed, Cheeseburger* burger, PowerUp* powerUp);
    virtual void fall() = 0;
    virtual bool collide(GameObject* collideobject) = 0;
    void move(char direction) override;
    void initializeCats();
    int getLives() const;
    int getRow() const;
    int getPlayerCol() const;
};

class RegularNyanCat : public NyanCat {
public:
    RegularNyanCat(int startRow, int startCol, int speed, Cheeseburger* burger, PowerUp* powerUp);
    void fall() override;
    void draw() override;
    bool collide(GameObject* collideobject) override;
};

class SuperNyanCat : public NyanCat {
public:
    SuperNyanCat(int startRow, int startCol, int speed, Cheeseburger* burger, PowerUp* powerUp);
    void fall() override;
    void draw() override;
    bool collide(GameObject* collideobject) override;
};

class MegaNyanCat : public NyanCat {
public:
    MegaNyanCat(int x, int y, int speed, Cheeseburger* cheeseburger, PowerUp* powerup);
    void fall() override;
    void draw() override;
    bool collide(GameObject* collideobject) override;
    void teleport();  // Unique feature for MegaNyanCat
};

#endif  // NYANCAT_H
