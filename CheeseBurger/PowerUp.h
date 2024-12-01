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
    Powerup(int x, int y, int rows, int cols, Cheeseburger* burger, int speed = 1);
    void draw()override;
};
#endif