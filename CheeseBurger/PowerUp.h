#ifndef POWERUP_H
#define POWERUP_H
#include "GameObject.h"
#include "Cheeseburger.h"
#include "NyanCat.h"
#include <iostream>
#include <cstdlib>
class Powerup : public GameObject {
protected:
    int duration;    
    bool isActive;   
    Cheeseburger* burger;
    int rows;       
    int cols;       
    int speed;    
    struct power {
        int row;
        int col;
    };
public:
    Powerup(int x, int y, int rows, int cols, Cheeseburger* burger, int speed = 1)
        : GameObject(x, y, 4, 2) , burger(burger), rows(rows), cols(cols), isActive(false), speed(speed),duration(10) {}
    virtual void activate() = 0;
    void deactivate();
    void reset();
    void fall(); 
    bool collide(GameObject* other) override;
    void draw() override; 
};
class ShieldPowerup : public Powerup {
public:
    ShieldPowerup(int x, int y, int rows, int cols, Cheeseburger* burger)
        : Powerup(x, y, rows, cols, burger) {}
    void activate() override {
        isActive = true;
        std::cout << "Shield Activated!" << std::endl;
    }
    void drawShield();
    void move(char dir) override {}
};
class ScoreMultiplierPowerup : public Powerup {
public:
    ScoreMultiplierPowerup(int x, int y, int rows, int cols, Cheeseburger* burger)
        : Powerup(x, y, rows, cols, burger) {}
    void activate() override {
        isActive = true;
        std::cout << "Score Multiplier Activated!" << std::endl;
    }
    void move(char dir) override {}
};
class SpeedBoostPowerup : public Powerup {
public:
    SpeedBoostPowerup(int x, int y, int rows, int cols, Cheeseburger* burger)
        : Powerup(x, y, rows, cols, burger) {}
    void activate() override {
        isActive = true;
        std::cout << "Speed Boost Activated!" << std::endl;
    }
    void drawSpeedBoost();
    void move(char dir) override {}
};
#endif // POWERUP_H