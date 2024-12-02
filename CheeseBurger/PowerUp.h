#ifndef POWERUP_H
#define POWERUP_H

#include "GameObject.h"
#include "Nyancat.h"
#include "Cheeseburger.h"
#include <cstdlib>
#include <ctime>

class Powerup : public GameObject {
private:
    const int rows, cols;
    Cheeseburger* burger;
    int speed, player_col;
    static const int maxCats = 3;
    struct Cat {
        int row, col;
    } cats[maxCats];
    int shieldRow, shieldCol;
    int boosterRow, boosterCol;
    int multiplierRow, multiplierCol;
    int getRow() const;
    int getCol() const;
    bool shieldActive, boosterActive, multiplierActive;
public:
    Powerup(int x, int y, int rows, int cols, Cheeseburger* burger, int speed, int startCol);
    virtual ~Powerup() {}
    void move(char dir)override;
    virtual void draw() override;
    void fall();
    bool collide(GameObject* other) override;
    int drawShield() const;
    int drawBooseter() const;
    int drawScoreMultiplier() const;
};

#endif
