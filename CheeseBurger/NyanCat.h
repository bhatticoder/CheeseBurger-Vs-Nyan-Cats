#ifndef NYANCAT_H
#define NYANCAT_H
#include "GameObject.h"
#include "Cheeseburger.h"
#include <iostream>
class Nyancat : public GameObject {
private:
    struct Cat {
        int row;
        int col;
    };
    static const int maxCats = 3;
    Cat cats[maxCats];          
    int falling_speed;           
    int player_col;              
    bool isvisible;              
    int level;
    int playerLives;
public:
    Nyancat(int startRow, int startCol, int speed, int level);
    void initializeCats();
    void move(char direction) override;
    void collide(GameObject* collideobject);
    void draw() override;
    void fall();
    int getRow() const;    
    int getPlayerCol() const;
    int getLives()const;
    static const int cols = 60; 
    static const int rows = 40;  
};
#endif