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
    int player_row;
    Cheeseburger* burger;
    static const int maxCats = 3;
    struct Cat {
        int row;
        int col;
    };
    Cat cats[maxCats];
    shield* powerUp;
    ScoreMultiplier* multiplier;
    SpeedBooster* booster;
public:
    NyanCat(int startRow, int startCol, int speed, Cheeseburger* burger, shield* powerUp, ScoreMultiplier* multiplier, SpeedBooster* booster);
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
    RegularNyanCat(int startRow, int startCol, int speed, Cheeseburger* burger, shield* powerUp, ScoreMultiplier* multiplier, SpeedBooster* booster);
    void fall() override;
    void draw() override;
    bool collide(GameObject* collideobject) override;
};

class SuperNyanCat : public NyanCat {
public:
    SuperNyanCat(int x, int y, int speed, Cheeseburger* burger, shield* shieldObj, ScoreMultiplier* multiplier, SpeedBooster* booster);
    void fall() override;
    void draw() override;
    bool collide(GameObject* collideobject) override;
};

class MegaNyanCat : public NyanCat {
public:
    MegaNyanCat(int startRow, int startCol, int speed, Cheeseburger* burger, shield* powerUp, ScoreMultiplier* multiplier, SpeedBooster* booster);
    void fall() override;
    void draw() override;
    bool collide(GameObject* collideobject) override;
    void teleport();
};

#endif  // NYANCAT_H
