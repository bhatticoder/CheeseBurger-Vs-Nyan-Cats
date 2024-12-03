#pragma once
#include "GameObject.h"
#include <thread>
#include <chrono>
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
    int updateShield();
    bool isShieldActive() const;
    friend std::ostream& operator<<(std::ostream& os, const Cheeseburger& burger);
    int getTimer();
    void loseLife() {
        if (!shieldActive) {
            lives--;  // Only decrease lives if the shield is not active
            std::cout << "Lives remaining: " << lives << "\n";
        }
    }
private:
    int score;
    int lives;
    int speed;
    int player_col;
    bool shieldActive;
    int shieldTimer;
};
