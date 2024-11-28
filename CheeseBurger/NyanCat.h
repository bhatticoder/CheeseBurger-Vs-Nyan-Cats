#ifndef NYANCAT_H
#define NYANCAT_H
#include "GameObject.h"
#include "Cheeseburger.h"
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
    Cat cats[maxCats];  // Array of cats
public:
    NyanCat(int startRow, int startCol, int speed, Cheeseburger* burger);
    virtual void fall() = 0;
    virtual void move() = 0;
    virtual void collide(GameObject* collideobject) = 0;
    // Getters
    void move(char direction)override;
    void initializeCats();
    int getLives() const;
    int getRow() const;
    int getPlayerCol() const;
};
class RegularNyanCat : public NyanCat {
public:
    RegularNyanCat(int startRow, int startCol, int speed, Cheeseburger* burger);
    void fall() override;
    void move() override;
    void draw()override;
    void move(char direction)override;
    void collide(GameObject* collideobject) override;
};
class SuperNyanCat : public NyanCat {
public:
    SuperNyanCat(int startRow, int startCol, int speed, Cheeseburger* burger);
    void fall() override;
    void move() override;
    void draw()override;
    void move(char direction)override;
    void collide(GameObject* collideobject) override;
    void teleport();
};

#endif  // NYANCAT_H
