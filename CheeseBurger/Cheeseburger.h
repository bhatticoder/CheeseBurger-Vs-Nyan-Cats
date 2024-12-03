#pragma once
#include "GameObject.h"

class Cheeseburger : public GameObject {
public:
    Cheeseburger(int x, int y, int speed, int lives, int startCol);
    void updateScore(int points);
    bool collide(GameObject* collideobject);
    int getLives() const;
    int getScore() const;
    int getSpeed() const;
    void draw();
    void move(char direction);
    void activateShield();
    void updateShield();
    bool isShieldActive() const;
    friend std::ostream& operator<<(std::ostream& os, const Cheeseburger& burger);

private:
    int score;
    int lives;
    int speed;
    int player_col;
    bool shieldActive;
    int shieldTimer;
};
