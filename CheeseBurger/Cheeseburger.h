#pragma once
#include "GameObject.h"
#include <iostream>
#include <chrono>
#include <thread>

class Cheeseburger : public GameObject {
private:
    int score;
    int lives;
    int speed;
    int player_col;
    bool shieldActive;
    int shieldTimer;
    const int defaultSpeed = 1;

public:
    Cheeseburger(int x, int y, int speed, int lives, int startCol);
    void setPlayerCol(int col) {
        player_col = col;
    }
    int getPlayerCol() const{
        return player_col;
    }
    // Getters
    int getLives() const;
    int getScore() const;
    int getSpeed() const;

    // Setters and Update methods
    void updateScore(int points);
    bool collide(GameObject* collideobject);
    void draw();
    // Movement and Shielding
    void move(char direction);
    void activateShield();
    bool isShieldActive() const;
    int getTimer();
    int updateShield();

    // Overload output operator for Cheeseburger state
    friend std::ostream& operator<<(std::ostream& os, const Cheeseburger& burger);

    // Speed control methods
    void increaseSpeed(); // Boost speed temporarily
    void resetSpeed();    // Reset speed to normal
};
