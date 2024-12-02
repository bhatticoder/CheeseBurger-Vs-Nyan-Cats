#ifndef NYANCAT_H
#define NYANCAT_H

#include "GameObject.h"
#include "Cheeseburger.h"
#include <cstdlib>
#include <iostream>

class NyanCat : public GameObject {
protected:
    static const int maxCats = 3;
    struct Cat {
        int row, col;
    } cats[maxCats];
    int falling_speed, playerLives, player_col;
    Cheeseburger* burger;

public:
    //virtual int MaxCats() const = 0;
    //virtual void initializeCats() = 0;
    int MaxCats()const;
    Cat* getCats() { return cats; }
    NyanCat(int startRow, int startCol, int speed, Cheeseburger* burger);
    virtual void fall() = 0;
    virtual void draw() = 0;
    virtual bool collide(GameObject* collideobject) = 0;
    virtual void move(char direction) = 0;
    int getLives() const;
    int getPlayerCol() const;
    void initializeCats();
};

class RegularNyanCat : public NyanCat {
public:
    RegularNyanCat(int x, int y, int speed, Cheeseburger* burger);
    void fall() override;
    void draw() override;
    bool collide(GameObject* collideobject) override;
    void move(char direction)override;
};

class SuperNyanCat : public NyanCat {
public:
    SuperNyanCat(int startRow, int startCol, int speed, Cheeseburger* burger);
    void fall() override;
    void draw() override;
    bool collide(GameObject* collideobject) override;
    void move(char direction)override;
};

class MegaNyanCat : public NyanCat {
public:
    MegaNyanCat(int startRow, int startCol, int speed, Cheeseburger* burger);
    void fall() override;
    void draw() override;
    bool collide(GameObject* collideobject) override;
    void move(char direction)override;
    void teleport();
};

#endif
